#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef LDR_ISTR
#define LDR_ISTR

void LDR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm);

#endif