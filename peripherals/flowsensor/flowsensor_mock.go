package flowsensor

type MockFlowSensor struct {
	C chan int
}

func NewMockFlowSensor() *MockFlowSensor {
	return &MockFlowSensor{
		make(chan int),
	}
}

func (t *MockFlowSensor) PerSecondFlow() <-chan int {
	return t.C
}

func (t *MockFlowSensor) Close() error {
	return nil
}
