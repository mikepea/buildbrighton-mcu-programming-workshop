/*
 * blinky.c
 *
 */


#include <avr/io.h>

void delay_ten_us(unsigned int us) {
  unsigned int count;

  while (us != 0) {
    for (count=0; count <= 8; count++) {
            PINB |= bogusMask;
    }
    us--;
  }
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

        main_loop_counter++;

    }

    return 0;

}
