#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JMP(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    printf("JMP %d (PC = PC + %d)\n", immediate, immediate);

    // atualiza o contador de programa 
    cpuCtxPtr->pc += immediate;
}
