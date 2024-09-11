################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
the_dio_module.lss \

FLASH_IMAGE += \
the_dio_module.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: the_dio_module.elf secondary-outputs

# Tool invocations
the_dio_module.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,the_dio_module.map -mmcu=atmega32 -o "the_dio_module.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

the_dio_module.lss: the_dio_module.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S the_dio_module.elf  >"the_dio_module.lss"
	@echo 'Finished building: $@'
	@echo ' '

the_dio_module.hex: the_dio_module.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex the_dio_module.elf  "the_dio_module.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: the_dio_module.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 the_dio_module.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) the_dio_module.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
