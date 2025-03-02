#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef ORR_ISTR
#define ORR_ISTR

void ORR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn);

#endif