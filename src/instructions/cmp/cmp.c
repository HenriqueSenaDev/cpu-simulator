#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void CMP(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t rn)
{
  printf("CMP R%d, R%d\n", rm, rn);

  uint16_t vRm = cpuCtxPtr->registers[rm];
  uint16_t vRn = cpuCtxPtr->registers[rn];
  cpuCtxPtr->zero = vRm == vRn;
  cpuCtxPtr->signal = (vRm < vRn);
}
// Compara os bits de Rm e Rn, atualizando os flags de acordo com o resultado da comparação.
