#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-reader.h"

char **ler_arquivo(const char *nomearq, int *nlinhas)
{
    FILE *fp = fopen(nomearq, "r");
    char lelinha[14];
    char **linhas = NULL;
    int cl = 0;

    while (fgets(lelinha, 14, fp) != NULL)
    {
        // Substitue quebra de linha pelo terminador de string.
        lelinha[strcspn(lelinha, "\n")] = '\0';

        // Aloca mais uma posição vetor.
        linhas = realloc(linhas, (cl + 1) * sizeof(char *));

        // Aloca memória na posição adicionada.
        linhas[cl] = malloc((strlen(lelinha) + 1) * sizeof(char));

        // Insere a linha na memória alocada.
        strcpy(linhas[cl], lelinha);

        cl++;
    }

    fclose(fp);

    for (int i = 0; i < cl; i++)
    {
        printf("%s\n", linhas[i]);
    }

    *nlinhas = cl;
    return linhas;
}

void liberar_linhas_lidas(char **linhasLidas, int nLinhas)
{
    for (int i = 0; i < nLinhas; i++)
    {
        free(linhasLidas[i]);
    }

    free(linhasLidas);
}