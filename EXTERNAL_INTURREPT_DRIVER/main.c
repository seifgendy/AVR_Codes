


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "EXTI_interface.h"
#include "DIO_interface.h"

void action(void);
int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT); //LED0 >> O/P
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);  //INT0 >> I/P
	TMR0_setCallBackOVF(&action);
	// Enable Global Interrupt
	#define SREG          (*(volatile u8*)0x5F)
	#define I             7
	SET_BIT(SREG,I);

	EXTI_enable(EXTI_INT0,EXTI_FALLING_EDGE);
    while (1)
    {
    }
}




//the action function that do that carry or do the action called by isr

void action(void)
{

	DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
}

