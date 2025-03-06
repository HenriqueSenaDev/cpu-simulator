#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JLT(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    // Imediato em complemento 2.
    int16_t offset = (immediate & 0x100)
                         ? immediate | ~0x1FF
                         : immediate;

    printf("JLT 0x%03x (PC += %d  if Z=0 and C=1)\n", immediate, offset);

    if (cpuCtxPtr->zero == 0 && cpuCtxPtr->carry == 1)
    {
        cpuCtxPtr->pc += offset;
    }
}
