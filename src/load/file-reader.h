#ifndef FILE_READER_H
#define FILE_READER_H

char **ler_arquivo(const char *nomearq, int *nlinhas);

void liberar_linhas_lidas(char **linhasLidas, int nLinhas);

#endif