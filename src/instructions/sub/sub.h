#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef SUB_ISTR
#define SUB_ISTR

void SUB(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn);

#endif