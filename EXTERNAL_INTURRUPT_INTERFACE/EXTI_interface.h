



#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/* Enum For Interrupt Source */
typedef enum
{
	EXTI_INT0=0,  // PORT_D PIN_2
	EXTI_INT1,    // PORT_D PIN_3
	EXTI_INT2     // PORT_B PIN_2
}EXTI_source;

/* Enum For Interrupt Trigger Edge */
typedef enum {
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_trigger;


                      /*************** APIS PROTOTYPES ***************/
					  
void EXTI_enable (EXTI_source interruptSource, EXTI_trigger interruptTriggerEdge);
void EXTI_disable(EXTI_source interruptSource);


#endif /* EXTI_INTERFACE_H_ */
