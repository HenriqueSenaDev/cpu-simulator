#include "../core/cpu-context.h"
#ifndef FILE_LINE_PARSER_H
#define FILE_LINE_PARSER_H

int hexadecimal_para_inteiro(const char *hex_str);

void popular_memoria_programa(CPUContext *cpuCtx, char **linhas, int nLinhas);

#endif
