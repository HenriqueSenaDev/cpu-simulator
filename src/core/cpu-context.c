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