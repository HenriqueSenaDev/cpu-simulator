#include "../../core/cpu-context.h"
#include <stdio.h>

void HALT(CPUContext *cpuCtxPtr)
{
    printf("HALT - Parando a execução da CPU\n");
    endExecution(cpuCtxPtr); 
}
