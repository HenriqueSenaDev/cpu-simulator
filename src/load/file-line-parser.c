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
        char valorstr[5];

        strncpy(enderecostr, linhas[i], 4);
        enderecostr[4] = '\0';
        strncpy(valorstr, linhas[i] + 8, 4);
        valorstr[4] = '\0';

        uint8_t endereco = (uint8_t) hexadecimal_para_inteiro(enderecostr);
        uint8_t valor = (uint8_t) hexadecimal_para_inteiro(valorstr);
        cpuCtx->programMem[endereco] = valor;
    }
}