#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ROL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("ROL R%d = R%d << 1\n", rd, rm);

  uint16_t value = cpuCtxPtr->registers[rm];
  uint8_t msb = value & 0x8000; // 0 or 1

  cpuCtxPtr->registers[rd] = (value << 1) | (msb >> 7);
}