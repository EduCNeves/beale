#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "leitura.h"
#include "liblistacarect.h"
#include "libimprimir.h"
#include "libcodificar.h"
#include "libdecodificar.h"



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
        int cod = codificar_mensagem_original(mensagem_original, chaves, saida);
        if (cod == 1){
            printf("não é possivel codificar essa mensagem\n");
        }
        imprimir_arquivos_de_chaves(arquivo_de_chaves, chaves);

    }
    else {
        printf("Decodificar: %d\n", edu);
        if (cb == 0){
            ler_arquivos_de_chaves(arquivo_de_chaves,chaves);
            exibe_lista_c(chaves);
            int deco = decodificar_mensagem_codificada(mensagem_codificada, chaves, saida);
            if (deco == 1){
                printf("não é possivel decodificar essa mensagem\n");
            }
        }
        else{
            ler_livro_cifra(livro_cifra, chaves);
            int deco = decodificar_mensagem_codificada(mensagem_codificada, chaves, saida);
            if (deco == 1){
                printf("não é possivel decodificar essa mensagem\n");
            }
        }
    }





    
    return 0;
}