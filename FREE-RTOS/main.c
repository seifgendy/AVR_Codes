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

/* */
#include "LCD_interface.h"

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// Tasks Prototypes
void Task_1(void* copy_pvParamter);
void Task_2(void* copy_pvParamter);

SemaphoreHandle_t LCD_KEY;

int main(void)
{
	/* Initialization */
	//DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	//DIO_setPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_INPUT);
	
	LCD_init();
	
	vSemaphoreCreateBinary(LCD_KEY);
	//xSemaphoreCreateCounting(1,1);
	
	/* Create Tasks */
	xTaskCreate(&Task_1,(const char*)"Task_1",300,NULL,2,NULL);
	xTaskCreate(&Task_2,(const char*)"Task_2",300,NULL,2,NULL);
	
	
	/* Start FreeRTOS*/
	vTaskStartScheduler();
	
	/* Never Enter Here*/
    while (1) 
    {
    }
}


void Task_1(void* copy_pvParamter)
{
	while(1)
	{
		if(pdTRUE == xSemaphoreTake(LCD_KEY,0))
		{
			LCD_writeString((u8*)"Iam Task_1");
			xSemaphoreGive(LCD_KEY);
		}
		vTaskDelay(50);
	}
	
}


void Task_2(void* copy_pvParamter)
{
	while(1)
	{
			if (pdTRUE == xSemaphoreTake(LCD_KEY,0))
			{
				LCD_writeString((u8*)"Iam Task_2");
				xSemaphoreGive(LCD_KEY);
			}
		vTaskDelay(50);
	}
	
}