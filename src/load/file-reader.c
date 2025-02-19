#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-reader.h"

void remove_spaces(char *s)
{
    char *d = s;
    do
    {
        while (*d == ' ')
        {
            ++d;
        }
    } while (*s++ = *d++);
}

char **ler_arquivo(const char *nomearq, int *nlines)
{
    printf("------------ Reading File ------------\n");
    printf("Filepath: \"./src/test.txt\".\n");

    FILE *fp = fopen(nomearq, "r");

    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo \"%s\".", nomearq);
        return NULL;
    }

    char readLine[14];
    char **lines = NULL;

    int count = 0;

    while (fgets(readLine, 14, fp) != NULL)
    {
        remove_spaces(readLine);

        // Linha no formato "####:0x####".
        char formattedLine[12];

        // Copia excluindo a quebra de linha.
        strncpy(formattedLine, readLine, 11);
        // Insere o terminador de string.
        formattedLine[11] = '\0';

        // Aloca mais uma posição no vetor.
        lines = realloc(lines, (count + 1) * sizeof(char *));
        // Aloca memória na posição adicionada.
        lines[count] = malloc(12 * sizeof(char));

        // Insere a linha na memória alocada.
        strcpy(lines[count], formattedLine);
        count++;
    }

    fclose(fp);

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", lines[i]);
    }

    *nlines = count;
    return lines;
}

void liberar_linhas_lidas(char **readLines, int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        free(readLines[i]);
    }

    free(readLines);
}