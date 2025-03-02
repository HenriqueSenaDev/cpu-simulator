#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void NOT(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
  printf("NOT R%d = !R%d\n", rd, rm);

  cpuCtxPtr->registers[rd] = ~cpuCtxPtr->registers[rm];
  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
}
// invertendo os bits de Rm e armazenando em Rd.