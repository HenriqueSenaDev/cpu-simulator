#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef STR_ISTR
#define STR_ISTR

void STR(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t rn);
void STR_IM(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t immediate);

#endif