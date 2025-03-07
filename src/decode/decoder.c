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
#include "../instructions/not/not.h"
#include "../instructions/xor/xor.h"
#include "../instructions/psh/psh.h"
#include "../instructions/pop/pop.h"
#include "../instructions/cmp/cmp.h"
#include "../instructions/jmp/jmp.h"
#include "../instructions/jeq/jeq.h"
#include "../instructions/jlt/jlt.h"
#include "../instructions/jgt/jgt.h"
#include "../instructions/shr/shr.h"
#include "../instructions/shl/shl.h"
#include "../instructions/ror/ror.h"
#include "../instructions/rol/rol.h"

void decodeAndExecute(CPUContext *cpuCtxPtr)
{
  uint16_t instruction = cpuCtxPtr->ir;

  // Instruction 16 bits.
  uint8_t *bitsArr = decimalToBinary(instruction);

  uint8_t *opCode = (uint8_t *)binaryToDecimal(bitsArr, 0, 3);
  uint8_t variation = bitsArr[4];

  uint8_t *rdPtr = (uint8_t *)binaryToDecimal(bitsArr, 5, 7);
  uint8_t *rmPtr = (uint8_t *)binaryToDecimal(bitsArr, 8, 10);
  uint8_t *rnPtr = (uint8_t *)binaryToDecimal(bitsArr, 11, 13);

  uint8_t rd = *rdPtr;
  uint8_t rm = *rmPtr;
  uint8_t rn = *rnPtr;

  if (instruction == 0)
    return NOP(cpuCtxPtr);

  if (instruction == 65535)
    return HALT(cpuCtxPtr);

  if (*opCode == 0)
  {
    uint8_t *aux = (uint8_t *)binaryToDecimal(bitsArr, 14, 15);

    // JUMPS
    if (variation)
    {
      uint16_t *immediate = binaryToDecimal(bitsArr, 5, 13);

      // JMP
      if (*aux == 0)
        return JMP(cpuCtxPtr, *immediate);

      // JEQ
      if (*aux == 1)
        return JEQ(cpuCtxPtr, *immediate);

      // JLT
      if (*aux == 2)
        return JLT(cpuCtxPtr, *immediate);

      // LGT
      if (*aux == 3)
        return JGT(cpuCtxPtr, *immediate);
    }

    // PSH
    if (*aux == 1)
      return PSH(cpuCtxPtr, rn);

    // POP
    if (*aux == 2)
      return POP(cpuCtxPtr, rd);

    // CMP
    if (*aux == 3)
      return CMP(cpuCtxPtr, rm, rn);
  }

  // MOV variations
  if (*opCode == 1)
  {
    // MOV Rd = #Im
    if (variation)
    {
      uint8_t *immediate = (uint8_t *)binaryToDecimal(bitsArr, 8, 15);
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

      uint8_t *immediate = (uint8_t *)binaryToDecimal(immediateBits, 0, 7);
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
    return NOT(cpuCtxPtr, rd, rm);

  // XOR
  else if (*opCode == 10)
    return XOR(cpuCtxPtr, rd, rm, rn);

  // SHR
  else if (*opCode == 11)
  {
    uint8_t *immediate = (uint8_t *)binaryToDecimal(bitsArr, 11, 15);
    return SHR(cpuCtxPtr, rd, rm, *immediate);
  }

  // SHL
  else if (*opCode == 12)
  {
    uint8_t *immediate = (uint8_t *)binaryToDecimal(bitsArr, 11, 15);
    return SHL(cpuCtxPtr, rd, rm, *immediate);
  }

  // ROR
  else if (*opCode == 13)
    return ROR(cpuCtxPtr, rd, rm);

  // ROL
  else if (*opCode == 14)
    return ROL(cpuCtxPtr, rd, rm);

  printf("Unmapped instruction.\n");
  endExecution(cpuCtxPtr);
}