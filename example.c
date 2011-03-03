/*
 * blinky_without_delay.c
 *
 * Turn LED on, and off - without using sleep delays
 * 
 */

#include <avr/io.h>
#include "HSVtoRGB.h"
#include "sendNEC.h"
#include "common.h"
#include "badge.h"

unsigned int loop_counter = 0;
unsigned int second_counter = 0;

void pre_loop_setup() {
    // zero our timer controls, for now
    TCCR0A = 0;
    TCCR0B = 0;
    TCCR1 = 0;
    GTCCR = 0;

    DDRB =  (rgbMask) | ( irOutMask );

    // all PORTB output pins High (all LEDs off), except for the
    // IR LED, which is SOURCE not SINK
    PORTB = ( 0xFF & ~irOutMask );

    enableIROut();
    delay_ten_us(10);

}

int main(void) {

    pre_loop_setup();

    while (1) {

        if ( loop_counter % 100 == 0 ) {
            TURN_BLUE_ON;
            TURN_GREEN_ON;
        } else if ( loop_counter % 100 == 60 ) {
            TURN_GREEN_OFF;
        } else if ( loop_counter % 100 == 10 ) {
            TURN_BLUE_OFF;
        } 

        loop_counter++;

    }

    return 0;

}

