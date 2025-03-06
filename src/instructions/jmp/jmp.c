#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void JMP(CPUContext *cpuCtxPtr, uint16_t immediate)
{
    // Imediato em complemento 2.
    int16_t offset = (immediate & 0x100)
                         ? immediate | ~0x1FF
                         : immediate;

    printf("JMP 0x%03x (PC += %d)\n", immediate, offset);

    // atualiza o contador de programa
    cpuCtxPtr->pc += offset;
}
