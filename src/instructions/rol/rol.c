#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void ROL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("ROL R%d = R%d << 1\n", rd, rm);

  uint16_t value = cpuCtxPtr->registers[rm];
  uint8_t msb = (uint8_t)(value & 0x8000); // 0 or 1

  cpuCtxPtr->registers[rd] = (value << 1) | (msb >> 7);

  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
  // o carry é o bit que foi deslocado para fora do registrador, nesse caso o bit MAIS significativo antes da rotação.
  cpuCtxPtr->carry = msb;
}