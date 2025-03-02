#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void PSH(CPUContext *cpuCtxPtr, uint8_t rn)
{
  printf("PSH [SP] = R%d; SP--\n", rn);

  // TODO
}