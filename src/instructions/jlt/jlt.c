#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JLT(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    printf("JLT %d (PC = PC + %d if Z=0 and C=1)\n", immediate, immediate);

    if (cpuCtxPtr->zero == 0 && cpuCtxPtr->carry == 1)
    {
        cpuCtxPtr->pc += immediate;
    }
}
