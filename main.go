package main

import (
	"fmt"
	"io"
	"os"
	"os/signal"

	log "github.com/sirupsen/logrus"

	"github.com/sjhitchner/pondcontroller/peripherals/addflow"
	"github.com/sjhitchner/pondcontroller/peripherals/flowsensor"
	"github.com/sjhitchner/pondcontroller/peripherals/pump"
)

/*
At Booting
GPIO1		GPIO / I2S SDO		Must be floating or pulled down
GPIO6		SPI CS1/ GPIO		Must be floating
GPIO7		SPI CLK				Must be floating
GPIO8		SPI MOSI				Must be floating
GPIO12	UART TX0				Must be floating or pulled down
GPIO45	UART TX1 / GPIO	Must be floating
GPIO36	GPIO / PERST_N (Omega2S Only)	Must be floating

Working Ports

Output GPI02
General Purpose Pins
GPIO2  - ADD_FLOW
GPIO3  - PUMP_FLOW
GPIO11 - PUMP_ON
GPIO15
GPIO16
GPIO17
GPIO18 - PWM
GPIO19 - 1W


RGB LED (active low)
GPIO 17 controls the red LED.
GPIO 16 controls the green LED.
GPIO 15 controls the blue LED.


Periphals
- Add flow sensor		I
- pump flow sensor	I
- flow sensor			I
- dose pump control	O
- dose pump prime
- one wire temp         2
*/

const (
	DosePumpPin       = 0
	TempOneWirePin    = 19
	AddFlowSensorPin  = 2
	PumpFlowSensorPin = 3
	DosePumpPrime     = 11

	LedRedPin   = 17
	LedGreenPin = 16
	LedBluePin  = 15
)

// TODO configuration
func main() {
}

func Setup() error {

	addFlowSensor, err := NewFlowSensor(AddFlowSensorPin)
	if err != nil {
		return err
	}

	dosePump, err := pump.NewPump(DosePumpPin)
	if err != nil {
		return err
	}

	addFlowMonitor, err := addflow.NewAddFlowMonitor(dosePump, addFlowSensor)
	if err != nil {
		return err
	}
	if err := addFlowMonitor.Start(); err != nil {
		return err
	}

	Shutdown(addFlowMonitor, addFlowSensor, dosePump)
}

func Shutdown(closers ...io.Close) {
	ch := make(chan os.Signal, 1)
	signal.Notify(c, os.Interrupt)

	go func() {
		for _ = range ch {
			fmt.Printf("\nClearing and unexporting the pin.\n")

			for c := range closers {
				err := c.Close()
				if err != nil {
					log.Error(err)
				}
			}

			os.Exit(0)
		}
	}()
}

/*
	rgbLed, err := NewActiveLowRGBLed(LedRedPin, LedGreenPin, LedBluePin)
	if err != nil {
		panic(err)
  }

	addFlowSensor, err := gpio.OpenPin(AddFlowSensorPin, gpio.ModeInput)
	if err != nil {
		panic(err)
	}

	var addFlowCounter uint32
	//var pumpFlowCounter Uint32

	if err := addFlowSensor.BeginWatch(gpio.EdgeRising, func() {
		atomic.AddUint32(&addFlowCounter, 1)
	}); err != nil {
		panic(err)
	}
	for {
		select {
		case <-time.After(1 * time.Second):
			addFlowCount := atomic.SwapUint32(&addFlowCounter, 0)

			flowRate := 7.5 * float32(addFlowCount)
			fmt.Println("Flow Rate", flowRate)
		}
	}
}

/*
	for {
		r := rand.Intn(8)

		if r&0x1 > 0 {
			redLed.Clear()
			fmt.Printf("RED")
		} else {
			redLed.Set()
			fmt.Printf("red")
		}
		fmt.Printf("  ")

		if r&0x2 > 0 {
			greenLed.Clear()
			fmt.Printf("GREEN")
		} else {
			greenLed.Set()
			fmt.Printf("green")
		}
		fmt.Printf("  ")

		if r&0x4 > 0 {
			blueLed.Clear()
			fmt.Printf("BLUE")
		} else {
			blueLed.Set()
			fmt.Printf("blue")
		}
		fmt.Println()

		<-time.After(2 * time.Second)
	}
}

/*
const (
	LED_RED_PIN   = "GPIO2" // Connect a LED to GPIO11 on the Omega2
	LED_GREEN_PIN = "GPIO3" // Connect a LED to GPIO11 on the Omega2

	DOSE_PUMP_CTRL_PIN = "GPIO18"
)

var (
	Version string
)

func main() {
	_, err := host.Init() // Init periph.io
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("Pond Controller v1 verion=%s\n", Version)

	dosePump := gpioreg.ByName(DOSE_PUMP_CTRL_PIN) // Get GPIO
	defer dosePump.Halt()                          // Close when the program ends

	var dutyCycle gpio.Duty

	for {
		fmt.Printf("PWM %s\n", dutyCycle)
		dosePump.PWM(dutyCycle, 10*10*physic.KiloHertz)

		if dutyCycle == gpio.DutyMax {
			dutyCycle = gpio.DutyHalf
		} else {
			dutyCycle = gpio.DutyMax
		}

		<-time.After(2 * time.Second)
	}
			for _, n := range gpioreg.Aliases() {
				fmt.Printf("Alias %s %d\n", n.Name(), n.Number())
			}

			for i, p := range gpioreg.All() {
				fmt.Printf("Name %s %d", p.Name(), p.Number())

				p.Out(gpio.High)
				fmt.Printf(" ON")
				<-time.After(500 * time.Millisecond)

				p.Out(gpio.Low)
				fmt.Printf(" OFF")
				<-time.After(500 * time.Millisecond)

				p.Out(gpio.High)
				fmt.Printf(" ON")
				<-time.After(500 * time.Millisecond)

				p.Out(gpio.Low)
				fmt.Printf(" OFF")
				<-time.After(500 * time.Millisecond)

				fmt.Println()
				p.Halt()

				if i > 32 {
					break
				}
			}

		red := gpioreg.ByName(LED_RED_PIN) // Get GPIO
		defer red.Halt()                   // Close when the program ends

		green := gpioreg.ByName(LED_GREEN_PIN) // Get GPIO
		defer green.Halt()                     // Close when the program ends

		ledState := false
		for {
			// Keeps blinking each 500ms
			if ledState {
				red.Out(gpio.High)
				green.Out(gpio.Low)
			} else {
				red.Out(gpio.Low)
				green.Out(gpio.High)
			}
			ledState = !ledState
			time.Sleep(500 * time.Millisecond)
		}
}
*/

