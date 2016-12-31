/*
 * gpio.h
 *
 *  Created on: 3 avr. 2015
 *      Author: mi03
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "registers.h"

inline void gpioInit(gpio_t* port, int pin) {
	port->GIUS |= (1UL << pin);
	port->DDIR |= (1UL<<pin);
	if (pin < 16) {
		port->OCR1 |= (1UL << (2*pin)) | (1UL << (2*pin+1));
	} else {
		pin -= 16;
		port->OCR2 |= (1UL << (2*pin)) | (1UL << (2*pin+1));
	}
}

inline void gpioSetValue(gpio_t* port, int pin, int value) {
	if (value == 0) {
		port->DR &= ~(1UL<<pin);
	} else {
		port->DR |= (1UL<<pin);
	}
}


#endif /* GPIO_H_ */
