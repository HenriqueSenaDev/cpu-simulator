#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-line-parser.h"

int hexadecimal_para_inteiro(const char *hex_str)
{
    int valor;
    sscanf(hex_str, "%x", &valor);
    return valor;
}

void popular_memoria_programa(CPUContext *cpuCtx, char **linhas, int nLinhas) {
    for (int i = 0; i < nLinhas; i++) {
        char enderecostr[5];
        char valorstr1[3];
        char valorstr2[3];

        strncpy(enderecostr, linhas[i], 4);
        enderecostr[4] = '\0';
        strncpy(valorstr1, linhas[i] + 10, 2);
        valorstr1[2] = '\0';
        strncpy(valorstr2, linhas[i] + 8, 2);
        valorstr2[2] = '\0';


        uint8_t endereco = (uint8_t) hexadecimal_para_inteiro(enderecostr);
        uint8_t valor1 = (uint8_t) hexadecimal_para_inteiro(valorstr1);
        uint8_t valor2 = (uint8_t) hexadecimal_para_inteiro(valorstr2);
        cpuCtx->programMem[endereco +1 ] = valor1;
        cpuCtx->programMem[endereco] = valor2;
    }
    
    for(int i = 0; i < MEMORY_RANGE; i++) {
        if(cpuCtx->programMem[i] != 0)
        printf("Memória[%d] = %02x\n", i, cpuCtx->programMem[i]);
    }
}