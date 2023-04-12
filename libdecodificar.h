#ifndef __LIBDECODIFICAR__
#define __LIBDECODIFICAR__

#include "liblistacarect.h"

#include <stdlib.h>
#include<time.h>
#include <string.h>

#define LINESIZE 1024

int decodificar_mensagem_codificada(char *mensagem_codificada, lista_t *chaves, char *saida);
int decodificar_numero(char *numero, FILE *arq_s, lista_t *chaves);


#endif