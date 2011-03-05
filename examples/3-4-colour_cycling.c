/*
 *
 *
 *
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

    const int seq_length = 10;
    int red_seq[10] =   { 10, 55, 88, 22, 255, 255, 255, 12, 0, 0 };
    int blue_seq[10] =  { 10, 55, 88, 22, 255, 255, 255, 0, 66, 0 };
    int green_seq[10] = { 88,  5, 88, 5, 0, 255, 255, 0, 0, 15 };
    int i=0;

    while (1) {

        if ( loop_counter > 10000 ) {
            second_counter++;
            loop_counter = 0;
            i = (i<(seq_length-1)) ? i+1 : 0; // make sure i = 0..9
        }

        display_colour(loop_counter % 256, red_seq[i], green_seq[i], blue_seq[i]);
        delay_ten_us(5);

        loop_counter++;

    }

    return 0;

}

