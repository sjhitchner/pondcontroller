package main

import (
	"sync/atomic"
	"time"

	"github.com/pkg/errors"
	"github.com/sjhitchner/gpio"
)

// Defines New flow sensor
// Access flow per second flow rate by listen to channel
type FlowSensor interface {
	PerSecondFlow() (<-chan float32, error)
	Close() error
}

type flowSensorImpl struct {
	pinNum  int
	pin     gpio.Pin
	counter uint32
	end     chan bool
}

func NewFlowSensor(pin int) (FlowSensor, error) {

	sensorPin, err := gpio.OpenPin(AddFlowSensorPin, gpio.ModeInput)
	if err != nil {
		return nil, errors.Wrapf(err, "error initializing flow sensor on %d", pin)
	}

	return &flowSensorImpl{
		pinNum:  pin,
		pin:     sensorPin,
		counter: 0,
		end:     make(chan bool),
	}, nil
}

func (t *flowSensorImpl) PerSecondFlow() (<-chan float32, error) {
	ch := make(chan float32, 10)

	if err := t.pin.BeginWatch(gpio.EdgeRising, func() {
		atomic.AddUint32(&t.counter, 1)
	}); err != nil {
		return nil, errors.Wrapf(err, "error initializing flow sensor interrupt on %d", t.pinNum)
	}

	ticker := time.NewTicker(time.Second)

	go func() {
		defer ticker.Stop()
		defer close(ch)

		for {
			select {
			case <-ticker.C:
				ch <- float32(atomic.SwapUint32(&t.counter, 0))
			case <-t.end:
				return
			}
		}
	}()

	return ch, nil
}

func (t *flowSensorImpl) Close() error {
	t.end <- true
	t.pin.EndWatch()
	return t.pin.Close()
}
