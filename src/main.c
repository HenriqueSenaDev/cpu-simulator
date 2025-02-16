#include <stdio.h>
#include <stdlib.h>
#include "load/file-reader.h"
#include "core/cpu-context.h"
#include "load/file-line-parser.h"

int main()
{
    int linesQuantity;
    char **readLines = ler_arquivo("./src/test.txt", &linesQuantity);
    printf("%d instruções lidas.\n", linesQuantity);

    // CPU state initialization.
    CPUContext *cpuCtx = initCPU();

    popular_memoria_programa(cpuCtx, readLines, linesQuantity);

    // Memory freed.
    liberar_linhas_lidas(readLines, linesQuantity);
    cleanCPU(cpuCtx);
    return 0;
}