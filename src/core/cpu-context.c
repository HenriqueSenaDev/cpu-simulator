#include <stdio.h>
#include <stdlib.h>
#include "cpu-context.h"
#include <string.h>

CPUContext *initCPU()
{
    CPUContext *cpuCtx = (CPUContext *)calloc(1, sizeof(CPUContext));

    memset(cpuCtx->registers, 0, sizeof(cpuCtx->registers));
    cpuCtx->carry = 0;
    cpuCtx->overflow = 0;
    cpuCtx->zero = 0;
    cpuCtx->signal = 0;

    return cpuCtx;
}

void cleanCPU(CPUContext *cpuCtx)
{
    free(cpuCtx);
}

void printCPUState(CPUContext *cpuCtx)
{
    printf("------------ CPU State ------------\n");

    // Program memory
    for (int i = 0; i < MEMORY_RANGE; i++)
    {
        if (cpuCtx->usedProgramMem[i])
            printf("Memória[%d] = %02x\n", i, cpuCtx->programMem[i]);
    }

    // TODO: Data memory
    // TODO: Generic registers
    // TODO: Specific registers
    // TODO: Flags

    printf("-----------------------------------\n");
}
