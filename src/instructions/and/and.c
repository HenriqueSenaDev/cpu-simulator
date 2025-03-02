#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void AND(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("AND R%d = R%d and R%d\n", rd, rm, rn);

  cpuCtxPtr->registers[rd] = cpuCtxPtr->registers[rm] & cpuCtxPtr->registers[rn];
  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
}
// Compara os bits de Rm e Rn, o resultado (Rd) recebe 1 quando os bits de Rm e Rn são 1 e 0 caso contrário.