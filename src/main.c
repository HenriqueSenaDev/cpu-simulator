#include <stdio.h>
#include <stdlib.h>
#include "load/file-reader.h"
#include "core/cpu-context.h"
#include "load/file-line-parser.h"

int main()
{
    printf("Hello CPU Simulator!\n");

    int linesQuantity;
    char **readLines = ler_arquivo("test.txt", &linesQuantity);

    printf("%d instruções lidas.\n", linesQuantity);

    CPUContext *cpuCtx = initCPU();
    printf("CPU initialized.\n");

    popular_memoria_programa(cpuCtx, readLines, linesQuantity);

    cleanCPU(cpuCtx);
    printf("CPU memory freed.\n");

    return 0;
}