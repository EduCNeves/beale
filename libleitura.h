#ifndef __LIBLEITURA__
#define __LIBLEITURA__

#include "liblistacarect.h"

#define LINESIZE 1024

void ler_livro_cifra(char *livro_cifra, lista_t *chaves);
void ler_arquivos_de_chaves(char *arquivo_de_chaves, lista_t *chaves);
char separa_caractere(char *palavra);

#endif