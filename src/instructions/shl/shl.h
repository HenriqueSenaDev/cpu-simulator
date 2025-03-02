#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef SHL_ISTR
#define SHL_ISTR

void SHL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint16_t immediate);

#endif