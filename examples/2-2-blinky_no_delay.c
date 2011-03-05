/*
 * blinky_without_delay.c
 *
 * Turn LED on, and off - without using sleep delays
 * 
 */

#include <avr/io.h>
#include "common.h"
#include "badge.h"

unsigned int loop_counter = 0;
unsigned int second_counter = 0;

void pre_loop_setup() {
    initialise_registers();
}

int main(void) {

    pre_loop_setup();

    while (1) {

        if ( loop_counter % 1000 == 0 ) {
            JUST_RED_ON;
        } else if ( loop_counter % 1000 == 500 ) {
            ALL_RGB_OFF;
        }

        // sleep a little bit, just to give CPU a rest
        delay_ten_us(100);

        loop_counter++;

    }

    return 0;

}

