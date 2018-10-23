################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/aes.c \
../Src/crc.c \
../Src/dma.c \
../Src/gpio.c \
../Src/iwdg.c \
../Src/lcd_conf.c \
../Src/main.c \
../Src/power_counter.c \
../Src/rng.c \
../Src/rtc.c \
../Src/stm32l4xx_hal_msp.c \
../Src/stm32l4xx_it.c \
../Src/system_stm32l4xx.c \
../Src/tim.c \
../Src/usart.c 

OBJS += \
./Src/adc.o \
./Src/aes.o \
./Src/crc.o \
./Src/dma.o \
./Src/gpio.o \
./Src/iwdg.o \
./Src/lcd_conf.o \
./Src/main.o \
./Src/power_counter.o \
./Src/rng.o \
./Src/rtc.o \
./Src/stm32l4xx_hal_msp.o \
./Src/stm32l4xx_it.o \
./Src/system_stm32l4xx.o \
./Src/tim.o \
./Src/usart.o 

C_DEPS += \
./Src/adc.d \
./Src/aes.d \
./Src/crc.d \
./Src/dma.d \
./Src/gpio.d \
./Src/iwdg.d \
./Src/lcd_conf.d \
./Src/main.d \
./Src/power_counter.d \
./Src/rng.d \
./Src/rtc.d \
./Src/stm32l4xx_hal_msp.d \
./Src/stm32l4xx_it.d \
./Src/system_stm32l4xx.d \
./Src/tim.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -std=c11 '-D__weak=__attribute__((weak))' -DENABLE_UART_PIN_SWAP -DUART_XFER_STPM3X -DNDEBUG -DEE_ACCESS_32BITS -DBOARD_REV_1 '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32L486xx -I"/home/john/Projects/SystemWorkBench/BasicProject/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/NVM/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/drivers/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/handlers/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/include/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STPM3X/tasks/inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/HD44780/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/EEPROM/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STM32L4xx_HAL_Driver/Inc" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"/home/john/Projects/SystemWorkBench/BasicProject/Drivers/CMSIS/Include"  -Og -g3 -Wall -Wextra -Wconversion -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


