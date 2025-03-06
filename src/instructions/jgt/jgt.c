#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JGT(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    // Imediato em complemento 2.
    int16_t offset = (immediate & 0x100)
                         ? immediate | ~0x1FF
                         : immediate;

    printf("JGT 0x%03x (PC += %d if Z=0 and C=0)\n", immediate, offset);

    if (cpuCtxPtr->zero == 0 && cpuCtxPtr->carry == 0)
    {
        cpuCtxPtr->pc += offset;
    }
}
