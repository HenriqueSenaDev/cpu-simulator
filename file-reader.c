// Task 1 -> Read the content of a file and store in a string array.
// File to read: "text.txt"

// References: https://www.youtube.com/watch?v=DqY_PGlMihM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-reader.h"

void ler_arquivo(const char *nomearq){
    FILE *fp; 
    char linha[14];
    char **instrucao = NULL;
    char **endereco = NULL;
    int cl = 0;
    fp = fopen(nomearq, "r");
    while (fgets(linha, 14, fp) != NULL){
        linha[strcspn(linha, "\n")] = '\0';
        endereco = realloc (endereco, (cl + 1) * sizeof (char*));
        instrucao = realloc (instrucao, (cl + 1) * sizeof (char*));
        endereco[cl] = malloc ((4 + 1)*sizeof(char));
        instrucao[cl] = malloc ((4 + 1)*sizeof(char));
        strncpy(endereco[cl], linha, 4);
        endereco[cl][4] = '\0';
        strncpy(instrucao[cl], linha + 8, 4);
        instrucao[cl][4] = '\0';
        cl++;
    }
    fclose(fp);
    for(int i = 0; i < cl; i++){
        printf("%s\n", endereco[i]);
    }
    for(int i = 0; i < cl; i++){
        printf("%s\n", instrucao[i]);
    }
    

}
