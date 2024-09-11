/*
 * WDT_program.c
 *
 * Created: 9/23/2023 11:40:45 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "WDT_interface.h"
#include "WDT_private.h"


void WDT_Start(void)
{
	// Select Prescaler Value >>> 2.1s
	SET_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);
	
	// Enable WDT
	SET_BIT(WDTCR,WDE);
}


void WDT_Stop(void)
{
	// Write logical one to WDTOE and WDE 
	WDTCR = (1<<WDTOE) | (1<<WDE);
	
	// Disable WDT
	WDTCR = 0x00;
}