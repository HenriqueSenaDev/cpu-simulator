#include <stdio.h>
#include <stdlib.h>
#include "cpu-context.h"

CPUContext *initCPU()
{
    CPUContext *cpuCtx = (CPUContext *)calloc(1, sizeof(CPUContext));

    return cpuCtx;
}

void cleanCPU(CPUContext *cpuCtx)
{
    free(cpuCtx);
    printf("CPU memory freed.\n");
}