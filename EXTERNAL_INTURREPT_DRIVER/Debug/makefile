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
EXTERNAL_INTURREPT_DRIVER.lss \

FLASH_IMAGE += \
EXTERNAL_INTURREPT_DRIVER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: EXTERNAL_INTURREPT_DRIVER.elf secondary-outputs

# Tool invocations
EXTERNAL_INTURREPT_DRIVER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EXTERNAL_INTURREPT_DRIVER.map -mmcu=atmega32 -o "EXTERNAL_INTURREPT_DRIVER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EXTERNAL_INTURREPT_DRIVER.lss: EXTERNAL_INTURREPT_DRIVER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EXTERNAL_INTURREPT_DRIVER.elf  >"EXTERNAL_INTURREPT_DRIVER.lss"
	@echo 'Finished building: $@'
	@echo ' '

EXTERNAL_INTURREPT_DRIVER.hex: EXTERNAL_INTURREPT_DRIVER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex EXTERNAL_INTURREPT_DRIVER.elf  "EXTERNAL_INTURREPT_DRIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EXTERNAL_INTURREPT_DRIVER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 EXTERNAL_INTURREPT_DRIVER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EXTERNAL_INTURREPT_DRIVER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
