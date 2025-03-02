#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef ROR_ISTR
#define ROR_ISTR

void ROR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm);

#endif