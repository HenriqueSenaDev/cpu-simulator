#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef XOR_ISTR
#define XOR_ISTR

void XOR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn);

#endif