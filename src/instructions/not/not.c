#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void NOT(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("NOT R%d = !R%d\n", rd, rm);

  // TODO
}