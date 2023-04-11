#include "libcodificar.h"

#include <stdlib.h>
#include<time.h>
#include <string.h>

void codificar_mensagem_original(char *messagem_original, lista_t *chaves, char *saida){
    
    FILE *arq_e, *arq_s;
    char *palavra = malloc (sizeof(char)*LINESIZE);
    
    // abre o arquivo em leitura
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
    // codificar_palavra(palavra,arq_s, chaves);

    while (! feof (arq_e)) {

        codificar_palavra(palavra,arq_s, chaves);

        fscanf (arq_e, "%s", palavra);  // tenta ler a próxima linha
        if (! feof (arq_e)) 
            fprintf(arq_s,"-1 ");

    }
    fprintf (arq_s, "\n");
 
    // fecha o arquivo
    fclose (arq_e);
    fclose(arq_s);
}

void codificar_palavra(char *palavra, FILE *arq_s, lista_t *chaves){

    char c;
    int num;
    Node *aux;
    
    for (int i = 0; i < strlen(palavra); i++){
        
        c = palavra[i];

        aux = buscar_lista_c(chaves,c);
        if (aux == NULL){
            printf("errooo");
            exit(1);
        }
        else{
            printf("%c", c);        
            num = gerar_num(aux);
            fprintf(arq_s,"%d ", num);
        }
    }

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

