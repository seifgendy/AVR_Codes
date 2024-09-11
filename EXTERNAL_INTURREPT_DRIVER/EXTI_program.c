

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "EXTI_interface.h"
#include "EXTI_private.h"


static void (*private_pCallBackOVF)(void);//the global variable(pointer)that eill carry the address of action funtion to put in in the isr


void EXTI_enable(EXTI_source interruptSource, EXTI_trigger interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		}
		SET_BIT(GICR,INT0); //Enable INT0
		break;
		
		case EXTI_INT1:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		}
		SET_BIT(GICR,INT1); //Enable INT1
		break;
		
		case EXTI_INT2:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2);
			break;
		}
		SET_BIT(GICR,INT2); //Enable INT2
		break;
	}
}


void EXTI_disable(EXTI_source interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,INT0); //Disable INT0
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,INT1); //Disable INT1
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,INT2); //Disable INT2
		break;
	}
}
//the  function that will recieve the address of action func from the main module
TMR0_setCallBackOVF(void(*ptrToFun)(void)){

	if(ptrToFun!=NULL){

		private_pCallBackOVF = ptrToFun ;

	}


}






void __vector_1(void) __attribute__ ((signal));  //1 is vector noumber
void __vector_1(void)
{
	if(private_pCallBackOVF!=NULL){

				private_pCallBackOVF();
}
}
