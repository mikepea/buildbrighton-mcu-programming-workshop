
// chip specifics
// tiny45
#define EEPROM_SIZE 256
// tiny25
//#define EEPROM_SIZE 128

#define SYSCLOCK 8000000  // main clock speed

// PORTB masks - for BBadge design (change for TrippyRGB wave board)
#define redMask      0b00000100
#define grnMask      0b00000010
#define bluMask      0b00000001
#define rgbMask      0b00000111
#define irInMask     0b00001000
#define irOutMask    0b00010000
// 4 = PB3
#define irInPortBPin  4

#define ALL_RGB_OFF      PORTB |= rgbMask;

#define JUST_RED_ON      PORTB |= rgbMask; PORTB ^= redMask;
#define TURN_RED_ON      PORTB &= ~(redMask);
#define TURN_RED_OFF     PORTB |= redMask;

#define JUST_GREEN_ON    PORTB |= rgbMask; PORTB ^= grnMask;
#define TURN_GREEN_ON    PORTB &= ~(grnMask);
#define TURN_GREEN_OFF   PORTB |= grnMask;

#define JUST_BLUE_ON     PORTB |= rgbMask; PORTB ^= bluMask;
#define TURN_BLUE_ON     PORTB &= ~(bluMask);
#define TURN_BLUE_OFF    PORTB |= bluMask;

#define FLASH_RED       PORTB ^= redMask; delay_ten_us(100); PORTB ^= redMask;
#define FLASH_GREEN     PORTB ^= grnMask; delay_ten_us(100); PORTB ^= grnMask;
#define FLASH_BLUE      PORTB ^= bluMask; delay_ten_us(100); PORTB ^= bluMask;

