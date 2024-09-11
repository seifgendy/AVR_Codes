/*
 * TMR1_test.c
 *
 * Created: 9/23/2023 8:59:04 PM
 * Author : Kareem Hussein
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR1_interface.h"
#include "DIO_interface.h"


int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT); //OC1A >> O/P
	TMR1_init();
	TMR1_setFastPWM_usingMode14(7.5,50);
	TMR1_start();
    while (1) 
    {
    }
}

