#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void POP(CPUContext *cpuCtxPtr, uint8_t rd)
{
  printf("SP++; R%d = [SP]\n", rd);

  // TODO
}