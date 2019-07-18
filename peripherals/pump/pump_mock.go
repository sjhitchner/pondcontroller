package pump

import (
	"time"
)

type MockPump struct {
	on bool
}

// Defines active high pump
func (t *MockPump) On() {
	t.on = true
}

func (t *MockPump) IsOn() bool {
	return t.on
}

func (t *MockPump) OnFor(duration time.Duration) {
	go func() {
		<-time.After(duration)
		t.on = false
	}()
	t.on = true
}

func (t *MockPump) Off() {
	t.on = false
}

func (t *MockPump) Close() error {
	return nil
}
