################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Screen/BWSettings.cpp \
../Core/Src/Screen/LogBook.cpp \
../Core/Src/Screen/MainScreen.cpp \
../Core/Src/Screen/PWSettings.cpp \
../Core/Src/Screen/ScreenControl.cpp \
../Core/Src/Screen/TimeScreen.cpp 

OBJS += \
./Core/Src/Screen/BWSettings.o \
./Core/Src/Screen/LogBook.o \
./Core/Src/Screen/MainScreen.o \
./Core/Src/Screen/PWSettings.o \
./Core/Src/Screen/ScreenControl.o \
./Core/Src/Screen/TimeScreen.o 

CPP_DEPS += \
./Core/Src/Screen/BWSettings.d \
./Core/Src/Screen/LogBook.d \
./Core/Src/Screen/MainScreen.d \
./Core/Src/Screen/PWSettings.d \
./Core/Src/Screen/ScreenControl.d \
./Core/Src/Screen/TimeScreen.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Screen/%.o: ../Core/Src/Screen/%.cpp Core/Src/Screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32L412xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

