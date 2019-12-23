################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Util/LinkedList.c \
../Src/Util/Random.c \
../Src/Util/Renderer.c \
../Src/Util/Time.c 

OBJS += \
./Src/Util/LinkedList.o \
./Src/Util/Random.o \
./Src/Util/Renderer.o \
./Src/Util/Time.o 

C_DEPS += \
./Src/Util/LinkedList.d \
./Src/Util/Random.d \
./Src/Util/Renderer.d \
./Src/Util/Time.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Util/LinkedList.o: ../Src/Util/LinkedList.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Util/LinkedList.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Util/Random.o: ../Src/Util/Random.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Util/Random.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Util/Renderer.o: ../Src/Util/Renderer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Util/Renderer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Util/Time.o: ../Src/Util/Time.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Util/Time.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

