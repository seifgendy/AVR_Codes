/*
 * STPM_test.c
 *
 * Created: 10/20/2023 11:37:48 PM
 * Author : AMIT
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"


int main(void)
{
    DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	u16 counter;
    while (1) 
    {
		for(counter=0;counter<514;counter++)
		{
			 DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
			 DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			 DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			 DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			 _delay_ms(10);
			 
			  DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			  DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
			  DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			  DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			  _delay_ms(10);
			  
			   DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			   DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			   DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
			   DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
			   _delay_ms(10);
			   
			    DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
			    DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
			    DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
			    DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
			    _delay_ms(10);
		}
    }
}

