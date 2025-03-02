#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef AND_ISTR
#define AND_ISTR

void AND(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn);

#endif