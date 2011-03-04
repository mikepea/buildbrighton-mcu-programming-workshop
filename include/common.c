#include <avr/io.h>
#include "common.h"

void delay_ten_us(unsigned int us) {
  unsigned int count;

  while (us != 0) {
    for (count=0; count <= 8; count++) {
            PINB |= bogusMask;
    }
    us--;
  }
}

