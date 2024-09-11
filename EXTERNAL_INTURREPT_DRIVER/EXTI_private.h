

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


                          /* EXTERNAL INTERRUPT REGISTERS */

// MCU Control Register
#define MCUCR          (*(volatile u8*)0x55)
#define ISC00          0         //the bits of each register as written in data sheet
#define ISC01          1         //the bits of each register as written in data sheet
#define ISC10          2         //the bits of each register as written in data sheet
#define ISC11          3         //the bits of each register as written in data sheet

// MCU Control and Status Register
#define MCUCSR         (*(volatile u8*)0x54)
#define ISC2           6     //the bits of each register as written in data sheet

// General Interrupt Control Register
#define GICR           (*(volatile u8*)0x5B)
#define INT0            6   //the bits of each register as written in data sheet
#define INT1            7   //the bits of each register as written in data sheet
#define INT2            5   //the bits of each register as written in data sheet

// General Interrupt Flag Register
#define GIFR           (*(volatile u8*)0x5A)
#define INTF0          6     //the bits of each register as written in data sheet
#define INTF1          7     //the bits of each register as written in data sheet
#define INTF2          5     //the bits of each register as written in data sheet



#endif /* EXTI_PRIVATE_H_ */
