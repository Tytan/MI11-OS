/*
 * timer.h
 *
 *  Created on: 3 avr. 2015
 *      Author: mi03
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "registers.h"

#define TIMER_IRQEN		(1 << 4)

inline void timerInit(timer_t* timer, float hz) {
	timer->TCTL = 0x0003;
	timer->TPRER = 0x00;
	timer->TCMP = (reg_t)(CLOCK_FREQ / hz);
}

inline int timerComparedOccured(timer_t* timer) {
	if (timer->TSTAT & TSTAT_COMP) {
		timer->TSTAT &= ~TSTAT_COMP;
		return 1;
	}
	return 0;
}

inline void timerEnableInterrupt(timer_t* timer) {
	timer->TCTL |= TIMER_IRQEN;
}

#endif /* TIMER_H_ */
