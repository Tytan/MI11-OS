OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm",
	      "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY {
	RAM		: ORIGIN = 0x08000000, LENGTH = 16M
	ROM		: ORIGIN = 0x00000000, LENGTH = 1M
}
_start = ORIGIN(ROM);
ENTRY(_start)

SECTIONS {
	.isr_vectors	: {
				*(.isr_vectors) 
				. = ALIGN(4); 
	} >ROM AT>ROM
	
	.init	: {
				*(.init) 
				. = ALIGN(4); 
	} >ROM AT>ROM
				
	.text 	: { 
				*(.text) 
				. = ALIGN(4); 
	} >ROM AT>ROM
				
	.rodata	: { 
				*(.rodata) 
				. = ALIGN(4); 
	} >ROM AT>ROM
				
	.bss 	: { 
				*(.bss) *(COMMON)
				. = ALIGN(4);
	} >RAM
				

	.data 	: { 
				*(.data) 
				. = ALIGN(4); 
	} >RAM AT>ROM
}

_stack_irq = ORIGIN(RAM) + LENGTH(RAM) - 4;
_stack = ORIGIN(RAM) + LENGTH(RAM) - 4 - 1024;

ram_copy_start = ADDR(.data);

rom_copy_start = LOADADDR(.data);
rom_copy_end = rom_copy_start + SIZEOF(.data);

bss_start = ADDR(.bss);
bss_end = bss_start + SIZEOF(.bss); 
