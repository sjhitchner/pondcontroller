package addflow

import (
	"time"

	//"github.com/pkg/errors"
	log "github.com/sirupsen/logrus"
	"github.com/sjhitchner/pondcontroller/peripherals/flowsensor"
	"github.com/sjhitchner/pondcontroller/peripherals/pump"
)

const (
	DefaultDosePumpDelay         = 5 * time.Second
	DefaultFlowSensorCalibration = 0.125
	DefaultDoseConversion        = 0.120 / 1817
	DefaultDosePumpCalibration   = 1000
)

type AddFlowMonitor struct {
	DosePump              pump.Pump
	FlowSensor            flowsensor.FlowSensor
	end                   chan bool
	pumpDelay             time.Duration
	flowSensorCalibration float32 // sensor ticks to volume calibration
	doseConversion        float32 // volume added to dose ratio
	dosePumpCalibration   float32 // liters per second of dose pump
}

func NewAddFlowMonitor(pump pump.Pump, sensor flowsensor.FlowSensor) *AddFlowMonitor {
	return &AddFlowMonitor{
		DosePump:              pump,
		FlowSensor:            sensor,
		end:                   make(chan bool),
		pumpDelay:             DefaultDosePumpDelay,
		flowSensorCalibration: DefaultFlowSensorCalibration,
		doseConversion:        DefaultDoseConversion,
		dosePumpCalibration:   DefaultDosePumpCalibration,
	}
}

func (t *AddFlowMonitor) Start() error {
	log.Info("Starting Addflow Monitor")

	flow, err := t.FlowSensor.PerSecondFlow()
	if err != nil {
		return err
	}

	go func() {
		// Create a timer and immediately stop it.
		timer := time.NewTimer(t.pumpDelay)
		timer.Stop()

		sum := 0
		for {
			select {
			case count := <-flow:
				sum += count
				timer.Reset(t.pumpDelay)

			case <-timer.C:

				// TODO convert sensor ticks to volume
				// Determine the volume of water based on the ticks
				// F(min) = 7.5 * Q (L/min)
				// F(sec) = 7.5 * Q (L/min)(min/60s) = 0.125 * Q (L/s)
				addedVolume := t.flowSensorCalibration * float32(sum)

				// Determine dose to add
				doseVolume := addedVolume * t.doseConversion

				// Determine dose duration give dose volume
				// D(s) = V(L) * Q(s/L)
				duration := time.Duration(doseVolume*t.dosePumpCalibration) * time.Second

				log.Infof("Added %fL of water (%d ticks), %fmL of stress coat (%s)", addedVolume, sum, doseVolume*1000, duration)

				t.DosePump.OnFor(duration)

				sum = 0

			case <-t.end:
				return
			}
		}
	}()

	return nil
}

func (t *AddFlowMonitor) Close() error {
	t.end <- true
	return nil
}
