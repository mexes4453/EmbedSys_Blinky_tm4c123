ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx):ORIGIN =0x00000000,LENGTH =256K
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =32K
}

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		_e_text = .;	
	}> FLASH

	.data :
	{
		_s_data = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_e_data = .;
	}> SRAM AT> FLASH

	.bss :
	{
		__bss_start__ = .;
		*(.bss)
		*(.bss*)
		. = ALIGN(4);
		__bss_end__ = .;
	}> SRAM
}
