################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/OverAllEnv/gpio.c \
../Src/OverAllEnv/lcd.c \
../Src/OverAllEnv/main.c \
../Src/OverAllEnv/mygpio.c \
../Src/OverAllEnv/stm32f1xx_hal_msp.c \
../Src/OverAllEnv/stm32f1xx_it.c \
../Src/OverAllEnv/syscalls.c \
../Src/OverAllEnv/sysmem.c \
../Src/OverAllEnv/system_stm32f1xx.c \
../Src/OverAllEnv/usart.c 

OBJS += \
./Src/OverAllEnv/gpio.o \
./Src/OverAllEnv/lcd.o \
./Src/OverAllEnv/main.o \
./Src/OverAllEnv/mygpio.o \
./Src/OverAllEnv/stm32f1xx_hal_msp.o \
./Src/OverAllEnv/stm32f1xx_it.o \
./Src/OverAllEnv/syscalls.o \
./Src/OverAllEnv/sysmem.o \
./Src/OverAllEnv/system_stm32f1xx.o \
./Src/OverAllEnv/usart.o 

C_DEPS += \
./Src/OverAllEnv/gpio.d \
./Src/OverAllEnv/lcd.d \
./Src/OverAllEnv/main.d \
./Src/OverAllEnv/mygpio.d \
./Src/OverAllEnv/stm32f1xx_hal_msp.d \
./Src/OverAllEnv/stm32f1xx_it.d \
./Src/OverAllEnv/syscalls.d \
./Src/OverAllEnv/sysmem.d \
./Src/OverAllEnv/system_stm32f1xx.d \
./Src/OverAllEnv/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/OverAllEnv/gpio.o: ../Src/OverAllEnv/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/lcd.o: ../Src/OverAllEnv/lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/main.o: ../Src/OverAllEnv/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/mygpio.o: ../Src/OverAllEnv/mygpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/mygpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/stm32f1xx_hal_msp.o: ../Src/OverAllEnv/stm32f1xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/stm32f1xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/stm32f1xx_it.o: ../Src/OverAllEnv/stm32f1xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/stm32f1xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/syscalls.o: ../Src/OverAllEnv/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/sysmem.o: ../Src/OverAllEnv/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/system_stm32f1xx.o: ../Src/OverAllEnv/system_stm32f1xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/system_stm32f1xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/OverAllEnv/usart.o: ../Src/OverAllEnv/usart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/OverAllEnv/usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

