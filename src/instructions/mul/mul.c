#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void MUL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("MUL R%d = R%d * R%d\n", rd, rm, rn);

  uint16_t vRm = cpuCtxPtr->registers[rm];
  uint16_t vRn = cpuCtxPtr->registers[rn];
  uint32_t result = vRm * vRn;
  cpuCtxPtr->registers[rd] = (uint16_t) result;
  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (result & 0x8000) != 0;
  cpuCtxPtr->overflow = result > 0xFFFF;
}