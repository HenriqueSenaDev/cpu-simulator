#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void MOV(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("MOV R%d = R%d\n", rd, rm);

  // TODO
}

void MOV_IM(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t immediate)
{
  printf("MOV R%d = #%d\n", rd, immediate);

  // TODO
}