################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graph/Graph.cpp 

OBJS += \
./Graph/Graph.o 

CPP_DEPS += \
./Graph/Graph.d 


# Each subdirectory must supply rules for building sources it contributes
Graph/%.o: ../Graph/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/e-man/eclipse-workspace/CppAlgorithms" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


