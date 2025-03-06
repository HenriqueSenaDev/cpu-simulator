#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void SHL(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm, uint8_t immediate)
{
  printf("SHL R%d = R%d << %d\n", rd, rm, immediate);

  cpuCtxPtr->registers[rd] = cpuCtxPtr->registers[rm] << immediate;

  cpuCtxPtr->zero = cpuCtxPtr->registers[rd] == 0;
  cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
  // o bit de carry é o bit que foi deslocado para fora do registrador, nesse caso o bit MAIS significativo.
  // se immediate = 0 não houve deslocamento, então o carry é 0
  // (immediate > 0 && immediate <= 16) ? serve para verificar se o immediate é válido 
  cpuCtxPtr->carry = (immediate > 0 && immediate <= 16) ? ((cpuCtxPtr->registers[rm] >> (16 - immediate)) & 1) : 0;
}