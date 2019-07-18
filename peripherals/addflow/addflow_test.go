package addflow

import (
	"testing"
	"time"

	. "gopkg.in/check.v1"

	"github.com/sjhitchner/pondcontroller/peripherals/flowsensor"
	"github.com/sjhitchner/pondcontroller/peripherals/pump"
)

func Test(t *testing.T) {
	TestingT(t)
}

var _ = Suite(&AddFlowSuite{})

type AddFlowSuite struct{}

func (s *AddFlowSuite) SetUpSuite(c *C) {
}

func (s *AddFlowSuite) Test_AddFlowMonitor(c *C) {
	pump := &pump.MockPump{}
	sensor := flowsensor.NewMockFlowSensor()

	addFlow := NewAddFlowMonitor(pump, sensor, 2*time.Second)

	go func() {
		for i := 0; i < 10; i++ {
			sensor.C <- 10
		}

		<-time.After(5 * time.Second)

		for i := 0; i < 5; i++ {
			sensor.C <- 10
		}

		<-time.After(5 * time.Second)

		for i := 0; i < 100; i++ {
			sensor.C <- 10
		}

		<-time.After(5 * time.Second)

	}()

	go addFlow.Start()
	<-time.After(20 * time.Second)
	addFlow.Close()
}
