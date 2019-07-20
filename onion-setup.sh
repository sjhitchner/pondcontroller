#!/bin/sh -e

omega2-ctrl gpiomux set i2c gpio  # i2c pins for general io
omega2-ctrl gpiomux set pwm0 pwm  # enable pwm on 18
omega2-ctrl gpiomux set pwm1 pwm  # enable pwm on 19
insmod w1-gpio-custom bus0=0,5,0  # enable one wire on 5
