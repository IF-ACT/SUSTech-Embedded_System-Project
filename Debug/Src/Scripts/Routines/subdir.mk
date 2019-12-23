################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Scripts/Routines/Demo4_Routine.c 

OBJS += \
./Src/Scripts/Routines/Demo4_Routine.o 

C_DEPS += \
./Src/Scripts/Routines/Demo4_Routine.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Scripts/Routines/Demo4_Routine.o: ../Src/Scripts/Routines/Demo4_Routine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Img" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/OverAllEnv" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Prefebs" -I"D:/worksoftware/STM32CubeIDE_1.0.2/newworkplace/SUSTech-Embedded_System-Project/Src/Scripts/Routines" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Scripts/Routines/Demo4_Routine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

