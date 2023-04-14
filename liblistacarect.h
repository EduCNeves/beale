#ifndef __LIBLISTACARECT__
#define __LIBLISTACARECT__
     
#include <stdio.h>
#include <stdlib.h>
#include "liblistanum.h"



typedef struct Node{
 char letra;
 struct lista_n *listaN;
 struct Node *prox;
} Node;

typedef struct lista_t{
    Node *inicio;
    int tam;
}lista_t;


lista_t *cria_lista_c();
Node *criaNode();
void insere_caracter(lista_t *lista, char elemento, int i);
void exibe_lista_c(lista_t *lista);
int listaVazia(lista_t *lista);
Node *buscar_lista_c(lista_t *lista, char c);
void libera_lista_c(lista_t *lista);

#endif