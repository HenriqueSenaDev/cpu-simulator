#include <stdio.h>
#include <stdlib.h>
#include "cpu-context.h"
#include <string.h>

CPUContext *initCPU()
{
    CPUContext *cpuCtx = (CPUContext *)calloc(1, sizeof(CPUContext));

    memset(cpuCtx->registers, 0, sizeof(cpuCtx->registers));
    cpuCtx->flags = 0;

    return cpuCtx;
}

void cleanCPU(CPUContext *cpuCtx)
{
    free(cpuCtx);
    printf("CPU memory freed.\n");
}