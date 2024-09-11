

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "UART_interface.h"

int main() {

	 DIO_setPinDirection(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT); //SET TX PIN AS OUTPUT
	 DIO_setPinDirection(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT); // SET RX PIN AS INPUT
     UART_init();
     UART_TxChar('D');

    while (1) {






    }

    return 0;
}
