/*
 * test_badge.c
 *
 * confirm our badge LED is working, by rotating R, G, B
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

        if ( loop_counter > 1000 ) {
            second_counter++;
            loop_counter = 0;
        }

        if ( second_counter % 6 == 0 ) { 
            JUST_RED_ON;
        } else if ( second_counter % 6 == 2 ) { 
            JUST_GREEN_ON;
        } else if ( second_counter % 6 == 4 ) { 
            JUST_BLUE_ON;
        } else {
            ALL_RGB_OFF;
        }

        delay_ten_us(100);
        loop_counter++;

    }

    return 0;

}

