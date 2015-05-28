/*
 * registers.h
 *
 *  Created on: 3 avr. 2015
 *      Author: mi03
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

typedef unsigned int reg_t;

/****************************/
/* 	GPIO  */
/****************************/

typedef struct {
	reg_t DDIR,
		OCR1, OCR2,
		ICONFA1, ICONFA2,
		ICONFB1, ICONFB2,
		DR,
		GIUS,
		SSR,
		ICR1, ICR2,
		IMR,
		ISR,
		GPR,
		SWR,
		PUEN;
} gpio_t;

#define GPIO_A	((gpio_t*)0x21c000)
#define GPIO_B	((gpio_t*)0x21c100)
#define GPIO_C	((gpio_t*)0x21c200)
#define GPIO_D 	((gpio_t*)0x21c300)


/****************************/
/* 	TIMER  */
/****************************/

#define CLOCK_FREQ 	16000000

typedef struct {
	reg_t TCTL,
		TPRER,
		TCMP,
		TCR,
		TCN,
		TSTAT;
} timer_t;

#define TIMER1 		((timer_t*)0x202000)
#define TIMER2 		((timer_t*)0x203000)

#define TSTAT_COMP 0x1


/****************************/
/* 	INTERRUPT  */
/****************************/

typedef struct {
	reg_t INTCTL,
		NIMASK,
		INTENNUM, INTDISNUM,
		INTENABLEH, INTENABLEL,
		INTTYPEH, INTTYPEL,
		NIPRIORITY[8],
		NIVECSR, FIVECSR,
		INTSRCH, INTSRCL,
		NIPDH, NIPDL,
		FIPNDH, FIPNDL;
} interrupt_t;

#define INTERRUPT	((interrupt_t*)0x223000)

#endif /* REGISTERS_H_ */
