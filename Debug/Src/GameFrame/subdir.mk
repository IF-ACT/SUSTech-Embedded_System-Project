################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GameFrame/GameEvent.c \
../Src/GameFrame/GameObject.c \
../Src/GameFrame/GameObject_Bullet.c \
../Src/GameFrame/GameObject_Enemy.c \
../Src/GameFrame/GameObject_Self.c 

OBJS += \
./Src/GameFrame/GameEvent.o \
./Src/GameFrame/GameObject.o \
./Src/GameFrame/GameObject_Bullet.o \
./Src/GameFrame/GameObject_Enemy.o \
./Src/GameFrame/GameObject_Self.o 

C_DEPS += \
./Src/GameFrame/GameEvent.d \
./Src/GameFrame/GameObject.d \
./Src/GameFrame/GameObject_Bullet.d \
./Src/GameFrame/GameObject_Enemy.d \
./Src/GameFrame/GameObject_Self.d 


# Each subdirectory must supply rules for building sources it contributes
Src/GameFrame/GameEvent.o: ../Src/GameFrame/GameEvent.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GameFrame/GameEvent.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/GameFrame/GameObject.o: ../Src/GameFrame/GameObject.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GameFrame/GameObject.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/GameFrame/GameObject_Bullet.o: ../Src/GameFrame/GameObject_Bullet.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GameFrame/GameObject_Bullet.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/GameFrame/GameObject_Enemy.o: ../Src/GameFrame/GameObject_Enemy.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GameFrame/GameObject_Enemy.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/GameFrame/GameObject_Self.o: ../Src/GameFrame/GameObject_Self.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I"N:/OneDrive - Platinum/University/3/CS301_Embedded_System/Project/SUSTech-Embedded_System-Project/Img" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GameFrame/GameObject_Self.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

