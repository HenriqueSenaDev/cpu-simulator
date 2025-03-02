#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void AND(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("AND R%d = R%d and R%d\n", rd, rm, rn);

  // TODO
}