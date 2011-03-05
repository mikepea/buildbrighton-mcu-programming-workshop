/*
 * blinky_without_delay.c
 *
 * Turn LED on, and off - without using sleep delays
 * 
 */

#include <avr/io.h>
#include "badge.h"

unsigned int loop_counter = 0;
unsigned int second_counter = 0;

void delay_ten_us(unsigned int us) {
  unsigned int count;

  while (us != 0) {
    for (count=0; count <= 8; count++) {
            PINB |= bogusMask;
    }
    us--;
  }
}

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

}

int main(void) {

    pre_loop_setup();

    while (1) {

        if ( loop_counter % 100 == 0 ) {
            TURN_RED_ON;
        } else if ( loop_counter % 100 == 30 ) {
            TURN_RED_OFF;
        } 

        loop_counter++;

    }

    return 0;

}

