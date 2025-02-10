#include <stdio.h>
#include "load/file-reader.h"
#include "load/file-line-parser.h"

int main()
{
    printf("Hello CPU Simulator!\n");
    int nlinhas;
    char **linhas = ler_arquivo("test.txt", &nlinhas);
    if (linhas == NULL) {
        fprintf(stderr, "Erro ao ler o arquivo.\n");
        return 1;}
    char **endereco;
    char **instrucao;
    divisao_enderecos_instrucoes(linhas, nlinhas, &endereco, &instrucao);
    for (int i = 0; i < nlinhas; i++)
    {
        printf("endereco: %s\n", endereco[i]);
    }
    for (int i = 0; i < nlinhas; i++)
    {
        printf("instrucao: %s\n", instrucao[i]);
    }
    
    return 0;
}