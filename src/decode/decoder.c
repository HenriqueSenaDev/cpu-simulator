#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../core/cpu-context.h"
#include "../utils/numeric.h"
#include "../instructions/nop/nop.h"
#include "../instructions/halt/halt.h"
#include "../instructions/mov/mov.h"

// Receives 16 bits array
void decodeAndExecute(CPUContext *cpuCtxPtr)
{
  uint16_t instruction = cpuCtxPtr->ir;

  // Instruction 16 bits.
  uint8_t *bitsArr = decimalToBinary(instruction);

  uint8_t *opCode = binaryToDecimal(bitsArr, 0, 3);
  uint8_t variation = bitsArr[4];

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
  else if (*opCode == 1)
  {
    uint8_t *rd = binaryToDecimal(bitsArr, 5, 7);

    // MOV Rd = #Im
    if (variation)
    {
      uint8_t *immediate = binaryToDecimal(bitsArr, 8, 15);
      return MOV_IM(cpuCtxPtr, *rd, *immediate);
    }

    // MOV Rd = Rm
    uint8_t *rm = binaryToDecimal(bitsArr, 8, 10);
    return MOV(cpuCtxPtr, *rd, *rm);
  }
  // STR variations
  else if (*opCode == 2)
  {
    if (variation)
      return printf("STR [Rm] = Rn\n");
    else
      return printf("STR [Rm] = #Im\n");
  }
  // LDR
  else if (*opCode == 3)
    return printf("LDR\n");
  // ADD
  else if (*opCode == 4)
    return printf("ADD\n");
  // SUB
  else if (*opCode == 5)
    return printf("SUB\n");
  // MUL
  else if (*opCode == 6)
    return printf("MUL\n");
  // AND
  else if (*opCode == 7)
    return printf("AND\n");
  // ORR
  else if (*opCode == 8)
    return printf("ORR\n");
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