package addflow

import (
	"time"

	//"github.com/pkg/errors"
	log "github.com/sirupsen/logrus"
	"github.com/sjhitchner/pondcontroller/peripherals/flowsensor"
	"github.com/sjhitchner/pondcontroller/peripherals/pump"
	//"github.com/sjhitchner/pondcontroller/utils/metrics"
)

const (
	DefaultDosePumpDelay         = 5 * time.Second
	DefaultFlowSensorCalibration = 0.125
	DefaultDoseConversion        = 0.120 / 1817
	DefaultDosePumpCalibration   = 1000
)

type AddFlowMonitor struct {
	DosePump                pump.Pump
	FlowSensor              flowsensor.FlowSensor
	end                     chan bool
	pumpDelay               time.Duration
	flowSensorTicksPerLiter float32 // sensor ticks to volume calibration
	doseConversion          float32 // volume added to dose ratio
	dosePumpLitersPerSecond float32 // liters per second of dose pump
}

func NewAddFlowMonitor(pump pump.Pump, sensor flowsensor.FlowSensor) *AddFlowMonitor {
	return &AddFlowMonitor{
		DosePump:                pump,
		FlowSensor:              sensor,
		end:                     make(chan bool),
		pumpDelay:               DefaultDosePumpDelay,
		flowSensorTicksPerLiter: flowsensor.DefaultTicksPerLiter,
		doseConversion:          DefaultDoseConversion,
		dosePumpLitersPerSecond: DefaultDosePumpCalibration,
	}
}

func (t *AddFlowMonitor) Start() {
	log.Info("Starting Addflow Monitor")

	flow := t.FlowSensor.PerSecondFlow()

	go func() {
		// Create a timer and immediately stop it.
		timer := time.NewTimer(t.pumpDelay)
		timer.Stop()

		sum := 0
		for {
			select {
			case count := <-flow:
				if count > 0 {
					sum += count
					timer.Reset(t.pumpDelay)

					log.Debugf("Added %d ticks -> %d", count, sum)
				}

			case <-timer.C:

				// TODO convert sensor ticks to volume
				// Experimentally determined to be 370 ticks/L
				// Determine the volume of water based on the ticks
				// F(min) = 7.5 * Q (L/min)
				// F(sec) = 7.5 * Q (L/min)(min/60s) = 0.125 * Q (L/s)
				addedVolume := float32(sum) / t.flowSensorTicksPerLiter

				// Determine dose to add
				doseVolume := addedVolume * t.doseConversion

				// Determine dose duration give dose volume
				// D(s) = V(L) * Q(s/L)
				doseDuration := time.Duration(doseVolume*t.dosePumpLitersPerSecond) * time.Second

				log.WithFields(log.Fields{
					"ticks":                       sum,
					"metric":                      "add_flow_volume",
					"volume":                      addedVolume,
					"dose_volume":                 doseVolume,
					"dose_duration":               doseDuration,
					"calibration_flow_tpl":        t.flowSensorTicksPerLiter,
					"calibration_dose_conversion": t.doseConversion,
					"calibration_pump_lps":        t.dosePumpLitersPerSecond,
				}).Infof("Added %fL of water (%d ticks), %fmL of stress coat (%s)", addedVolume, sum, doseVolume*1000, doseDuration)

				t.DosePump.OnFor(doseDuration)

				sum = 0

			case <-t.end:
				return
			}
		}
	}()
}

func (t *AddFlowMonitor) Close() error {
	t.end <- true
	return nil
}
