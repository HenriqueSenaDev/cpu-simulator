#include "../../core/cpu-context.h"
#include "../../utils/numeric.h"
#include <stdint.h>
#include <stdio.h>

void STR(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t rn)
{
  printf("STR [R%d] = R%d\n", rm, rn);

  uint16_t addr = cpuCtxPtr->registers[rm];
  uint16_t value = cpuCtxPtr->registers[rn];

  uint8_t *bitsPtr = decimalToBinary(value);

  uint8_t msByte = (uint8_t)*(binaryToDecimal(bitsPtr, 0, 7));
  uint8_t lsByte = (uint8_t)*(binaryToDecimal(bitsPtr, 8, 15));

  cpuCtxPtr->dataMem[addr + 1] = msByte;
  cpuCtxPtr->dataMem[addr] = lsByte;
  cpuCtxPtr->usedDataMem[addr + 1] = true;
  cpuCtxPtr->usedDataMem[addr] = true;
}

void STR_IM(CPUContext *cpuCtxPtr, uint8_t rm, uint8_t immediate)
{
  printf("STR [R%d] = #%d\n", rm, immediate);

  uint16_t addr = cpuCtxPtr->registers[rm];

  cpuCtxPtr->dataMem[addr] = immediate;
  cpuCtxPtr->usedDataMem[addr] = true;
}