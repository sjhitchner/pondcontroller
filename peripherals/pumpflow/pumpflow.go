package pumpflow

import (
	log "github.com/sirupsen/logrus"

	"github.com/sjhitchner/pondcontroller/peripherals/flowsensor"
)

const (
	DefaultFlowSensorCalibration = 0.125
)

type PumpFlowMonitor struct {
	FlowSensor              flowsensor.FlowSensor
	end                     chan bool
	flowSensorTicksPerLiter float32 // sensor ticks to volume calibration
}

func NewPumpFlowMonitor(sensor flowsensor.FlowSensor) *PumpFlowMonitor {
	return &PumpFlowMonitor{
		FlowSensor:              sensor,
		end:                     make(chan bool),
		flowSensorTicksPerLiter: flowsensor.DefaultTicksPerLiter,
	}
}

func (t *PumpFlowMonitor) Start() {
	log.Info("Starting Pump Flow Monitor")

	flow := t.FlowSensor.PerSecondFlow()

	go func() {
		for {
			select {
			case count := <-flow:
				volume := float32(count) / t.flowSensorTicksPerLiter

				log.WithFields(log.Fields{
					"ticks":                count,
					"metric":               "pump_flow_volume",
					"volume":               volume,
					"calibration_flow_tpl": t.flowSensorTicksPerLiter,
				}).Infof("Pump flow %fL of water (%d ticks)", volume, count)

			case <-t.end:
				return
			}
		}
	}()
}

func (t *PumpFlowMonitor) Close() error {
	t.end <- true
	return nil
}
