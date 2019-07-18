package main

import (
	"time"

	"github.com/pkg/errors"
	"github.com/sjhitchner/gpio"
)

type RGBLed interface {
	RedOn()
	RedOnFor(time.Duration)
	RedOff()
	GreenOn()
	GreenOnFor(time.Duration)
	GreenOff()
	BlueOn()
	BlueOnFor(time.Duration)
	BlueOff()

	On(r, g, b bool)
	OnFor(r, g, b bool, d time.Duration)
	Off()

	Close() error
}

type activeLowRGBLedImpl struct {
	red, green, blue          gpio.Pin
	redNum, greenNum, blueNum int
}

// Abstract away LED first
func NewActiveLowRGBLed(redPin, greenPin, bluePin int) (RGBLed, error) {

	red, err := gpio.OpenPin(redPin, gpio.ModeOutput)
	if err != nil {
		return nil, err
	}

	green, err := gpio.OpenPin(greenPin, gpio.ModeOutput)
	if err != nil {
		return nil, err
	}

	blue, err := gpio.OpenPin(bluePin, gpio.ModeOutput)
	if err != nil {
		return nil, err
	}

	return &activeLowRGBLedImpl{
		redNum:   redPin,
		greenNum: greenPin,
		blueNum:  bluePin,
		red:      red,
		green:    green,
		blue:     blue,
	}, nil
}

func (t *activeLowRGBLedImpl) RedOn() {
	t.red.Clear()
}

func (t *activeLowRGBLedImpl) RedOnFor(duration time.Duration) {
	go func() {
		<-time.After(duration)
		t.RedOff()
	}()
	t.RedOn()
}

func (t *activeLowRGBLedImpl) RedOff() {
	t.red.Set()
}

func (t *activeLowRGBLedImpl) GreenOn() {
	t.green.Clear()
}

func (t *activeLowRGBLedImpl) GreenOnFor(duration time.Duration) {
	go func() {
		<-time.After(duration)
		t.GreenOff()
	}()
	t.GreenOn()
}

func (t *activeLowRGBLedImpl) GreenOff() {
	t.green.Set()
}

func (t *activeLowRGBLedImpl) BlueOn() {
	t.blue.Clear()
}

func (t *activeLowRGBLedImpl) BlueOnFor(duration time.Duration) {
	go func() {
		<-time.After(duration)
		t.BlueOff()
	}()
	t.BlueOn()
}

func (t *activeLowRGBLedImpl) BlueOff() {
	t.blue.Set()
}

func (t *activeLowRGBLedImpl) On(r, g, b bool) {
	t.RedOn()
	t.GreenOn()
	t.BlueOn()
}

func (t *activeLowRGBLedImpl) OnFor(r, g, b bool, duration time.Duration) {
	go func() {
		<-time.After(duration)
		t.Off()
	}()
	t.On(r, g, b)
}

func (t *activeLowRGBLedImpl) Off() {
	t.RedOff()
	t.GreenOff()
	t.BlueOff()
}

func (t *activeLowRGBLedImpl) Close() error {
	t.Off()

	rerr := errors.Wrapf(t.red.Close(), "Error closing red led on %d", t.redNum)
	gerr := errors.Wrapf(t.green.Close(), "Error closing green led on %d", t.greenNum)
	berr := errors.Wrapf(t.blue.Close(), "Error closing blue led on %d", t.blueNum)
	if rerr != nil {
		return rerr
	}
	if gerr != nil {
		return gerr
	}
	if berr != nil {
		return berr
	}

	return nil
}
