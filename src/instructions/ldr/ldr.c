#include "../../core/cpu-context.h"
#include <stdint.h>
#include <stdio.h>

void LDR(CPUContext *cpuCtxPtr, uint8_t rd, uint8_t rm)
{
    printf("LDR R%d = [R%d]\n", rd, rm);

    // obtem o endereço armazenado em rm
    uint16_t address = cpuCtxPtr->registers[rm];

    // confere se o endereço ta dentro do intervalo da memoria
    if (address < MEMORY_RANGE - 1)
    {
        // le um valor de 16 bits da memoria de dados
        cpuCtxPtr->registers[rd] = (cpuCtxPtr->dataMem[address] | (cpuCtxPtr->dataMem[address + 1] << 8));
        
        // atualiza os flags
        cpuCtxPtr->zero = (cpuCtxPtr->registers[rd] == 0);
        cpuCtxPtr->signal = (cpuCtxPtr->registers[rd] & 0x8000) != 0;
    }
    else
    {
        printf("Erro: Tentativa de acessar endereço inválido 0x%04X\n", address);
    }
}
