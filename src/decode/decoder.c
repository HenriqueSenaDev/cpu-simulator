#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../core/cpu-context.h"
#include "../utils/numeric.h"
#include "../instructions/nop/nop.h"
#include "../instructions/halt/halt.h"

// Receives 16 bits array
void decodeAndExecute(CPUContext *cpuCtxPtr)
{
  uint16_t instruction = cpuCtxPtr->ir;

  if (instruction == 0)
    return NOP(cpuCtxPtr);

  if (instruction == 65535)
    return HALT(cpuCtxPtr);

  // Instruction 16 bits.
  uint8_t *bitsArr = decimalToBinary(instruction);

  printf("Unmapped instruction.\n");
}