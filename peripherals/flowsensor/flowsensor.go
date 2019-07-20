package flowsensor

import (
	"sync/atomic"
	"time"

	"github.com/pkg/errors"
	"github.com/sjhitchner/gpio"
)

const (
	// Twelve trials 371
	// 393
	// 331
	// 319
	// 342
	// 432
	// 373
	// 335
	// 325
	// 419
	// 402
	// 351
	// 419 = 4441 / 12 = 370.083
	DefaultTicksPerLiter = 370
)

// Defines New flow sensor
// Access flow per second flow rate by listen to channel
type FlowSensor interface {
	PerSecondFlow() <-chan int
	Close() error
}

type flowSensorImpl struct {
	pinNum  int
	pin     gpio.Pin
	counter uint32
	end     chan bool
}

func NewFlowSensor(pin int) (FlowSensor, error) {

	sensorPin, err := gpio.OpenPin(pin, gpio.ModeInput)
	if err != nil {
		return nil, errors.Wrapf(err, "error initializing flow sensor on %d", pin)
	}

	sensor := &flowSensorImpl{
		pinNum:  pin,
		pin:     sensorPin,
		counter: 0,
		end:     make(chan bool),
	}

	if err := sensorPin.BeginWatch(gpio.EdgeRising, func() {
		atomic.AddUint32(&sensor.counter, 1)
	}); err != nil {
		return nil, errors.Wrapf(err, "error initializing flow sensor interrupt on %d", pin)
	}

	return sensor, nil
}

func (t *flowSensorImpl) PerSecondFlow() <-chan int {
	ch := make(chan int, 10)

	ticker := time.NewTicker(time.Second)

	go func() {
		defer ticker.Stop()
		defer close(ch)

		for {
			select {
			case <-ticker.C:
				value := int(atomic.SwapUint32(&t.counter, 0))
				ch <- value
			case <-t.end:
				return
			}
		}
	}()

	return ch
}

func (t *flowSensorImpl) Close() error {
	t.pin.EndWatch()
	t.end <- true
	return t.pin.Close()
}
