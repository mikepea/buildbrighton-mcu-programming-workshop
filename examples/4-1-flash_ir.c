/*
 * 4-1-flash_ir.c
 *
 * Demonstrate receiving of IR signals from remotes
 *
 */

#include <avr/io.h>
#include "common.h"
#include "recvNEC.h"
#include "badge.h"

unsigned int loop_counter = 0;
unsigned int second_counter = 0;

void pre_loop_setup() {
    initialise_registers();
}

int main(void) {

    pre_loop_setup();

    while (1) {

        if ( IR_MARK_RECEIVED ) {
            FLASH_RED;
        } else {
            //FLASH_BLUE;
        }
        delay_ten_us(100);

    }

    return 0;

}

