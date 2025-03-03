#include "../../core/cpu-context.h"
#include <stdint.h>
#ifndef SHR_ISTR
#define SHR_ISTR

void SHR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t immediate);

#endif