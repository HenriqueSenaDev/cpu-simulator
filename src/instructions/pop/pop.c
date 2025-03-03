#include "../../core/cpu-context.h"
#include "../../utils/numeric.h"
#include <stdint.h>
#include <stdio.h>

void POP(CPUContext *cpuCtxPtr, uint8_t rd)
{
  printf("POP R%d\n", rd);

  cpuCtxPtr->sp += 2;

  uint8_t msByte = cpuCtxPtr->dataMem[cpuCtxPtr->sp + 1];
  uint8_t lsByte = cpuCtxPtr->dataMem[cpuCtxPtr->sp];

  cpuCtxPtr->dataMem[cpuCtxPtr->sp + 1] = 0;
  cpuCtxPtr->dataMem[cpuCtxPtr->sp] = 0;

  uint8_t *msByteBits = decimalToBinary(msByte);
  uint8_t *lsByteBits = decimalToBinary(lsByte);

  uint8_t totalBits[16] = {
      msByteBits[0],
      msByteBits[1],
      msByteBits[2],
      msByteBits[3],
      msByteBits[4],
      msByteBits[5],
      msByteBits[6],
      msByteBits[7],
      msByteBits[0],
      lsByteBits[1],
      lsByteBits[2],
      lsByteBits[3],
      lsByteBits[4],
      lsByteBits[5],
      lsByteBits[6],
      lsByteBits[7],
  };

  uint16_t *value = binaryToDecimal(totalBits, 0, 15);
  cpuCtxPtr->registers[rd] = *value;
}