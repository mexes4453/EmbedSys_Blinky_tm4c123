###################################################################
# Makefile, startup file and linker script
# https://www.youtube.com/c/FastbitEmbeddedBrainAcademy
# Documentation : http://gcc.gnu.org/onlinedocs/gcc/index.html
# 		section 3.3  options controlling the kind of output
#		section 3.19 machine dependent option
#		section 6.34.1 common variable attribute
####################################################################

1.) Download the GNU GCC toolchain from the link
 	
	-> https://developer.arm.com/downloads/-/gnu-rm

2.) Tools
	-> compiler, assembler, linker	- arm-none-eabi-gcc
	-> assembler 			- arm-none-eabi-as
	-> linker 			- arm-none-eabi-ld

	-> elf file analyzer		- arm-none-eabi-objdump
					- arm-none-eabi-readelf
					- arm-none-eabi-nm

	-> format converter 		- arm-none-eabi-objcopy
	To view the tool option run the prog command.
	-> arm-none-eabi-objdump -h main.o - display the sections in main.o
	-> arm-none-eabi-objdump -d main.o - display the disassembled code (text section only) of main.o
	-> arm-none-eabi-objdump -D main.o - display the disassembled code (all sections) of main.o
	-> arm-none-eabi-objdump -s main.o - display the full content of all section in main.o
	-> arm-none-eabi-nm <elf_file>	   - display all the symbols in the application file.


3.) Makefile
	-> Flags (compilation with arm-none-eabi-gcc)
		 include the -D flag and specify the microcontroller name for its header file inclusion.
			-> -D__MSP430F5299__
		 -mthumb 		to compile codes for thumb state
		 -mcpu=cortex-m4	to specify the micro controller processor architecture
		 -S			to stop the compilation at compile stage, output is *.s (assembly file)
		 -c		 	to stop the compilation at assembly stage,output is *.o (object or relocatable files or .elf - executable and linkable format)
		 -std=gnu11		select c language standard
		 -Og			select code optimization level - minimum optimization
		 -g			include codes for debugging
		 --spec=nosys.specs

4.) Startup_code
	-> execute codes prior to call of main function
	-> enable some hardware required by the main function (co-processor, floating point unit)
	-> vector table placement in memory. (arm dependent or mcu usr manual)
	-> stack reintialization
	-> data (data, .bss) section initialization in main memory prior to call of main function
		-> The requires copying the data from flash to sram.o

	3 TASKS REQUIRED
	----------------
	-> Create vector table (MCU dependent) - contains exeception and interrupt handler (function) addresses.
		The total contents are (System exeception + interrupt (IRQ) + MSP)
		Total memory =	(System exeception + interrupt (IRQ) + MSP) * 1word
		each word contains 4 bytes
		Total memory =	(System exeception + interrupt (IRQ) + MSP) * 4bytes
		Total memory =  (FFF80-FFFFF) * 4
		uint32_t vectors[] = {store MSP & address of vector handlers}
		
		Instruct compiler not to include the vector table in .data section but rather in a different user defined section
		using the attribute keyword -> __attribute__((section("name"))) to create section.
		uint32_t vectors[] __attribute__((section(".isr_vector"))= {store MSP & address of vector handlers}
		
	*Note -> see linker script notes.
	-> Initialise data and .bss section in SRAM
	-> Call main()

