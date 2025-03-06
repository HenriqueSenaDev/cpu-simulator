#include "../../core/cpu-context.h"
#include <stdio.h>

void HALT(CPUContext *cpuCtxPtr)
{
    printf("HALT\n");
    endExecution(cpuCtxPtr);
}
