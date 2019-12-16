################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GameEngine.c \
../Src/gpio.c \
../Src/lcd.c \
../Src/mygpio.c 

OBJS += \
./Src/GameEngine.o \
./Src/gpio.o \
./Src/lcd.o \
./Src/mygpio.o 

C_DEPS += \
./Src/GameEngine.d \
./Src/gpio.d \
./Src/lcd.d \
./Src/mygpio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/GameEngine.o: ../Src/GameEngine.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Src/OverAllEnv" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GameEngine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/gpio.o: ../Src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Src/OverAllEnv" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/lcd.o: ../Src/lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Src/OverAllEnv" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/mygpio.o: ../Src/mygpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Inc/OverAllEnv" -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Src/OverAllEnv" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/mygpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

