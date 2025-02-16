#include <stdio.h>
#include <stdlib.h>
#include "load/file-reader.h"
#include "core/cpu-context.h"
#include "load/file-line-parser.h"

int main()
{
    // File reading
    int linesQuantity;
    printf("Reading file './src/test.txt'...\n");
    char **readLines = ler_arquivo("./src/test.txt", &linesQuantity);
    printf("%d instruções lidas.\n", linesQuantity);

    // CPU initialization
    CPUContext *cpuCtx = initCPU();
    popular_memoria_programa(cpuCtx, readLines, linesQuantity);

    printCPUState(cpuCtx);

    // Memory freed
    liberar_linhas_lidas(readLines, linesQuantity);
    cleanCPU(cpuCtx);
    return 0;
}