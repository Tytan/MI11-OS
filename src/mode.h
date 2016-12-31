#ifndef MODE_H
#define MODE_H

#define MODE_IRQ (0b10010)
#define MODE_SYS (0b11111)

inline void switchMode(uint8_t mode) {
	asm volatile (
		"mrs r0, CPSR\t\n" // Copie CPSR dans r0
		"bic r0, r0, #0x1f\t\n" // Met à 0 les 5 bits M
		"orr r0, r0, %[input]\t\n" // change mode
		"msr CPSR_c, r0\t\n" // Recharge les bits de contrôle
		: 
		: [input]"r" (mode)
		: "r0")
}

#endif
