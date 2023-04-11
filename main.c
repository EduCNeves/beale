#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "leitura.h"
#include "liblistacarect.h"
#include "libimprimir.h"
#include "libcodificar.h"


#define LINESIZE 1024



int main(int argc, char **argv){

    srand(time(NULL));

    char *livro_cifra = malloc (sizeof(char)*LINESIZE);
    livro_cifra[0] = '\0';

    char *mensagem_original = malloc (sizeof(char)*LINESIZE);
    mensagem_original [0] = '\0';

    char *saida = malloc (sizeof(char)*LINESIZE);
    saida [0] = '\0';

    char *arquivo_de_chaves = malloc (sizeof(char)*LINESIZE);
    arquivo_de_chaves [0] = '\0';

    char *mensagem_codificada = malloc (sizeof(char)*LINESIZE);
    mensagem_codificada [0] = '\0';


    int edu = -1; //variavel para ver se é para codificar ou decodificar 
    int cb = -1;
    int option;

    while ( (option = getopt(argc, argv, "deb:m:o:c:i:")) != -1)
        switch (option){
        case 'e':
            edu = 0;
            break;
        case 'd':
            edu = 1;
            break;
        case 'b':
            cb = 1;
            strcpy(livro_cifra, optarg);
            break;
        case 'm':
            strcpy(mensagem_original, optarg);
            break;
        case 'o':
            strcpy(saida, optarg);
            break;
        case 'c':
            cb = 0;
            strcpy(arquivo_de_chaves, optarg);
            break;
        case 'i':
            strcpy(mensagem_codificada, optarg);
            break;
        default:
            fprintf(stderr, "Passagem incorreta de parametros\n");
            exit(1);
        }

    lista_t *chaves = cria_lista_c();

   if (edu == 0){
    
        ler_livro_cifra(livro_cifra, chaves);
        codificar_mensagem_original(mensagem_original, chaves, saida);
        imprimir_arquivos_de_chaves(arquivo_de_chaves, chaves);

    }
    else {
        printf("Decodificar: %d\n", edu);
        if (cb == 0){
            printf(" %d\n", cb);
            printf("-i %s\n", mensagem_codificada);
            printf("-c %s\n", arquivo_de_chaves);
            printf("-o %s\n", saida);

        }
        else{
            printf("%d\n", cb);
            ler_livro_cifra(livro_cifra, chaves);
            printf("-i %s\n", mensagem_codificada);
            printf("-o %s\n", saida);
        }
    }

        // exibe_lista_c(chaves);
        // printf("tam lista = %d", chaves->tam);



    
    return 0;
}