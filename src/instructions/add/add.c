#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ADD(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("ADD R%d = R%d + R%d\n", rd, rm, rn);

  // TODO
}