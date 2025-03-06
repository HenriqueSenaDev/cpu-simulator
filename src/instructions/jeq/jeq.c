#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JEQ(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    // Imediato em complemento 2.
    int16_t offset = (immediate & 0x100)
                         ? immediate | ~0x1FF
                         : immediate;

    printf("JEQ 0x%03x (PC += %d if Z=1 and C=0)\n", immediate, offset);

    if (cpuCtxPtr->zero == 1 && cpuCtxPtr->carry == 0)
    {
        cpuCtxPtr->pc += offset;
    }
}
