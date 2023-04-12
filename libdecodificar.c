#include "libdecodificar.h"

#include <stdlib.h>
#include<time.h>
#include <string.h>

int decodificar_mensagem_codificada(char *mensagem_codificada, lista_t *chaves, char *saida){
    
    FILE *arq_e, *arq_s;
    char *numero = malloc (sizeof(char)*LINESIZE);
    int deco = 1;
    
    // abre o arquivo em leitura
    arq_e = fopen (mensagem_codificada, "r") ;
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

    fscanf (arq_e, "%s", numero);

    while (! feof (arq_e)) {

        if (strcmp(numero,"-1") != 0){
            deco = decodificar_numero(numero,arq_s, chaves);
            // decodificação deu errado, abortar
            if (deco == 1){
                fclose (arq_e);
                fclose(arq_s);
                return 1;
            }
        } else {
            fprintf(arq_s," ");
        }

        fscanf (arq_e, "%s", numero);  // tenta ler a próxima linha

    }
    fprintf (arq_s, "\n");
 
    // fecha o arquivo
    fclose (arq_e);
    fclose(arq_s);
    
    return 0;
}

int decodificar_numero(char *numero, FILE *arq_s, lista_t *chaves){

    int flag = 1;
    Node *aux = chaves->inicio;

    while (aux && (flag == 1)){

        flag = buscar_lista_n(aux->listaN, numero);
        // printf("aquiii %d", i);
        if (flag == 1){
            aux = aux->prox;
        }
    }
    if (flag == 0){
        fprintf(arq_s,"%c", aux->letra);
    }
    return flag;
}

