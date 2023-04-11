#include "liblistanum.h" 

void insere_numero(lista_n *lista, int num){
   
   NodeN *node = criaNode_n();
   node->num = num;
   
   
   node->prox = lista->inicio;
   lista->inicio = node;

   // printf("%p, %p, %p\n", node->prox, lista->inicio, node);
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