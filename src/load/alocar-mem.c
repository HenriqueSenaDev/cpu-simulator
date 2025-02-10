#include <stdlib.h>
#include <stdlib.h>
#include "alocar-mem.h"


void alocar_mem(int *memoria, char **endereco, char **valor, int nlinhas)
{
    for(int i = 0; i < nlinhas; i++){
        int ender = (int)strtol(endereco[i], NULL, 16);
        int val = (int)strtol(valor[i], NULL, 16);
        if((ender >= 0) && (ender < 65536)){
            memoria[ender] = valor[i];
        }
    }
}
