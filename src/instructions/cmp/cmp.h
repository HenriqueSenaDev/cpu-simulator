#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef CMP_ISTR
#define CMP_ISTR

void CMP(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t rn);

#endif