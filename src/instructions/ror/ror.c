#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ROR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("ROR R%d = R%d >> 1\n", rd, rm);

  // TODO
}