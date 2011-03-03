#include <avr/io.h>
#include "common.h"
#include "sendNEC.h"

void mark(int time) {
  // Sends an IR mark for the specified number of microseconds.
  // The mark output is modulated at the PWM frequency.
  GTCCR |= _BV(COM1B0);  // turn on OC1B PWM output
  delay_ten_us(time / 10);
}

/* Leave pin off for time (given in microseconds) */
void space(int time) {
  // Sends an IR space for the specified number of microseconds.
  // A space is no output, so the PWM output is disabled.
  GTCCR &= ~(_BV(COM1B0));  // turn on OC1B PWM output
  delay_ten_us(time / 10);
}

void enableIROut(void) {

  TCCR1 = _BV(CS10);  // turn on clock, prescale = 1
  GTCCR = _BV(PWM1B) | _BV(COM1B0);  // toggle OC1B on compare match; PWM mode on OCR1C/B.

  // these two values give 38khz PWM on IR LED, with 33%ish duty cycle
  OCR1C = 210;
  OCR1B = 70;

}

void sendNEC(unsigned long data)
{
#ifndef DISABLE_IR_SENDING_CODE
    // handle turning on an approximation of our colour,
    // as RGB PWM is off during IR sending.

    mark(NEC_HDR_MARK);
    space(NEC_HDR_SPACE);

    for (uint8_t i = 0; i < 32; i++) {
        if (data & 1) {
            mark(NEC_BIT_MARK);
            space(NEC_ONE_SPACE);
        } else {
            mark(NEC_BIT_MARK);
            space(NEC_ZERO_SPACE);
        }
        data >>= 1;
    }
    mark(NEC_BIT_MARK);
    space(0);
#endif
}

