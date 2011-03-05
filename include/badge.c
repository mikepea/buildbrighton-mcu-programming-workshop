#include <avr/io.h>
#include "badge.h"

void initialise_registers() {

    // zero our timer controls, for now
    TCCR0A = 0;
    TCCR0B = 0;
    TCCR1 = 0;
    GTCCR = 0;

    DDRB =  (rgbMask) | ( irOutMask );

    // all PORTB output pins High (all LEDs off), except for the
    // IR LED, which is SOURCE not SINK
    PORTB = ( 0xFF & ~irOutMask );
                    // -- (if we set an input pin High it activates a
                    // pull-up resistor, which we don't need, but don't care about either)

}


void display_colour(uint8_t tick, int r, int g, int b) {

    if ((r > tick) && ( tick % 5 == 0) ) {
        TURN_RED_ON;
    } else {
        TURN_RED_OFF;
    }

    if ((g > tick) && ( tick % 5 == 0)) {
        TURN_GREEN_ON;
    } else {
        TURN_GREEN_OFF;
    }

    if ((b > tick) && ( tick % 2 == 0)) {
        TURN_BLUE_ON;
    } else {
        TURN_BLUE_OFF;
    }

}

