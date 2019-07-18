package temponewire

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"strconv"
	"strings"
	"time"

	log "github.com/sirupsen/logrus"
)

// Setup and communicate with a Dallas one-wire temperature sensor
// Only one device on the one-wire bus is currently supported
type OneWireTemp interface {
	Start(time.Duration) <-chan float32
	Close() error
}

type oneWireTempImpl struct {
	pinNum int
	ID     string
	end    chan bool
}

// insmod w1-gpio-custom bus0=0,19,0
// cat /sys/devices/w1_bus_master1/w1_master_slave_count
// cat /sys/devices/w1_bus_master1/10-00080047e5a0/w1_slave
func NewOneWireTemp(pin int) (OneWireTemp, error) {
	return initialize(pin)
}

func (t *oneWireTempImpl) Start(duration time.Duration) <-chan float32 {
	ch := make(chan float32, 10)

	go func() {
		defer close(ch)

		for {
			select {
			case <-time.After(duration):
				temp, err := readTemperature(t.ID)
				if err != nil {
					log.Errorf("Error reading temp on %d", t.pinNum)
				}
				ch <- temp

			case <-t.end:
				return
			}
		}
	}()

	return ch
}

func (t *oneWireTempImpl) Close() error {
	t.end <- true
	return nil
}

func initialize(pin int) (*oneWireTempImpl, error) {

	if err := insmod(pin); err != nil {
		return nil, err
	}

	count, err := slaveCount()
	if err != nil {
		return nil, err
	}

	if count != 1 {
		return nil, fmt.Errorf("slave not initialized correctly")
	}

	id, err := slaveID()
	if err != nil {
		return nil, err
	}

	return &oneWireTempImpl{
		pinNum: pin,
		ID:     id,
		end:    make(chan bool),
	}, nil
}

// insmod w1-gpio-custom bus0=0,19,0
func insmod(pin int) error {
	log.Infof("Initializing one wire temp on %d", pin)

	cmd := exec.Command(
		"insmod",
		"w1-gpio-custom",
		fmt.Sprintf("bus0=0,%d,0", pin),
	)

	var out bytes.Buffer
	cmd.Stdout = &out
	return cmd.Run()
}

// cat /sys/devices/w1_bus_master1/w1_master_slave_count
func slaveCount() (int, error) {
	data, err := readOneWireData("/sys/devices/w1_bus_master1/w1_master_slave_count")
	if err != nil {
		return 0, err
	}

	count, err := strconv.Atoi(data)
	if err != nil {
		return 0, err
	}

	return count, nil
}

// cat /sys/devices/w1_bus_master1/w1_master_slaves
func slaveID() (string, error) {
	data, err := readOneWireData("/sys/devices/w1_bus_master1/w1_master_slaves")
	if err != nil {
		return "", err
	}

	return strings.TrimSpace(data), nil
}

// cat /sys/devices/w1_bus_master1/10-00080047e5a0/w1_slave
// 32 00 4b 46 ff ff 0f 10 3e : crc=3e YES
// 32 00 4b 46 ff ff 0f 10 3e t=24812
func readTemperature(id string) (float32, error) {
	cmd := fmt.Sprintf("/sys/devices/w1_bus_master1/%s/w1_slave")
	data, err := readOneWireData(cmd)
	if err != nil {
		return 0, err
	}

	fields := strings.Fields(data)

	if len(fields) != 22 {
		return 0, fmt.Errorf("invalid response '%s'", data)
	}

	temp, err := strconv.Atoi(fields[21][2:])
	if err != nil {
		return 0, err
	}

	return float32(temp) / 1000, nil
}

func readOneWireData(cmd string) (string, error) {
	f, err := os.Open(cmd)
	if err != nil {
		return "", err
	}
	defer f.Close()

	b, err := ioutil.ReadAll(f)
	if err != nil {
		return "", err
	}

	return string(b), err
}