/*
TODO

Clock tick

3 flow sensors, interrupt on the pins
With calibration values

Dose pump
PWM
Prime pump

Onewire?

Mini server
Display calibration values etc




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

 /****************************************************************
 * Constants
 ****************************************************************

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) /* 3 seconds *
#define MAX_BUF 64

/****************************************************************
 * gpio_export
 ****************************************************************
int gpio_export(unsigned int gpio)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);

	return 0;
}

/****************************************************************
 * gpio_unexport
 ****************************************************************
int gpio_unexport(unsigned int gpio)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);
	return 0;
}

/****************************************************************
 * gpio_set_dir
 ****************************************************************
int gpio_set_dir(unsigned int gpio, unsigned int out_flag)
{
	int fd, len;
	char buf[MAX_BUF];

	len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR  "/gpio%d/direction", gpio);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/direction");
		return fd;
	}

	if (out_flag)
		write(fd, "out", 4);
	else
		write(fd, "in", 3);

	close(fd);
	return 0;
}

/****************************************************************
 * gpio_set_value
 ****************************************************************
int gpio_set_value(unsigned int gpio, unsigned int value)
{
	int fd, len;
	char buf[MAX_BUF];

	len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/set-value");
		return fd;
	}

	if (value)
		write(fd, "1", 2);
	else
		write(fd, "0", 2);

	close(fd);
	return 0;
}

/****************************************************************
 * gpio_get_value
 ****************************************************************
int gpio_get_value(unsigned int gpio, unsigned int *value)
{
	int fd, len;
	char buf[MAX_BUF];
	char ch;

	len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

	fd = open(buf, O_RDONLY);
	if (fd < 0) {
		perror("gpio/get-value");
		return fd;
	}

	read(fd, &ch, 1);

	if (ch != '0') {
		*value = 1;
	} else {
		*value = 0;
	}

	close(fd);
	return 0;
}


/****************************************************************
 * gpio_set_edge
 ****************************************************************

int gpio_set_edge(unsigned int gpio, char *edge)
{
	int fd, len;
	char buf[MAX_BUF];

	len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/edge", gpio);

	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/set-edge");
		return fd;
	}

	write(fd, edge, strlen(edge) + 1);
	close(fd);
	return 0;
}

/****************************************************************
 * gpio_fd_open
 ****************************************************************

int gpio_fd_open(unsigned int gpio)
{
	int fd, len;
	char buf[MAX_BUF];

	len = snprintf(buf, sizeof(buf), SYSFS_GPIO_DIR "/gpio%d/value", gpio);

	fd = open(buf, O_RDONLY | O_NONBLOCK );
	if (fd < 0) {
		perror("gpio/fd_open");
	}
	return fd;
}

/****************************************************************
 * gpio_fd_close
 ****************************************************************

int gpio_fd_close(int fd)
{
	return close(fd);
}

/****************************************************************
 * Main
 ****************************************************************
int main(int argc, char **argv, char **envp)
{
	struct pollfd fdset[2];
	int nfds = 2;
	int gpio_fd, timeout, rc;
	char *buf[MAX_BUF];
	unsigned int gpio;
	int len;
	int val;



	if (argc < 2) {
		printf("Usage: gpioIrq <gpio-pin>\n\n");
		printf("Waits for a change in the GPIO pin voltage level or input on stdin\n");
		exit(-1);
	}

	gpio = atoi(argv[1]);

	gpio_export(gpio);
	gpio_set_dir(gpio, 0);
	gpio_set_edge(gpio, "both");
	gpio_fd = gpio_fd_open(gpio);

	timeout = POLL_TIMEOUT;

	while (1) {
		memset((void*)fdset, 0, sizeof(fdset));

		fdset[0].fd = STDIN_FILENO;
		fdset[0].events = POLLIN;

		fdset[1].fd = gpio_fd;
		fdset[1].events = POLLPRI;

		rc = poll(fdset, nfds, timeout);

		if (rc < 0) {
			printf("\npoll() failed!\n");
			return -1;
		}

		if (rc == 0) {
			printf(".");
		}

		if (fdset[1].revents & POLLPRI) {
			lseek(fdset[1].fd, 0, SEEK_SET);
			len = read(fdset[1].fd, buf, MAX_BUF);
			printf("\npoll() GPIO %d interrupt occurred\n", gpio);
			printf("\tread value: '%c'\n", buf[0]);
		}

		if (fdset[0].revents & POLLIN) {
			(void)read(fdset[0].fd, buf, 1);
			printf("\npoll() stdin read 0x%2.2X\n", (unsigned int) buf[0]);
		}

		fflush(stdout);
	}

	gpio_fd_close(gpio_fd);
	return 0;
}

*/
