#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef JMP_ISTR
#define JMP_ISTR

void JMP(CPUContext *cpuCtxPtr, uint16_t immediate);

#endif