################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/a_source_file_example.c \
../Core/Src/alarm.c \
../Core/Src/canspi.c \
../Core/Src/datetime.c \
../Core/Src/fatman.c \
../Core/Src/freertos.c \
../Core/Src/main.c \
../Core/Src/mcp2515.c \
../Core/Src/myqueue.c \
../Core/Src/psa.c \
../Core/Src/state.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/timecounter.c 

C_DEPS += \
./Core/Src/a_source_file_example.d \
./Core/Src/alarm.d \
./Core/Src/canspi.d \
./Core/Src/datetime.d \
./Core/Src/fatman.d \
./Core/Src/freertos.d \
./Core/Src/main.d \
./Core/Src/mcp2515.d \
./Core/Src/myqueue.d \
./Core/Src/psa.d \
./Core/Src/state.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/timecounter.d 

OBJS += \
./Core/Src/a_source_file_example.o \
./Core/Src/alarm.o \
./Core/Src/canspi.o \
./Core/Src/datetime.o \
./Core/Src/fatman.o \
./Core/Src/freertos.o \
./Core/Src/main.o \
./Core/Src/mcp2515.o \
./Core/Src/myqueue.o \
./Core/Src/psa.o \
./Core/Src/state.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/timecounter.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F469xx -DDEBUG=1 -c -I../FATFS/Target -I../FATFS/App -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/a_source_file_example.d ./Core/Src/a_source_file_example.o ./Core/Src/alarm.d ./Core/Src/alarm.o ./Core/Src/canspi.d ./Core/Src/canspi.o ./Core/Src/datetime.d ./Core/Src/datetime.o ./Core/Src/fatman.d ./Core/Src/fatman.o ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/mcp2515.d ./Core/Src/mcp2515.o ./Core/Src/myqueue.d ./Core/Src/myqueue.o ./Core/Src/psa.d ./Core/Src/psa.o ./Core/Src/state.d ./Core/Src/state.o ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/timecounter.d ./Core/Src/timecounter.o

.PHONY: clean-Core-2f-Src

