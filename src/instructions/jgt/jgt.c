#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JGT(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    printf("JGT %d (PC = PC + %d if Z=0 and C=0)\n", immediate, immediate);

    if (cpuCtxPtr->zero == 0 && cpuCtxPtr->carry == 0)
    {
        cpuCtxPtr->pc += immediate;
    }
}
