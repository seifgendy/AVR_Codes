################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_program.c \
../FreeRTOS_test1.c \
../FreeRTOS_test2.c \
../FreeRTOS_test3.c \
../FreeRTOS_test4.c \
../croutine.c \
../event_groups.c \
../heap_1.c \
../list.c \
../port.c \
../queue.c \
../regtest.c \
../stream_buffer.c \
../tasks.c \
../timers.c 

OBJS += \
./DIO_program.o \
./FreeRTOS_test1.o \
./FreeRTOS_test2.o \
./FreeRTOS_test3.o \
./FreeRTOS_test4.o \
./croutine.o \
./event_groups.o \
./heap_1.o \
./list.o \
./port.o \
./queue.o \
./regtest.o \
./stream_buffer.o \
./tasks.o \
./timers.o 

C_DEPS += \
./DIO_program.d \
./FreeRTOS_test1.d \
./FreeRTOS_test2.d \
./FreeRTOS_test3.d \
./FreeRTOS_test4.d \
./croutine.d \
./event_groups.d \
./heap_1.d \
./list.d \
./port.d \
./queue.d \
./regtest.d \
./stream_buffer.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


