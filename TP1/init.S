.align 4
.code 32
.include "../lowlevel_init.S"

.section ".isr_vectors", "ax", %progbits

vectors:
	b start 				@ Reset vector
	b . @undefined 			@ Undefined instruction
	b . @soft_interrupt 	@ Software interrupt
	b . @prefetch_abort 	@ Prefetch abort exception
	b . @data_abort 		@ Data abort exception
	b . 					@ Reserved vector, not used
	b irq_handler 			@ Normal interrupt
	b . @fiq_handler 		@ Fast interrupt

.section ".init", "ax", %progbits

start:
		bl _lowlevel_init
		ldr sp, =_stack @init stack pointer at the end on RAM

@init_irq_stack
		mrs r0, CPSR
		bic r0, #0x1f		@ clear bits [4:0]
		orr r0, #0b10010	@ set IRQ mode
		msr CPSR_c, r0		@ mode switch
		ldr sp, =_stack_irq @init stack pointer
		bic r0, #0x1f		@ clear bits [4:0]
		orr r0, #0b10011	@ set Supervisor mode
		msr CPSR_c, r0		@ mode switch

@write 0 to bss
		mov r0, #0
		ldr r1, =bss_start
		ldr r2, =bss_end
wBSS:	cmp r1, r2
	 	bhs endBSS
		str r0, [r1], #4 @ write 32 bits of 0
		b wBSS
endBSS:

		ldr r1, =rom_copy_start
		ldr r2, =rom_copy_end
		ldr r3, =ram_copy_start
wData:	cmp r1, r2
	 	bhs endData
	 	ldr r0, [r1], #4
		str r0, [r3], #4
		b wData
endData:
launch:
		bl main
		b start
