#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cpu-context.h"
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
    printf("----------- Program Memory -----------\n");

    for (int i = 0; i < MEMORY_RANGE; i++)
    {
        if (cpuCtxPtr->usedProgramMem[i])
        {
            printf(
                "Addr[0x%04x]: 0x%02x = %d\n",
                i,
                cpuCtxPtr->programMem[i],
                cpuCtxPtr->programMem[i]);
        }
    }
}

uint8_t *nextInstructionBits(CPUContext *cpuCtxPtr)
{
    uint8_t *instructionBits = (uint8_t *)calloc(16, sizeof(uint8_t));

    if (instructionBits == NULL)
    {
        perror("Error on alocate memory for instruction.");
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

    return instructionBits;
}

uint16_t *extractIntFromInstruction(uint8_t *instructionBits, int from, int to)
{
    uint16_t *extracted = (uint16_t *)calloc(1, sizeof(uint16_t));
    int digitsCount = 0;

    if (extracted == NULL)
    {
        perror("Error on alocate memory for extract int.");
        exit(1);
    }

    for (int i = to; i >= from; i--)
    {
        if (instructionBits[i])
        {
            *extracted += pow(2, digitsCount);
        }

        digitsCount++;
    }

    return extracted;
}

void startExecution(CPUContext *cpuCtxPtr)
{
    printf("------- Start Execution -------\n");

    while (cpuCtxPtr->usedProgramMem[cpuCtxPtr->pc])
    {
        uint8_t *instructionBits = nextInstructionBits(cpuCtxPtr);

        uint16_t *ir = extractIntFromInstruction(instructionBits, 0, 15);

        // Print instruction bits
        // printf("Instruction bits: ");
        // for (int i = 0; i < 16; i++)
        //     printf("%d", instructionBits[i]);
        // printf("\n");

        cpuCtxPtr->ir = *ir;
        cpuCtxPtr->pc += 2;
    }

    endExecution(cpuCtxPtr);
}

void endExecution(CPUContext *cpuCtxPtr)
{
    printf("-------- End Execution --------\n");

    free(cpuCtxPtr);
    printf("CPU memory freed.\n");

    printf("TODO: print cpu state.\n");
    exit(0);
}