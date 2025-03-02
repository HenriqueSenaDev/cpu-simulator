#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void MUL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("MUL R%d = R%d * R%d\n", rd, rm, rn);

  // TODO
}