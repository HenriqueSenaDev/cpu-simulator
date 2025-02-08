#include <stdio.h>
#include "file-reader.h"
int main()
{
    printf("Hello CPU Simulator!\n");
    const char *nomearq = "test.txt";
    ler_arquivo(nomearq);
    return 0;
}