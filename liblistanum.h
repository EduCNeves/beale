#ifndef __LIBLISTANUM__
#define __LIBLISTANUM__
     
#include <stdio.h>
#include <stdlib.h>


typedef struct NodeN{
    int num;
    struct NodeN *prox;
} NodeN;

typedef struct lista_n{
    NodeN *inicio;
    int tam;
}lista_n;


void insere_numero(lista_n *lista, int num);
lista_n *cria_lista_n();
NodeN *criaNode_n();
void exibe_lista_n(lista_n *lista);
int buscar_lista_n(lista_n *lista, char *elemento);


#endif