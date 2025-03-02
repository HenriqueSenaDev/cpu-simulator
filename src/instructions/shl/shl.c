#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void SHL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint16_t immediate)
{
  printf("SHL R%d = R%d << %d\n", rd, rm, immediate);

  // TODO
}