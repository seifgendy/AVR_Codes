#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB0

int main(void) {
    // Set PB0 as output
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Toggle PB0
        PINB |= (1 << LED_PIN);
        _delay_ms(500);

        // Toggle PB0
        PINB &= ~(1 << LED_PIN);
        _delay_ms(500);
    }

    return 0;
}