# EmbedSys_Blinky_tm4c123
Blinky LED on TM4C123 TI Launchpad


# Motivation
The motivation for this project is to perform the project without any IDE and using only the GNU toolchain on Linux.
Also to implement the startup code and the linkerscript for the launchpad independent of the ones provided by the manufacturer.

# Build
To build the program for the target, simply follow the command below.

$ make    : This utilises the makefile within the directory to build the elf program file

# Flashing
Flashing the code unto the boards requires a host application (openocd).
Type the following command to start the process.

$ make flash

Then follow the instructions defined in the file "mcu_exe_debug_flash.txt"

