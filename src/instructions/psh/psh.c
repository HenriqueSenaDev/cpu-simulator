#include "../../core/cpu-context.h"
#include "../../utils/numeric.h"
#include <stdint.h>
#include <stdio.h>

void PSH(CPUContext *cpuCtxPtr, uint8_t rn)
{
  printf("PSH R%d\n", rn);

  uint16_t value = cpuCtxPtr->registers[rn];

  uint8_t *bitsPtr = decimalToBinary(value);
  uint8_t msByte = (uint8_t)*(binaryToDecimal(bitsPtr, 0, 7));
  uint8_t lsByte = (uint8_t)*(binaryToDecimal(bitsPtr, 8, 15));

  cpuCtxPtr->dataMem[cpuCtxPtr->sp + 1] = msByte;
  cpuCtxPtr->dataMem[cpuCtxPtr->sp] = lsByte;

  cpuCtxPtr->sp -= 2;
}