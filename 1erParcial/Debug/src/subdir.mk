################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/1erParcial.c \
../src/electrodomestico.c \
../src/reparacion.c \
../src/utnInputs.c 

OBJS += \
./src/1erParcial.o \
./src/electrodomestico.o \
./src/reparacion.o \
./src/utnInputs.o 

C_DEPS += \
./src/1erParcial.d \
./src/electrodomestico.d \
./src/reparacion.d \
./src/utnInputs.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


