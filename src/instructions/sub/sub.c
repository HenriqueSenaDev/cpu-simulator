#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void SUB(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("SUB R%d = R%d - R%d\n", rd, rm, rn);

  uint16_t vRm = cpuCtxPtr->registers[rm];
  uint16_t vRn = cpuCtxPtr->registers[rn];
  uint32_t result = vRm - vRn;
  cpuCtxPtr->registers[rd] = (uint16_t) result;
  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
  cpuCtxPtr->carry = (vRn > vRm);
  cpuCtxPtr->overflow = ((vRm & 0x8000)!=(vRn & 0x8000) && (cpuCtxPtr->registers[rd] & 0x8000)!=(vRm & 0x8000));
}