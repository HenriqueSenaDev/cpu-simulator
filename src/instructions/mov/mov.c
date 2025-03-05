#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void MOV(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
    printf("MOV R%d = R%d\n", rd, rm);

    // copia o valor de rm pra rd
    cpuCtxPtr->registers[rd] = cpuCtxPtr->registers[rm];
}

void MOV_IM(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t immediate)
{
    printf("MOV R%d = #%d\n", rd, immediate);

    // atribui o valor imediato ao registrador rd
    cpuCtxPtr->registers[rd] = immediate;
}
