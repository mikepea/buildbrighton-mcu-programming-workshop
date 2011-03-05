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

        display_colour(loop_counter % 256, 0, 70, 20);
        delay_ten_us(5);

        loop_counter++;

    }

    return 0;

}

