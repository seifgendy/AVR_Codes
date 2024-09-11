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


static u8 flag=0;
// Tasks Prototypes
void LED_0(void* copy_pvParamter);
void SW_0(void* copy_pvParamter);

int main(void)
{
	/* Initialization */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_INPUT);
	
	
	/* Create Tasks */
	xTaskCreate(&LED_0, (const char*)"Task_1",100,NULL,1,NULL);
	xTaskCreate(&SW_0,  (const char*)"Task_2",100,NULL,2,NULL);
	
	
	/* Start FreeRTOS*/
	vTaskStartScheduler();
	
	/* Never Enter Here*/
    while (1) 
    {
    }
}


void LED_0(void* copy_pvParamter)
{
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		if(flag == 1)
		{
			DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
			flag = 0;
		}
		/* Make the Task Periodic with Period 50 Tick */
		xTaskDelayUntil(&xLastWakeTime,pdMS_TO_TICKS(100));
	}
}


void SW_0(void* copy_pvParamter)
{
	u8 Local_u8Sw0;
	TickType_t xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		vTaskDelay(100);
		DIO_getPinValue(DIO_PORTB,DIO_PIN0,&Local_u8Sw0);
		
		if (Local_u8Sw0 == 1)
		{
			flag = 1;
		}
		/* Make the Task Periodic with Period 50 Tick */
		xTaskDelayUntil(&xLastWakeTime,pdMS_TO_TICKS(100));
	}
}