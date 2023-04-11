#include <stdio.h>
#include <stdlib.h>
#include "liblistacarect.h"
#include "liblistanum.h"


void insere_carcter(lista_t *lista, char elemento, int i){

   Node *node = criaNode();
   node->letra = elemento;
   insere_numero(node->listaN, i);

   Node *aux = criaNode();

   //se a lista é vazio
   if (listaVazia(lista) == 0){

      node->prox = NULL;
      lista->inicio = node;
      (lista->tam)++;
   
   }
   //é menor que o primeiro
   else if (node->letra < lista->inicio->letra){
      
      node->prox = lista->inicio;
      lista->inicio = node;
      (lista->tam)++;

   }

   //se for igual o primiero 
   else if (node->letra == lista->inicio->letra){
      insere_numero(lista->inicio->listaN, i);
      // printf("igual");

   }

   //inserir no meio ou no final 
   else {
      aux = lista->inicio;
      while ( aux->prox && (node->letra >= aux->prox->letra) ){
         aux = aux->prox;
      }
      if (node->letra == aux->letra){
         insere_numero(aux->listaN, i);
         // printf("igual");
      }
      else {
         node->prox = aux->prox;
         aux->prox = node;
         (lista->tam)++;
      }
      
   }
}


lista_t *cria_lista_c(){

   lista_t *lista = (lista_t *) malloc(sizeof(lista_t));
   lista->inicio=NULL;
   lista->tam=0;

   return lista;
}

Node *criaNode(){

   Node *node = (Node *) malloc(sizeof(Node));
   node->prox = NULL;
   node->letra = 0;
   node->listaN = cria_lista_n();

   return node;
}

int listaVazia(lista_t *lista){
   
   if (lista->tam == 0)
      return 0;
   return 1;

}

Node *buscar_lista_c(lista_t *lista, char c){

   Node *aux = lista->inicio;

   for (int i = 0; i < lista->tam; i++){

      if (aux->letra == c ){
         return aux;
      }
      aux = aux->prox; 
   }
   return NULL;


}



/*-----------------GERAL DAS DUAS LISTAS ------------------*/

// void libera_lista(lista_t *lista){
   
//    Node *aux = lista->inicio;

//    while (lista->inicio == NULL){
//       lista->inicio = lista->inicio->prox;
//       free(aux->nome);
//       free(aux->tipo);
//       free(aux);
//       aux = lista->inicio;
//    }
//    free(lista);
// }

void exibe_lista_c(lista_t *lista){

   Node *aux = lista->inicio;
   printf("exibe lista: \n");

   for (int i = 0; i < lista->tam; i++){
      printf("%c: ", aux->letra);
      exibe_lista_n(aux->listaN);
      printf("\n");
      aux = aux->prox; 
   }
   printf("\n");
   
}