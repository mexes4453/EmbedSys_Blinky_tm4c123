# Author : Chiemezie Albert Udoh
# Project: Blinky LED
# MCU	 : TM4C123
# Date   : 15.10.2022
# Files  : Linker_script, Startup_file
#
# DIRECTORIES

PATH_ROOT=/home/mexes/Documents/ES
PATH_CWD=$(PATH_ROOT)/projects/02_tm4c123_blinky
PATH_DEV=$(PATH_ROOT)/dev/msp430/msp430-gcc-9.3.1.11_linux64
PATH_DEV_BIN=$(PATH_DEV)/bin
PATH_DEV_LIB=$(PATH_DEV)/lib
PATH_DEV_HEADER="$(PATH_DEV_LIB)/gcc/msp430-elf/9.3.1/plugin/include/msp430/"
DIR_INCLUDE=$(PATH_CWD)/include
DIR_LINKER=$(DIR_INCLUDE)
DIR_BUILD = build
DIR_OBJ = $(DIR_BUILD)/obj
DIR_BIN = $(DIR_BUILD)/bin

# DIR DEBUGGER
DIR_TI_CCS=$(PATH_ROOT)/IDE/ccs1200/ccs
DIR_DEBUGGER=$(DIR_TI_CCS)/ccs_base/DebugServer
DIR_DEBUG_BIN=$(DIR_DEBUGGER)/bin
DIR_DEBUG_DRIVER=$(DIR_DEBUGGER)/drivers

# TOOLCHAIN
CC = arm-none-eabi-gcc
DEBUG = LD_LIBRARY_PATH=$(DIR_DEBUG_DRIVER) $(DIR_DEBUG_BIN)/mspdebug

# FILES
TARGET = $(DIR_BIN)/blink

SRCS = 	main.c \
      	php_led.c \
      	tm4c123_startup.c \

OBJ_NAMES = $(SRCS:.c=.o)
OBJS = $(patsubst %, $(DIR_OBJ)/%, $(OBJ_NAMES))

# FLAGS
MCU_MODEL = __MSP430F5529__
MCU = cortex-m4
WFLAGS = -Wall -Wextra -Werror -Wshadow
CFLAGS = -mcpu=$(MCU) $(WFLAGS) $(addprefix -I,$(DIR_INCLUDE)) -I. -Og -g -mthumb \
	 -std=gnu11  --specs=nosys.specs
# unused flag: -D$(MCU_MODEL)
LDFLAGS = -mcpu=$(MCU) --specs=nosys.specs $(addprefix -L,$(DIR_LINKER)) $(addprefix -I,$(DIR_INCLUDE)) -T tm4c123_ls.ld  -Wl,-Map=$(TARGET).map
#LDFLAGS = -mcpu=$(MCU) --specs=nosys.specs $(addprefix -L,$(DIR_LINKER)) $(addprefix -I,$(DIR_INCLUDE)) -T tm4c123gh6pm.lds  -Wl,-Map=$(TARGET).map


# BUILD
# LINKING
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@

# COMPILING - OBJ FILES
$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $^ $(CFLAGS) -c -o $@

# PHONY
.PHONY : all clean flash

all: $(TARGET)

clean:
	rm -r $(DIR_BUILD)

flash: $(TARGET)
#	$(DEBUG) tilib "prog $(TARGET)"
	openocd -f /usr/share/openocd/scripts/board/ti_ek-tm4c123gxl.cfg

	
	
