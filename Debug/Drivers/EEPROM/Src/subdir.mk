################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/EEPROM/Src/eeprom_emul.c \
../Drivers/EEPROM/Src/flash_interface.c 

OBJS += \
./Drivers/EEPROM/Src/eeprom_emul.o \
./Drivers/EEPROM/Src/flash_interface.o 

C_DEPS += \
./Drivers/EEPROM/Src/eeprom_emul.d \
./Drivers/EEPROM/Src/flash_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/EEPROM/Src/%.o: ../Drivers/EEPROM/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c11 '-D__weak=__attribute__((weak))' -DENABLE_UART_PIN_SWAP -DUART_XFER_STPM3X -DNDEBUG -DEE_ACCESS_32BITS -DBOARD_REV_1 '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32L486xx -I"/home/john/Projects/SystemWorkBench/BasicProject/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/NVM/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/drivers/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/handlers/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/include/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/tasks/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/HD44780/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/EEPROM/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STM32L4xx_HAL_Driver/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/CMSIS/Include"  -Og -g3 -Wall -Wextra -Wconversion -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


