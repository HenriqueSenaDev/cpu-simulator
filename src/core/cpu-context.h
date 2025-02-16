#include <stdint.h>
#include <stdbool.h>
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
    bool usedProgramMem[MEMORY_RANGE];

    // 65536x8 data memory.
    uint8_t dataMem[MEMORY_RANGE];

    uint16_t registers[NUM_REGISTERS];

    uint8_t carry;
    uint8_t overflow;
    uint8_t zero;
    uint8_t signal;
} CPUContext;

CPUContext *initCPU();

void cleanCPU(CPUContext *cpuCtx);

void printCPUState(CPUContext *cpuCtx);

#endif
