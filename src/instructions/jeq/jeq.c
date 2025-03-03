#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JEQ(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    printf("JEQ %d (PC = PC + %d if Z=1 and C=0)\n", immediate, immediate);

    
    if (cpuCtxPtr->zero == 1 && cpuCtxPtr->carry == 0)
    {
        cpuCtxPtr->pc += immediate;
    }
}
