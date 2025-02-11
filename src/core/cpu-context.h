#include <stdint.h>
#ifndef CPU_CONTEXT_H
#define CPU_CONTEXT_H

// 16 bits memory (From 0x0000 to 0xFFFF).
#define MEMORY_RANGE 65536
#define NUM_REGISTERS 8
#define REGISTER_SIZE 16

typedef struct cpu_context
{
    // 65536x8 program memory.
    uint8_t programMem[MEMORY_RANGE];
    // 65536x8 data memory.
    uint8_t dataMem[MEMORY_RANGE];

    uint8_t registers[NUM_REGISTERS][REGISTER_SIZE];
    // Flags (1 inteiro, 32 bits, onde cada bit pode representar um flag).
    uint32_t flags;

} CPUContext;

CPUContext *initCPU();
void cleanCPU(CPUContext *cpuCtx);

#endif
