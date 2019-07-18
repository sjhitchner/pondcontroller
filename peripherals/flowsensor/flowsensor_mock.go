package flowsensor

type MockFlowSensor struct {
	C chan int
}

func NewMockFlowSensor() *MockFlowSensor {
	return &MockFlowSensor{
		make(chan int),
	}
}

func (t *MockFlowSensor) PerSecondFlow() (<-chan int, error) {
	return t.C, nil
}

func (t *MockFlowSensor) Close() error {
	return nil
}
