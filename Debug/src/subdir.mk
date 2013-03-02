################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/balloon.cpp \
../src/functions.cpp \
../src/init_n_destroy.cpp \
../src/input.cpp \
../src/main.cpp \
../src/mainGame.cpp \
../src/sprite.cpp \
../src/starting.cpp \
../src/timer.cpp 

OBJS += \
./src/balloon.o \
./src/functions.o \
./src/init_n_destroy.o \
./src/input.o \
./src/main.o \
./src/mainGame.o \
./src/sprite.o \
./src/starting.o \
./src/timer.o 

CPP_DEPS += \
./src/balloon.d \
./src/functions.d \
./src/init_n_destroy.d \
./src/input.d \
./src/main.d \
./src/mainGame.d \
./src/sprite.d \
./src/starting.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/shalil/Codes/git/crazyNeo/bubble-trouble-clone/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


