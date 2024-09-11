/*
 * SSD_test.c
 *
 * Created: 9/1/2023 11:15:08 PM
 * Author : Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SSD_interface.h"


int main(void)
{
    SSD_init();
	
    while (1)
    {
		SSD_displayMultiNumber(00);
    }
}

