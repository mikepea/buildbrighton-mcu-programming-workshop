/*
 * blinky.c
 *
 * Turn LED on, and off - using sleep delays
 * 
 */

#include <avr/io.h>
#include "common.h"
#include "badge.h"

void pre_loop_setup() {
    initialise_registers();
}

int main(void) {

    pre_loop_setup();

    while (1) {

        JUST_RED_ON;

        delay_ten_us(10000);

        ALL_RGB_OFF;
        
        delay_ten_us(10000);

    }

    return 0;

}

