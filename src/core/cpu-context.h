#include <stdint.h>
#ifndef CPU_CONTEXT_H
#define CPU_CONTEXT_H

// 16 bits memory (From 0x0000 to 0xFFFF).
#define MEMORY_RANGE 65536

typedef struct cpu_context
{
    // 65536x8 program memory.
    uint8_t programMem[MEMORY_RANGE];
    // 65536x8 data memory.
    uint8_t dataMem[MEMORY_RANGE];
} CPUContext;

CPUContext *initCPU();
void cleanCPU(CPUContext *cpuCtx);

#endif