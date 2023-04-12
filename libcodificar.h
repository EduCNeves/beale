#ifndef __LIBCODIFICAR__
#define __LIBCODIFICAR__

#include "liblistacarect.h"

#include <stdlib.h>
#include<time.h>
#include <string.h>

#define LINESIZE 1024

int codificar_mensagem_original(char *messagem_original, lista_t *chaves, char *saida);
int codificar_palavra(char *palavra, FILE *arq_s, lista_t *chaves);
int gerar_num(Node *aux);


#endif