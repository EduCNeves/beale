#include "liblistanum.h" 

#include <stdio.h>
#include <stdlib.h>

void insere_numero(lista_n *lista, int num){
   
   NodeN *node = criaNode_n();
   node->num = num;
   
   
   node->prox = lista->inicio;
   lista->inicio = node;

   lista->tam++;

   
}

lista_n *cria_lista_n(){

   lista_n *lista = (lista_n *) malloc(sizeof(lista_n));
   lista->inicio=NULL;
   lista->tam=0;

   return lista;
}

NodeN *criaNode_n(){

   NodeN *node = (NodeN *) malloc(sizeof(NodeN));
   node->prox = NULL;
   node->num = 0;

   return node;
}

void exibe_lista_n(lista_n *lista){

   NodeN *aux = lista->inicio;

   for (int i = 0; i < lista->tam; i++){
      printf("%d ", aux->num);
      aux = aux->prox; 
   }
   
}

int buscar_lista_n(lista_n *lista, char *numero){
   
   NodeN *aux = lista->inicio;
   int elemento = atoi(numero);

   while (aux){
      if (aux->num == elemento){
         return 0;
      }
      aux = aux->prox;
   }
   return 1;
   
}

void libera_lista_n(lista_n *lista){
   NodeN *aux = lista->inicio;

   while (lista->inicio != NULL){
      lista->inicio = lista->inicio->prox;
      free(aux);
      aux = lista->inicio;
   }
   free(lista);
}