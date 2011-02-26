
// chip specifics
// tiny45
#define EEPROM_SIZE 256
// tiny25
//#define EEPROM_SIZE 128

#define SYSCLOCK 8000000  // main clock speed

// PORTB masks - for BBadge design (change for TrippyRGB wave board)
#define bogusMask    0b00100000
#define redMask      0b00000100
#define grnMask      0b00000010
#define bluMask      0b00000001
#define rgbMask      0b00000111
#define irInMask     0b00001000
#define irOutMask    0b00010000
// 4 = PB3
#define irInPortBPin  4

#define JUST_RED_ON      PORTB |= rgbMask; PORTB &= ~(redMask);
#define JUST_GREEN_ON    PORTB |= rgbMask; PORTB &= ~(grnMask);
#define JUST_BLUE_ON     PORTB |= rgbMask; PORTB &= ~(bluMask);

#define FLASH_BLUE      PORTB ^= bluMask; delay_ten_us(100); PORTB ^= bluMask;
#define FLASH_GREEN     PORTB ^= grnMask; delay_ten_us(100); PORTB ^= grnMask;
#define FLASH_RED       PORTB ^= redMask; delay_ten_us(100); PORTB ^= redMask;



