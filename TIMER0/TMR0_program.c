/*
 * TMR0_program.c
 *
 * Created: 9/9/2023 10:55:55 PM
 *  Author: Kareem Hussein
 */


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"
#include "TMR0_private.h"

static void (*private_pCallBackOVF)(void);//the global variable(pointer)that eill carry the address of action funtion to put in in the isr

void TMR0_init(void)
{
	// Select Mode = Normal Mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	// Init Timer With Preload Value
	TCNT0 = TMR0_PRELOAD_VALUE;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,TOIE0);
}


void TMR0_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}


void TMR0_stop(void)
{
	// Select Prescaler Value = 0
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

//the  function that will recieve the address of action func from the main module
TMR0_setCallBackOVF(void(*ptrToFun)(void)){

	if(ptrToFun!=NULL){

		private_pCallBackOVF = ptrToFun ;

	}


}






void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	static u16 OvfCounter = 0;
	OvfCounter++;

	if(TMR0_OVER_FLOW_COUNTER == OvfCounter)
	{
		// Set Preload Value
		TCNT0 = TMR0_PRELOAD_VALUE;

		// Clear Counter
		OvfCounter = 0;

		//call action
		if(private_pCallBackOVF!=NULL){

			private_pCallBackOVF();


		}

	}
}



