package pump

import (
	"log"
	"time"

	"github.com/pkg/errors"
	"github.com/sjhitchner/gpio"
)

// Defines active high pump
type Pump interface {
	On()
	IsOn() bool
	OnFor(time.Duration)
	Off()
	Close() error
}

type pumpImpl struct {
	pinNum int
	pin    gpio.Pin
}

func NewPump(pin int) (Pump, error) {
	pumpPin, err := gpio.OpenPin(pin, gpio.ModeOutput)
	if err != nil {
		// TODO wrap
		return nil, err
	}

	return &pumpImpl{
		pinNum: pin,
		pin:    pumpPin,
	}, nil
}

func (t *pumpImpl) IsOn() bool {
	return t.pin.Get()
}

func (t *pumpImpl) On() {
	log.Println("pump on")
	t.pin.Set()
}

func (t *pumpImpl) Off() {
	log.Println("pump off")
	t.pin.Clear()
}

func (t *pumpImpl) OnFor(duration time.Duration) {
	go func() {
		<-time.After(duration)
		t.Off()
	}()
	t.On()
}

func (t *pumpImpl) Close() error {
	t.Off()
	return errors.Wrapf(t.pin.Close(), "Error closing pump on %d", t.pinNum)
}
