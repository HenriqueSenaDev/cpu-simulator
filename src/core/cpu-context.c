#include <stdio.h>
#include <stdlib.h>
#include "cpu-context.h"
#include <string.h>

CPUContext *initCPU()
{
    CPUContext *cpuCtxPtr = (CPUContext *)calloc(1, sizeof(CPUContext));

    // Generic registers initialization.
    memset(cpuCtxPtr->registers, 0, sizeof(cpuCtxPtr->registers));

    // Specific registers initialization.
    cpuCtxPtr->ir = 0;
    cpuCtxPtr->pc = 0;
    cpuCtxPtr->sp = 0x8200; // Initial SP addr.

    // Flags initialization.
    cpuCtxPtr->carry = 0;
    cpuCtxPtr->overflow = 0;
    cpuCtxPtr->zero = 0;
    cpuCtxPtr->signal = 0;

    return cpuCtxPtr;
}

void cleanCPU(CPUContext *cpuCtxPtr)
{
    free(cpuCtxPtr);
}

void printProgramMem(CPUContext *cpuCtxPtr)
{
    printf("----------- Program Memory -----------\n");

    for (int i = 0; i < MEMORY_RANGE; i++)
    {
        if (cpuCtxPtr->usedProgramMem[i])
        {
            printf(
                "Addr[0x%04x] = 0x%02x = %d\n",
                i,
                cpuCtxPtr->programMem[i],
                cpuCtxPtr->programMem[i]);
        }
    }
}

void startExecution(CPUContext *cpuCtxPtr)
{
    printf("------- Start Execution -------\n");
    endExecution(cpuCtxPtr);
}

void endExecution(CPUContext *cpuCtxPtr)
{
    printf("-------- End Execution --------\n");
    cleanCPU(cpuCtxPtr);
    printf("CPU memory freed.\n");
    printf("TODO: print cpu state.\n");
    exit(0);
}