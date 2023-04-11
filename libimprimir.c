#include <stdio.h>
#include <stdlib.h>

#include "libimprimir.h"
#include "liblistacarect.h"

//saida de arquivos de chaves
void imprimir_arquivos_de_chaves(char *arquivo_de_chaves, lista_t *chaves){

    FILE* arq ;
    
    arq = fopen (arquivo_de_chaves, "w");
    
    if ( ! arq ){
        perror ("Erro ao abrir/criar arquivo x");
        exit (1) ; // encerra o programa com status 1
    }

    Node *aux = chaves->inicio;

    for (int i = 0; i < chaves->tam; i++){

        fprintf (arq, "%c: ", aux->letra);

        //lista de numeros
        NodeN *aux1 = aux->listaN->inicio;
        for (int i = 0; i < aux->listaN->tam; i++){
            fprintf (arq, "%d ", aux1->num);
            aux1 = aux1->prox; 
        }
        fprintf (arq, "\n");
   
      
      aux = aux->prox; 
    }
    
    fclose (arq);

}