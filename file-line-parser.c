// Task 2 -> Convert hex values present in string to integer.
// String format example: "0000: 0x1803"

// References:
// https://stackoverflow.com/questions/10156409/convert-hex-string-char-to-int
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/strtol.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file-line-parser.h"

int hexadecimal_para_inteiro(const char *hex_str) {
    int valor;
    sscanf(hex_str, "%x", &valor);
    return valor;
}

void processar_instrucoes(char **enderecos, char **instrucoes, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        int valor_endereco = hexadecimal_para_inteiro(enderecos[i]);
        int valor_instrucao = hexadecimal_para_inteiro(instrucoes[i]);

        printf("Endereco: %s = Inteiro: %d\n", enderecos[i], valor_endereco);
        printf("Instrucao: %s = Inteiro: %d\n", instrucoes[i], valor_instrucao);
    }
}