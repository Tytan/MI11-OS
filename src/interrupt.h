/*
 * interrupt.h
 *
 *  Created on: 10 avr. 2015
 *      Author: mi03
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "registers.h"

#define INTERRUPT_TIMER1 	59
#define INTERRUPT_TIMER2 	58

inline void interruptEnableIRQ(){
	asm volatile(
		"mrs r0,cpsr\t\n"
		"bic r0,r0,#0x80\t\n"
		"msr cpsr_c,r0\t\n"
		:
		:
		: "r0");
}

inline void interruptDisableIRQ(){
	asm volatile(
		"mrs r0,cpsr\t\n"
		"orr r0,r0,#0x80\t\n"
		"msr cpsr_c,r0\t\n"
		:
		:
		: "r0");
};

inline void interruptEnableFIQ(){
	asm volatile(
		"mrs r0,cpsr\t\n"
		"bic r0,r0,#0x40\t\n"
		"msr cpsr_c,r0\t\n"
		:
		:
		: "r0");
}

inline void interruptDisableFIQ(){
	asm volatile(
		"mrs r0,cpsr\t\n"
		"orr r0,r0,#0x40\t\n"
		"msr cpsr_c,r0\t\n"
		:
		:
		: "r0");
};

inline void interruptEnableSource(unsigned int int_nr) {
	INTERRUPT->INTENNUM = int_nr;
}

inline void interruptDisableSource(unsigned int int_nr) {
	INTERRUPT->INTDISNUM = int_nr;
}

#endif /* INTERRUPT_H_ */
