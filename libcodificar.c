#include "libcodificar.h"

#include <stdlib.h>
#include<time.h>
#include <string.h>

int codificar_mensagem_original(char *messagem_original, lista_t *chaves, char *saida){
    
    FILE *arq_e, *arq_s;
    char *palavra = malloc (sizeof(char)*LINESIZE);
    int codi = 0;

    // abre o arquivo da mensagem original em leitura
    arq_e = fopen (messagem_original, "r") ;
    if ( ! arq_e ) {
     perror ("Erro ao abrir arquivo") ;
     exit (1);
    }

    //abre o arquivo de saida
    arq_s = fopen (saida, "w") ;
    if ( ! arq_s ) {
     perror ("Erro ao abrir arquivo") ;
     exit (1);
    }

    fscanf (arq_e, "%s", palavra);

    while (! feof (arq_e)) {

        codi = codificar_palavra(palavra,arq_s, chaves);
        if (codi == 1){
            free(palavra);
            fclose (arq_e);
            fclose(arq_s);
            return 1;
        }

        fscanf (arq_e, "%s", palavra);  //le a proxima palavra
        if (! feof (arq_e)) 
            fprintf(arq_s,"-1 ");

    }
    fprintf (arq_s, "\n");
    
    free(palavra);
    // fecha o arquivo
    fclose (arq_e);
    fclose(arq_s);
    
    return 0;

}

int codificar_palavra(char *palavra, FILE *arq_s, lista_t *chaves){

    char c;
    int num;
    Node *aux;
    
    for (int i = 0; i < strlen(palavra); i++){
        
        c = palavra[i];
        
        //tornar as letras minusculas
        if(c >= 'A' && c <= 'Z'){
            c += 32;
        }

        aux = buscar_lista_c(chaves,c);
        if (aux == NULL){
           return 1;
        }
        else{        
            num = gerar_num(aux);
            fprintf(arq_s,"%d ", num);
        }
    }

    return 0;

}

int gerar_num(Node *aux){

    int n;
    n = rand() % aux->listaN->tam;

    NodeN *node = aux->listaN->inicio;

    for (int i = 0; i < n; i++){
       node = node->prox; 
    }
    return node->num;

}