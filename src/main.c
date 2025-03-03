#include <stdio.h>
#include <stdlib.h>
#include "load/file-reader.h"
#include "core/cpu-context.h"
#include "load/file-line-parser.h"

int main()
{
    // File reading
    int linesQuantity;
    char **readLines = ler_arquivo("./src/test.txt", &linesQuantity);

    // CPU initialization
    CPUContext *cpuCtx = initCPU();
    popular_memoria_programa(cpuCtx, readLines, linesQuantity);
    liberar_linhas_lidas(readLines, linesQuantity);

    // Instructions execution.
    startExecution(cpuCtx);
    return 0;
}