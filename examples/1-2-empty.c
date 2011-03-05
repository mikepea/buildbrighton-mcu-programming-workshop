/*
 * my_code.c
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

    while (1) {

        delay_ten_us(100);

    }

    return 0;

}

