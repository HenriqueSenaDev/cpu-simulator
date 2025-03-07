#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cpu-context.h"
#include "../utils/numeric.h"
#include "../decode/decoder.h"

CPUContext *initCPU()
{
    CPUContext *cpuCtxPtr = (CPUContext *)calloc(1, sizeof(CPUContext));

    // Generic registers initialization.
    memset(cpuCtxPtr->registers, 0, sizeof(cpuCtxPtr->registers));

    // Specific registers initialization.
    cpuCtxPtr->ir = 0;
    cpuCtxPtr->pc = 0;
    cpuCtxPtr->sp = 0x8200; // Initial SP addr.

    // Flags initialization.
    cpuCtxPtr->carry = 0;
    cpuCtxPtr->overflow = 0;
    cpuCtxPtr->zero = 0;
    cpuCtxPtr->signal = 0;

    return cpuCtxPtr;
}

void printProgramMem(CPUContext *cpuCtxPtr)
{
    printf("> Program Memory\n");

    for (int i = 0; i < MEMORY_RANGE; i = i + 2)
    {
        if (cpuCtxPtr->usedProgramMem[i])
        {
            printf(
                "Addr[0x%04x]: 0x%02x%02x\n",
                i,
                cpuCtxPtr->programMem[i + 1],
                cpuCtxPtr->programMem[i]);
        }
    }
}

void printState(CPUContext *cpuCtxPtr)
{
    int carry = cpuCtxPtr->carry;
    int overflow = cpuCtxPtr->overflow;
    int signal = cpuCtxPtr->signal;
    int zero = cpuCtxPtr->zero;

    printf("---------- CPU State ----------\n");
    printf("Registers\n");

    // Registers
    for (int i = 0; i < 8; i++)
        printf("    R%d: 0x%04x\n", i, cpuCtxPtr->registers[i]);

    printf("    PC: 0x%04x\n", cpuCtxPtr->pc);
    printf("    SP: 0x%04x\n", cpuCtxPtr->sp);

    // Used data mem
    printf("Data Memory\n");
    for (int i = 0; i < MEMORY_RANGE; i = i + 2)
    {
        if (cpuCtxPtr->usedDataMem[i])
            printf(
                "   [0x%04x]: 0x%02x%02x\n",
                i,
                cpuCtxPtr->dataMem[i + 1],
                cpuCtxPtr->dataMem[i]);
    }

    // Stack
    printf("Stack\n");
    for (int i = 0; i < 8; i++)
    {
        uint16_t curAddr = 0x8200 - (2 * i);

        printf(
            "   [0x%04x]: 0x%02x%02x\n",
            curAddr,
            cpuCtxPtr->dataMem[curAddr + 1],
            cpuCtxPtr->dataMem[curAddr]);
    }

    // Flags
    printf("Flags\n");
    printf("    Ca:%d Ov:%d S:%d Z:%d\n", carry, overflow, signal, zero);

    printf("--------------------------------\n");
}

uint16_t *mountNextInstruction(CPUContext *cpuCtxPtr)
{
    uint8_t *instructionBits = (uint8_t *)calloc(16, sizeof(uint8_t));

    if (instructionBits == NULL)
    {
        perror("Error on alocate memory for instruction bits.");
        exit(1);
    }

    uint8_t instructionLsb = cpuCtxPtr->programMem[cpuCtxPtr->pc];
    uint8_t instructionMsb = cpuCtxPtr->programMem[cpuCtxPtr->pc + 1];

    for (int i = 0; i < 8; i++)
    {
        uint8_t lsbBit = instructionLsb % 2; // 0 or 1
        instructionBits[15 - i] = lsbBit;

        uint8_t msbBit = instructionMsb % 2; // 0 or 1
        instructionBits[7 - i] = msbBit;

        instructionLsb = instructionLsb >> 1;
        instructionMsb = instructionMsb >> 1;
    }

    return binaryToDecimal(instructionBits, 0, 15);
}

void startExecution(CPUContext *cpuCtxPtr)
{
    printProgramMem(cpuCtxPtr);

    printf("> Start Execution\n");

    while (cpuCtxPtr->usedProgramMem[cpuCtxPtr->pc])
    {
        // Search
        uint16_t *instruction = mountNextInstruction(cpuCtxPtr);
        cpuCtxPtr->ir = *instruction;
        cpuCtxPtr->pc += 2;

        decodeAndExecute(cpuCtxPtr);
    }

    endExecution(cpuCtxPtr);
}

void endExecution(CPUContext *cpuCtxPtr)
{
    printf("> End Execution\n");
    free(cpuCtxPtr);

    printState(cpuCtxPtr);
    exit(0);
}