
/*
 * SSD_program.c
 *
 * Created: 9/1/2023 11:16:02 PM
 *  Author: Kareem Hussein
 */


#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"

/* HAL */
#include "SSD_interface.h"


void SSD_init(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
}


void SSD_displayNumber(u8 ssdId,u8 desiredNumber)
{
	if(((ssdId==SSD_ONE)||(ssdId==SSD_TWO))&&(desiredNumber<=9))
	{
		PORTA = (PORTA&0x0f)|(desiredNumber<<4);

		switch(ssdId)
		{
			case SSD_ONE:
			DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
			break;

			case SSD_TWO:
			DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
			break;
		}
	}
}


void SSD_displayMultiNumber(u8 desiredNumber)
{
	if(desiredNumber<=99)
	{
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		PORTA = (PORTA&0x0f)|((desiredNumber/10)<<4);
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		PORTA = (PORTA&0x0f)|((desiredNumber%10)<<4);
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	}
}
