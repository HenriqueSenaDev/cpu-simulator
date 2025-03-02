#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../core/cpu-context.h"
#include "../utils/numeric.h"
#include "../instructions/nop/nop.h"
#include "../instructions/halt/halt.h"
#include "../instructions/mov/mov.h"
#include "../instructions/str/str.h"
#include "../instructions/ldr/ldr.h"
#include "../instructions/add/add.h"
#include "../instructions/sub/sub.h"
#include "../instructions/mul/mul.h"
#include "../instructions/and/and.h"
#include "../instructions/orr/orr.h"

void decodeAndExecute(CPUContext *cpuCtxPtr)
{
  uint16_t instruction = cpuCtxPtr->ir;

  // Instruction 16 bits.
  uint8_t *bitsArr = decimalToBinary(instruction);

  uint8_t *opCode = binaryToDecimal(bitsArr, 0, 3);
  uint8_t variation = bitsArr[4];

  uint8_t *rdPtr = binaryToDecimal(bitsArr, 5, 7);
  uint8_t *rmPtr = binaryToDecimal(bitsArr, 8, 10);
  uint8_t *rnPtr = binaryToDecimal(bitsArr, 11, 13);

  uint8_t rd = *rdPtr;
  uint8_t rm = *rmPtr;
  uint8_t rn = *rnPtr;

  if (instruction == 0)
    return NOP(cpuCtxPtr);

  if (instruction == 65535)
    return HALT(cpuCtxPtr);

  if (*opCode == 0)
  {
    uint8_t *aux = binaryToDecimal(bitsArr, 14, 15);

    if (variation)
    {
      if (*aux == 0)
        return printf("JMP\n");
      if (*aux == 1)
        return printf("JEQ\n");
      if (*aux == 2)
        return printf("JLT\n");
      if (*aux == 3)
        return printf("JGT\n");
    }
    else
    {
      if (*aux == 1)
        return printf("PSH\n");
      if (*aux == 2)
        return printf("POP\n");
      if (*aux == 3)
        return printf("CMP\n");
    }
  }

  // MOV variations
  if (*opCode == 1)
  {
    // MOV Rd = #Im
    if (variation)
    {
      uint8_t *immediate = binaryToDecimal(bitsArr, 8, 15);
      return MOV_IM(cpuCtxPtr, rd, *immediate);
    }

    // MOV Rd = Rm
    return MOV(cpuCtxPtr, rd, rm);
  }

  // STR variations
  if (*opCode == 2)
  {
    // STR Rm = #Im
    if (variation)
    {
      uint8_t immediateBits[8] = {
          bitsArr[5],
          bitsArr[6],
          bitsArr[7],
          bitsArr[11],
          bitsArr[12],
          bitsArr[13],
          bitsArr[14],
          bitsArr[15]};

      uint8_t *immediate = binaryToDecimal(immediateBits, 0, 7);
      return STR_IM(cpuCtxPtr, rm, *immediate);
    }

    // STR Rm = Rn
    return STR(cpuCtxPtr, rm, rn);
  }

  // LDR
  if (*opCode == 3)
    return LDR(cpuCtxPtr, rd, rm);

  // ADD
  else if (*opCode == 4)
    return ADD(cpuCtxPtr, rd, rm, rn);

  // SUB
  else if (*opCode == 5)
    return SUB(cpuCtxPtr, rd, rm, rn);

  // MUL
  else if (*opCode == 6)
    return MUL(cpuCtxPtr, rd, rm, rn);

  // AND
  else if (*opCode == 7)
    return AND(cpuCtxPtr, rd, rm, rn);

  // ORR
  else if (*opCode == 8)
    return ORR(cpuCtxPtr, rd, rm, rn);

  // NOT
  else if (*opCode == 9)
    return printf("NOT\n");
  // XOR
  else if (*opCode == 10)
    return printf("XOR\n");
  // SHR
  else if (*opCode == 11)
    return printf("SHR\n");
  // SHL
  else if (*opCode == 12)
    return printf("SHL\n");
  // ROR
  else if (*opCode == 13)
    return printf("ROR\n");
  // ROL
  else if (*opCode == 14)
    return printf("ROL\n");

  printf("Unmapped instruction.\n");
}