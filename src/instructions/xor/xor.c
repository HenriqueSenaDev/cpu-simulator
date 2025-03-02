#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void XOR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("XOR R%d = R%d xor R%d\n", rd, rm, rn);

  cpuCtxPtr->registers[rd] = cpuCtxPtr->registers[rm] ^ cpuCtxPtr->registers[rn];
  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
}
// Compara os bits de Rm e Rn, o resultado (Rd) recebe 1 quando os bits comparados de Rm e Rn são diferentes e 0 caso contrário.