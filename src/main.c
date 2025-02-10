#include <stdio.h>
#include <stdlib.h>
#include "load/file-reader.h"
#include "core/cpu-context.h"
#include "load/file-line-parser.h"
#include "load/alocar-mem.h"

int main()
{
    printf("Hello CPU Simulator!\n");

    int linesQuantity;
    char **readLines = ler_arquivo("test.txt", &linesQuantity);

    printf("%d instruções lidas.\n", linesQuantity);
    
    char **enderecos;
    char **instrucoes;
    divisao_enderecos_instrucoes(readLines, linesQuantity, &enderecos, &instrucoes);

    CPUContext *cpuCtx = initCPU();
    printf("CPU initialized.\n");

    alocar_mem(cpuCtx->programMem, enderecos, instrucoes, linesQuantity);

    cleanCPU(cpuCtx);
    printf("CPU memory freed.\n");

    return 0;
}