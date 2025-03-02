#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef MOV_ISTR
#define MOV_ISTR

void MOV(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm);
void MOV_IM(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t immediate);

#endif