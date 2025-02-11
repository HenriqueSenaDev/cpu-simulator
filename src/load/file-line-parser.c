#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-line-parser.h"

int hexadecimal_para_inteiro(const char *hex_str)
{
    int valor;
    sscanf(hex_str, "%x", &valor);
    return valor;
}

void popular_memoria_programa(CPUContext *cpuCtx, char **linhas, int nLinhas) {
    // Para cada linha em "linhas" deve ser extraído o "endereço" e o "valor".
    // É importante lembrar que ambos devem ser do tipo "uint8_t" de 8 bits.
    // Após extraí-los, setar eles na memória de programa da cpu.
    // Ex.: "cpuCtx->programMem[endereco8Bits] = valor8Bits;".

    // OBS: ao finalizar pode deletar alocar-mem.h e a função comentada abaixo
    // pois não estaremos utilizando.
};

// A função abaixo será substituída pela função acima.

// void divisao_enderecos_instrucoes(char **linhas, int nlinhas, char ***endereco, char ***instrucao)
// {
//     *endereco = (char **)malloc(nlinhas * sizeof(char *));
//     *instrucao = (char **)malloc(nlinhas * sizeof(char *));

//     for (int i = 0; i < nlinhas; i++)
//     {
//         (*endereco)[i] = (char *)malloc(5 * sizeof(char));
//         (*instrucao)[i] = (char *)malloc(5 * sizeof(char));

//         strncpy((*endereco)[i], linhas[i], 4);
//         (*endereco)[i][4] = '\0';
//         strncpy((*instrucao)[i], linhas[i] + 8, 4);
//         (*instrucao)[i][4] = '\0';
//     }
// }