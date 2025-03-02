#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void XOR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t rn)
{
  printf("XOR R%d = R%d xor R%d\n", rd, rm, rn);

  // TODO
}