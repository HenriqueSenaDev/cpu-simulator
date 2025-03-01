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
    // TODO: handle stack range (16 bytes from 0x8200).
    uint8_t dataMem[MEMORY_RANGE];
    bool usedDataMem[MEMORY_RANGE];

    // Generic registers.
    uint16_t registers[NUM_REGISTERS];

    // Specific registers.
    uint16_t ir;
    uint16_t sp;
    uint16_t pc;

    // Flags
    uint8_t carry;
    uint8_t overflow;
    uint8_t zero;
    uint8_t signal;
} CPUContext;

CPUContext *initCPU();

void printProgramMem(CPUContext *cpuCtx);

void startExecution(CPUContext *cpuCtx);

void endExecution(CPUContext *cpuCtx);

#endif
