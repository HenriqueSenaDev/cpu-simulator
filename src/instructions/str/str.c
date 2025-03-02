#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void STR(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t rn)
{
  printf("STR [R%d] = R%d\n", rm, rn);

  // TODO
}

void STR_IM(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t immediate)
{
  printf("STR [R%d] = #%d\n", rm, immediate);

  // TODO
}