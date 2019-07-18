package pumpflow

import (
	log "github.com/sirupsen/logrus"

	"github.com/sjhitchner/pondcontroller/peripherals/flowsensor"
)

const (
	DefaultFlowSensorCalibration = 0.125
	HistorySize                  = 600
)

type PumpFlowMonitor struct {
	FlowSensor            flowsensor.FlowSensor
	end                   chan bool
	flowSensorCalibration float32 // sensor ticks to volume calibration

	history         []float32
	historyPosition int
	historySum      float32
}

func NewPumpFlowMonitor(sensor flowsensor.FlowSensor) *PumpFlowMonitor {
	return &PumpFlowMonitor{
		FlowSensor:            sensor,
		end:                   make(chan bool),
		flowSensorCalibration: DefaultFlowSensorCalibration,
		history:               make([]float32, HistorySize),
		historyPosition:       0,
		historySum:            0,
	}
}

func (t *PumpFlowMonitor) Start() error {
	log.Info("Starting Pump Flow Monitor")

	flow, err := t.FlowSensor.PerSecondFlow()
	if err != nil {
		return err
	}

	go func() {
		for {
			select {
			case count := <-flow:
				volume := t.flowSensorCalibration * float32(count)
				t.addToHistory(volume)

			case <-t.end:
				return
			}
		}
	}()

	return nil
}

func (t *PumpFlowMonitor) Close() error {
	t.end <- true
	return nil
}

func (t *PumpFlowMonitor) addToHistory(value float32) {
	//advance position
	t.historyPosition++
	if t.historyPosition >= HistorySize {
		t.historyPosition = 0
	}

	// Remove previous value
	t.historySum -= t.history[t.historyPosition]

	// add new value
	t.history[t.historyPosition] = value
	t.historySum += value
}

func (t *PumpFlowMonitor) FlowAverage() float32 {
	return t.historySum / HistorySize
}

func (t *PumpFlowMonitor) FlowHistory() []float32 {
	return t.history
}
