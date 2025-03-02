#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ROL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("ROL R%d = R%d << 1\n", rd, rm);

  // TODO
}