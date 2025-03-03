#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ROR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("ROR R%d = R%d >> 1\n", rd, rm);

  uint16_t value = cpuCtxPtr->registers[rm];
  uint8_t lsb = value & 1; // 0 or 1

  cpuCtxPtr->registers[rd] = (value >> 1) | (lsb << 7);
}