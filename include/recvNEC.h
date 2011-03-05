
#define MARK  0
#define SPACE 1

#define IR_MARK_RECEIVED   (PINB & irInMask) >> (irInPortBPin - 1) == MARK
