#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void NOP(CPUContext *cpuCtxPtr)
{
  printf("NOP\n");
  printState(cpuCtxPtr);
}
