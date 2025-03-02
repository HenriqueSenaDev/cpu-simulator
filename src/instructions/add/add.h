#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef ADD_ISTR
#define ADD_ISTR

void ADD(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn);

#endif