/*
 * test_badge.c
 *
 * confirm our badge LED is working, by rotating R, G, B
 *
 */

#include <avr/io.h>
#include "badge.h"

unsigned long loop_counter = 0;

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
    delay_ten_us(100);
}

int main(void) {

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

    pre_loop_setup();

    while (1) {

        if ( loop_counter % 3000000 == 0 ) { 
            JUST_RED_ON;
        } else if ( loop_counter % 2000000 == 0 ) { 
            JUST_GREEN_ON;
        } else if ( loop_counter % 1000000 == 0 ) { 
            JUST_BLUE_ON;
        } else {
            ALL_RGB_OFF;
        }

        delay_ten_us(100);
        loop_counter++;

    }

    return 0;

}

