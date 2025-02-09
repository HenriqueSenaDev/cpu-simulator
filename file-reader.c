#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-reader.h"

void ler_arquivo(const char *nomearq, char ***enderecos, char ***instrucoes, int *quantidade)
{
    FILE *fp = fopen(nomearq, "r");
    char linha[20];
    int cl = 0;
    *enderecos = NULL;
    *instrucoes = NULL;

    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo.");
        return;
    }

    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';
        *enderecos = realloc(*enderecos, (cl + 1) * sizeof(char *));
        *instrucoes = realloc(*instrucoes, (cl + 1) * sizeof(char *));
        (*enderecos)[cl] = malloc(5 * sizeof(char));
        (*instrucoes)[cl] = malloc(5 * sizeof(char));
        strncpy((*enderecos)[cl], linha, 4);
        (*enderecos)[cl][4] = '\0';
        strncpy((*instrucoes)[cl], linha + 8, 4);
        (*instrucoes)[cl][4] = '\0';
        cl++;
    }

    fclose(fp);
    *quantidade = cl;
}
