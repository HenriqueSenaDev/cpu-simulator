#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void LDR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("LDR R%d = [R%d]\n", rd, rm);

  // TODO
}