#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

//bst5dm el enum bdl #define lma akoon ha5od variable 3arf en kemth hatb2a values mohadada


/* Enum For Interrupt Source */
typedef enum
{
	EXTI_INT0,  // PORT_D PIN_2
	EXTI_INT1,    // PORT_D PIN_3
	EXTI_INT2     // PORT_B PIN_2
}EXTI_source;





/* Enum For Interrupt Trigger Edge */
typedef enum {
	EXTI_RISING_EDGE,           //y3ny lw ktbt de 3awd 3nha be 0
	EXTI_FALLING_EDGE,          //y3ny lw ktbt de 3awd 3nha be 1
	EXTI_LOW_LEVEL,              //y3ny lw ktbt de 3awd 3nha be 2
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_trigger;




                      /*************** APIS PROTOTYPES ***************/
			//EXTI_INT0,EXTI_INT1,EXTI_INT2    ,  falling or rising etc
void EXTI_enable (EXTI_source interruptSource, EXTI_trigger interruptTriggerEdge);
void EXTI_disable(EXTI_source interruptSource);
void TMR0_setCallBackOVF(void(*ptrToFun)(void));//the  function that will recieve the address of action func from the main module

#endif /* EXTI_INTERFACE_H_ */
