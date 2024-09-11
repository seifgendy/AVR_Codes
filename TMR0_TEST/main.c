/*
 * TMR0_test.c
 *
 * Created: 9/9/2023 10:53:57 PM
 * Author : Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "DIO_interface.h"
#include "GI_interface.h"

void action(void);


int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT); //LED0>>O/P
	GI_enable();
	TMR0_init();
	TMR0_setDelay_ms_usingCTC(2000);
	TMR0_setCallBackCTC(&action);
	TMR0_start();
    while (1) 
    {
    }
}


void action(void)
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
}