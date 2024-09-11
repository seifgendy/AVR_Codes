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
#include "TMR0_config.h"
#include "TMR0_private.h"
#include "DIO_interface.h"
#include "GI_interface.h"

void action(void);

int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT); //LED2>>O/P
	GI_enable();
	TMR0_init();
	TMR0_setCallBackOVF(&action);
	TMR0_start();
    while (1)
    {
    }
}


//the action function that do that carry or do the action called by isr

void action(void)
{

	DIO_togglePinValue(DIO_PORTD,DIO_PIN3);
}




