#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef MUL_ISTR
#define MUL_ISTR

void MUL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn);

#endif