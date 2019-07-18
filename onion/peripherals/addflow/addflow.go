package main

import (
	"log"
	"sync/atomic"
	"time"

	"github.com/pkg/errors"
	"github.com/sjhitchner/gpio"
)

type AddFlowInteractor struct {
	DosePump   Pump
	FlowSensor FlowSensor
	pumpDelay  time.Duration
}

func NewAddFlowInteractor(pump Pump, sensor FlowSensor, delay time.Duration) AddFlowInteractor {
	return &AddFlowInteractor{
		DosePump:   pump,
		FlowSensor: sensor,
		pumpDelay:  delay,
	}
}

func (t *AddFlowInteractor) Start() error {

	flow, err := t.FlowSensor.PerSecondFlow()
	if err != nil {
		return err
	}

	// Create a timer and immediately stop it.
	timer := time.NewTimer(t.pumpDelay)
	timer.Stop()

	sum := 0
	for {
		select {
		case count := <-addFlowChan:
			sum += count
			timer.Reset(t.pumpDelay)

		case <-timer.C:
			log.Println("AddflowFlow Rate", addFlow)

			sum = 0
		}
	}
}
