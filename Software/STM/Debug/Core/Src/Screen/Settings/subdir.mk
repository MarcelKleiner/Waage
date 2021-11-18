################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Screen/Settings/Contrast.cpp \
../Core/Src/Screen/Settings/DateSettings.cpp \
../Core/Src/Screen/Settings/TimeSettings.cpp 

OBJS += \
./Core/Src/Screen/Settings/Contrast.o \
./Core/Src/Screen/Settings/DateSettings.o \
./Core/Src/Screen/Settings/TimeSettings.o 

CPP_DEPS += \
./Core/Src/Screen/Settings/Contrast.d \
./Core/Src/Screen/Settings/DateSettings.d \
./Core/Src/Screen/Settings/TimeSettings.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Screen/Settings/%.o: ../Core/Src/Screen/Settings/%.cpp Core/Src/Screen/Settings/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32L412xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

