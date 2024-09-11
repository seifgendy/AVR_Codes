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
void LED_0(void* copy_pvParamter);
void LED_1(void* copy_pvParamter);
void LED_2(void* copy_pvParamter);
void BUZZER(void* copy_pvParamter);

int main(void)
{
	/* Initialization */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	
	/* Create Tasks */
    xTaskCreate(&LED_0, (const char*)"Task_1",100,NULL,0,NULL);
	xTaskCreate(&LED_1, (const char*)"Task_2",100,NULL,1,NULL);
	xTaskCreate(&LED_2, (const char*)"Task_3",100,NULL,2,NULL);
	xTaskCreate(&BUZZER,(const char*)"Task_4",100,NULL,3,NULL);
	
	/* Start FreeRTOS*/
	vTaskStartScheduler();
	
	/* Never Enter Here*/
    while (1) 
    {
    }
}

// Task_1 Code
void LED_0(void* copy_pvParamter)
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
		vTaskDelay(500);
	}
}

// Task_2 Code
void LED_1(void* copy_pvParamter)
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTC,DIO_PIN7);
		vTaskDelay(1000);
	}
}

// Task_3 Code
void LED_2(void* copy_pvParamter)
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTD,DIO_PIN3);
		vTaskDelay(2000);
	}
}

// Task_4 Code
void BUZZER(void* copy_pvParamter)
{
	while(1)
	{
		DIO_togglePinValue(DIO_PORTA,DIO_PIN3);
		vTaskDelay(250);
	}
}
