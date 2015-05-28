/*
 * main.c
 *
 *  Created on: 27 mars 2015
 *      Author: mi03
 */

#include "gpio.h"
#include "timer.h"
#include "interrupt.h"

#define GPIO_LED 		GPIO_D
#define PIN_LED 		31
#define TIMER 			TIMER1
#define HZ				5
#define INTERRUPT_TIMER	INTERRUPT_TIMER1
volatile int led_value = 1;

void __attribute__((interrupt("IRQ"))) irq_handler(void) {
	timerComparedOccured(TIMER); // clear compare status
	led_value = !led_value;
	gpioSetValue(GPIO_LED, PIN_LED, led_value);
}

void main(void) {
	gpioInit(GPIO_LED, PIN_LED);
	gpioSetValue(GPIO_LED, PIN_LED, led_value);
	timerInit(TIMER, 2*HZ);
	timerEnableInterrupt(TIMER);
	interruptEnableIRQ();
	interruptEnableSource(INTERRUPT_TIMER);
	while (1);
	return;
}
