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

void printProgramMem(CPUContext *cpuCtx)
{
    printf("----------- Program Memory -----------\n");

    for (int i = 0; i < MEMORY_RANGE; i++)
    {
        if (cpuCtx->usedProgramMem[i])
        {
            printf(
                "Addr[0x%04x] = 0x%02x = %d\n",
                i,
                cpuCtx->programMem[i],
                cpuCtx->programMem[i]);
        }
    }

    printf("-----------------------------------\n");
}
