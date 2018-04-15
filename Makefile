# This file was automagically generated by mbed.org. For more information,
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded

GCC_BIN =
PROJECT = ./BUILD/Susi
OBJECTS = ./src/main.o ./src/tald-app.o ./src/libtald.o ./src/tld_comm.o ./src/tld_dstore.o ./BLE_nRF8001/BLE_nRF8001/Arduino.o ./BLE_nRF8001/BLE_nRF8001/BLEAttribute.o ./BLE_nRF8001/BLE_nRF8001/BLECentral.o ./BLE_nRF8001/BLE_nRF8001/BLECharacteristic.o ./BLE_nRF8001/BLE_nRF8001/BLEDescriptor.o ./BLE_nRF8001/BLE_nRF8001/BLEPeripheral.o ./BLE_nRF8001/BLE_nRF8001/BLEService.o ./BLE_nRF8001/BLE_nRF8001/BLETypedCharacteristics.o ./BLE_nRF8001/BLE_nRF8001/BLEUuid.o ./BLE_nRF8001/BLE_nRF8001/nRF8001.o ./BLE_nRF8001/BLE_nRF8001/utility/aci_queue.o ./BLE_nRF8001/BLE_nRF8001/utility/aci_setup.o ./BLE_nRF8001/BLE_nRF8001/utility/acilib.o ./BLE_nRF8001/BLE_nRF8001/utility/hal_aci_tl.o ./BLE_nRF8001/BLE_nRF8001/utility/lib_aci.o
SYS_OBJECTS = ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_flash_ramfunc.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/board.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/cmsis_nvic.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/hal_tick.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/mbed_overrides.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/retarget.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/startup_stm32l053xx.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_adc.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_adc_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_comp.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_comp_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_cortex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_crc.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_crc_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_cryp.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_cryp_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_dac.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_dac_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_dma.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_firewall.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_flash.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_flash_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_smartcard.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_gpio.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_i2c.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_i2c_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_i2s.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_irda.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_iwdg.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_lcd.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_lptim.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_pcd.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_pcd_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_pwr.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_pwr_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_rcc.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_rcc_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_rng.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_rtc.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_rtc_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_smartcard_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_smbus.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_spi.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_tim.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_tim_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_tsc.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_uart.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_uart_ex.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_usart.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/stm32l0xx_hal_wwdg.o ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/system_stm32l0xx.o
INCLUDE_PATHS = -I. -I./SDFileSystem -I./SDFileSystem/FATFileSystem -I./SDFileSystem/FATFileSystem/ChaN -I./BLE_nRF8001 -I./BLE_nRF8001/BLE_nRF8001 -I./BLE_nRF8001/BLE_nRF8001/utility -I./mbed -I./mbed/TARGET_NUCLEO_L053R8 -I./mbed/TARGET_NUCLEO_L053R8/TARGET_STM -I./mbed/TARGET_NUCLEO_L053R8/TARGET_STM/TARGET_STM32L0 -I./mbed/TARGET_NUCLEO_L053R8/TARGET_STM/TARGET_STM32L0/TARGET_NUCLEO_L053R8 -I./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM
LIBRARY_PATHS = -L./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM
LIBRARIES = -lmbed
LINKER_SCRIPT = ./mbed/TARGET_NUCLEO_L053R8/TOOLCHAIN_GCC_ARM/STM32L053X8.ld

###############################################################################
AS      = $(GCC_BIN)arm-none-eabi-as
CC      = $(GCC_BIN)arm-none-eabi-gcc
CPP     = $(GCC_BIN)arm-none-eabi-g++
LD      = $(GCC_BIN)arm-none-eabi-gcc
OBJCOPY = $(GCC_BIN)arm-none-eabi-objcopy
OBJDUMP = $(GCC_BIN)arm-none-eabi-objdump
SIZE    = $(GCC_BIN)arm-none-eabi-size


CPU = -mcpu=cortex-m0plus -mthumb
CC_FLAGS = $(CPU) -c -g -fno-common -fmessage-length=0 -Wall -Wextra -fno-exceptions -ffunction-sections -fdata-sections -fomit-frame-pointer -MMD -MP -std=c++11
CC_SYMBOLS = -DTARGET_FF_ARDUINO -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_GCC -DTARGET_FF_MORPHO -DTARGET_LIKE_MBED -DTARGET_CORTEX_M -DMBED_BUILD_TIMESTAMP=1456943919.17 -DTARGET_M0P -D__MBED__=1 -DTARGET_NUCLEO_L053R8 -DTARGET_STM32L0 -DTARGET_STM -DTARGET_STM32L053R8 -D__CORTEX_M0PLUS -DTARGET_LIKE_CORTEX_M0 -DARM_MATH_CM0PLUS

LD_FLAGS = $(CPU) -Wl,--gc-sections --specs=nano.specs -Wl,--wrap,main -Wl,-Map=$(PROJECT).map,--cref
#LD_FLAGS += -u _printf_float -u _scanf_float
LD_SYS_LIBS = -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys


ifeq ($(DEBUG), 1)
  CC_FLAGS += -DDEBUG -O0
else
  CC_FLAGS += -DNDEBUG -Os
endif

$(shell mkdir -p ./BUILD)

.PHONY: all clean lst size

all: $(PROJECT).bin $(PROJECT).hex size


clean:
	rm -f $(PROJECT).bin $(PROJECT).elf $(PROJECT).hex $(PROJECT).map $(PROJECT).lst $(OBJECTS) $(DEPS)


.asm.o:
	$(CC) $(CPU) -c -x assembler-with-cpp -o $@ $<
.s.o:
	$(CC) $(CPU) -c -x assembler-with-cpp -o $@ $<
.S.o:
	$(CC) $(CPU) -c -x assembler-with-cpp -o $@ $<

.c.o:
	$(CC)  $(CC_FLAGS) $(CC_SYMBOLS) -std=gnu99   $(INCLUDE_PATHS) -o $@ $<

.cpp.o:
	$(CPP) $(CC_FLAGS) $(CC_SYMBOLS) -std=c++11 -fno-rtti $(INCLUDE_PATHS) -o $@ $<



$(PROJECT).elf: $(OBJECTS) $(SYS_OBJECTS)
	$(LD) $(LD_FLAGS) -T$(LINKER_SCRIPT) $(LIBRARY_PATHS) -o $@ $^ $(LIBRARIES) $(LD_SYS_LIBS) $(LIBRARIES) $(LD_SYS_LIBS)


$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $@

$(PROJECT).hex: $(PROJECT).elf
	@$(OBJCOPY) -O ihex $< $@

$(PROJECT).lst: $(PROJECT).elf
	@$(OBJDUMP) -Sdh $< > $@

lst: $(PROJECT).lst

size: $(PROJECT).elf
	$(SIZE) $(PROJECT).elf

DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)
