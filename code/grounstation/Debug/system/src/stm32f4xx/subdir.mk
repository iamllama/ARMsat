################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/stm32f4xx/stm32f4xx_hal.c \
../system/src/stm32f4xx/stm32f4xx_hal_adc.c \
../system/src/stm32f4xx/stm32f4xx_hal_adc_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_cortex.c \
../system/src/stm32f4xx/stm32f4xx_hal_crc.c \
../system/src/stm32f4xx/stm32f4xx_hal_dma.c \
../system/src/stm32f4xx/stm32f4xx_hal_dma_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_flash.c \
../system/src/stm32f4xx/stm32f4xx_hal_flash_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_flash_ramfunc.c \
../system/src/stm32f4xx/stm32f4xx_hal_gpio.c \
../system/src/stm32f4xx/stm32f4xx_hal_i2c.c \
../system/src/stm32f4xx/stm32f4xx_hal_i2c_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_pwr.c \
../system/src/stm32f4xx/stm32f4xx_hal_pwr_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_rcc.c \
../system/src/stm32f4xx/stm32f4xx_hal_rcc_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_sd.c \
../system/src/stm32f4xx/stm32f4xx_hal_spi.c \
../system/src/stm32f4xx/stm32f4xx_hal_tim.c \
../system/src/stm32f4xx/stm32f4xx_hal_tim_ex.c \
../system/src/stm32f4xx/stm32f4xx_hal_uart.c \
../system/src/stm32f4xx/stm32f4xx_ll_sdmmc.c 

OBJS += \
./system/src/stm32f4xx/stm32f4xx_hal.o \
./system/src/stm32f4xx/stm32f4xx_hal_adc.o \
./system/src/stm32f4xx/stm32f4xx_hal_adc_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_cortex.o \
./system/src/stm32f4xx/stm32f4xx_hal_crc.o \
./system/src/stm32f4xx/stm32f4xx_hal_dma.o \
./system/src/stm32f4xx/stm32f4xx_hal_dma_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_flash.o \
./system/src/stm32f4xx/stm32f4xx_hal_flash_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_flash_ramfunc.o \
./system/src/stm32f4xx/stm32f4xx_hal_gpio.o \
./system/src/stm32f4xx/stm32f4xx_hal_i2c.o \
./system/src/stm32f4xx/stm32f4xx_hal_i2c_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_pwr.o \
./system/src/stm32f4xx/stm32f4xx_hal_pwr_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_rcc.o \
./system/src/stm32f4xx/stm32f4xx_hal_rcc_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_sd.o \
./system/src/stm32f4xx/stm32f4xx_hal_spi.o \
./system/src/stm32f4xx/stm32f4xx_hal_tim.o \
./system/src/stm32f4xx/stm32f4xx_hal_tim_ex.o \
./system/src/stm32f4xx/stm32f4xx_hal_uart.o \
./system/src/stm32f4xx/stm32f4xx_ll_sdmmc.o 

C_DEPS += \
./system/src/stm32f4xx/stm32f4xx_hal.d \
./system/src/stm32f4xx/stm32f4xx_hal_adc.d \
./system/src/stm32f4xx/stm32f4xx_hal_adc_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_cortex.d \
./system/src/stm32f4xx/stm32f4xx_hal_crc.d \
./system/src/stm32f4xx/stm32f4xx_hal_dma.d \
./system/src/stm32f4xx/stm32f4xx_hal_dma_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_flash.d \
./system/src/stm32f4xx/stm32f4xx_hal_flash_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_flash_ramfunc.d \
./system/src/stm32f4xx/stm32f4xx_hal_gpio.d \
./system/src/stm32f4xx/stm32f4xx_hal_i2c.d \
./system/src/stm32f4xx/stm32f4xx_hal_i2c_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_pwr.d \
./system/src/stm32f4xx/stm32f4xx_hal_pwr_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_rcc.d \
./system/src/stm32f4xx/stm32f4xx_hal_rcc_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_sd.d \
./system/src/stm32f4xx/stm32f4xx_hal_spi.d \
./system/src/stm32f4xx/stm32f4xx_hal_tim.d \
./system/src/stm32f4xx/stm32f4xx_hal_tim_ex.d \
./system/src/stm32f4xx/stm32f4xx_hal_uart.d \
./system/src/stm32f4xx/stm32f4xx_ll_sdmmc.d 


# Each subdirectory must supply rules for building sources it contributes
system/src/stm32f4xx/%.o: ../system/src/stm32f4xx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F411xE -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4xx" -I"../system/include/cmsis/device" -I"../Middlewares/Third_Party/FatFs/src/drivers" -I"../Middlewares/Third_Party/FatFs/src" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


