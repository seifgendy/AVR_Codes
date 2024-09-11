/*
 * FreeRTOS_test.c
 *
 * Created: 11/10/2023 8:05:57 PM
 * Author : Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"

// Tasks Prototypes
void LED_On(void* copy_pvParamter);
void LED_Off(void* copy_pvParamter);


int main(void)
{
	/* Initialization */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	/* Create Tasks */
	xTaskCreate(&LED_On, (const char*)"Task_1",100,NULL,1,NULL);
	xTaskCreate(&LED_Off,(const char*)"Task_2",100,NULL,3,NULL);
	
	/* Start FreeRTOS*/
	vTaskStartScheduler();
	
	/* Never Enter Here*/
    while (1) 
    {
    }
}


void LED_On(void* copy_pvParamter)
{
	while(1)
	{
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
	}
}


void LED_Off(void* copy_pvParamter)
{
	vTaskDelay(2000);
	while(1)
	{
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
	}
}

