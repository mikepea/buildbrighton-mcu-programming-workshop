#ifndef SENDNEC_H_GUARD
#define SENDNEC_H_GUARD

#define NEC_HDR_MARK    9000
#define NEC_HDR_SPACE   4500
#define NEC_BIT_MARK    560
#define NEC_ONE_SPACE   1600
#define NEC_ZERO_SPACE  560
#define NEC_RPT_SPACE   2250

void mark(int time);
void space(int time);
void enableIROut(void);
void sendNEC(unsigned long data);

#endif
