#ifndef FILE_LINE_PARSER_H
#define FILE_LINE_PARSER_H

int hexadecimal_para_inteiro(const char *hex_str);
void divisao_enderecos_instrucoes(char **linhas, int nlinhas, char ***endereco, char ***instrucao);
void processar_instrucoes(char **enderecos, char **instrucoes, int quantidade);

#endif
