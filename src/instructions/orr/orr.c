#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ORR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("ORR R%d = R%d or R%d\n", rd, rm, rn);

  // TODO
}