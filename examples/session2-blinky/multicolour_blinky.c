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

        if ( loop_counter % 1000 == 0 ) {
            TURN_RED_ON;
        } else if ( loop_counter % 1000 == 300 ) {
            TURN_RED_OFF;
        } else if ( loop_counter % 1000 == 200 ) {
            TURN_GREEN_ON;
        } else if ( loop_counter % 1000 == 500 ) {
            TURN_GREEN_ON;
        } else if ( loop_counter % 1000 == 400 ) {
            TURN_BLUE_ON;
        } else if ( loop_counter % 1000 == 700 ) {
            TURN_BLUE_OFF;
        } else  if ( loop_counter % 1000 == 900 ) {
            ALL_RGB_OFF;
        }

        // sleep a little bit, just to give CPU a rest
        delay_ten_us(100);

        loop_counter++;

    }

    return 0;

}

