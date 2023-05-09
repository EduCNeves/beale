#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "libleitura.h"
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
    int cb = -1; //variavel para ver se é para ler o livro de cifra ou o arquivo de chaves
    int option;

    // lendo os parametros
    while ( (option = getopt(argc, argv, "deb:m:o:c:i:")) != -1)
        switch (option){
        case 'e'://codificar
            edu = 0;
            break;
        case 'd'://decodificar
            edu = 1;
            break;
        case 'b':
            cb = 1; //saber se vai decodificar com o livro de cifra ou com o arquivo de chaves
            strcpy(livro_cifra, optarg);
            break;
        case 'm':
            strcpy(mensagem_original, optarg);
            break;
        case 'o':
            strcpy(saida, optarg);
            break;
        case 'c':
            cb = 0; //saber se vai decodificar com o livro de cifra ou com o arquivo de chaves
            strcpy(arquivo_de_chaves, optarg);
            break;
        case 'i':
            strcpy(mensagem_codificada, optarg);
            break;
        default:
            fprintf(stderr, "Passagem incorreta de parametros\n");
            exit(1);
        }

    // crianco a lista de chaves
    lista_t *chaves = cria_lista_c();

    // testando se é para codificar ou decodificar
   if (edu == 0){
        //codificando a mensagem
        ler_livro_cifra(livro_cifra, chaves);
        int cod = codificar_mensagem_original(mensagem_original, chaves, saida);
        if (cod == 1){
            printf("não é possivel codificar essa mensagem\n");
        }
        else {
            printf("mensagem codificada com sucesso\n");
        }
        imprimir_arquivos_de_chaves(arquivo_de_chaves, chaves);

    }
    else {
        //decodificando a mensagem
        if (cb == 0){
            //decodificando com o arquivo de chaves
            ler_arquivos_de_chaves(arquivo_de_chaves,chaves);
            int deco = decodificar_mensagem_codificada(mensagem_codificada, chaves, saida);
            if (deco == 1){
                printf("não é possivel decodificar essa mensagem\n");
            }
            else {
                printf("mensagem decodificada com sucesso\n");
            }
        }
        else{
            //decodificando com o livro de cifra
            ler_livro_cifra(livro_cifra, chaves);
            int deco = decodificar_mensagem_codificada(mensagem_codificada, chaves, saida);
            if (deco == 1){
                printf("não é possivel decodificar essa mensagem\n");
            }
            else {
                printf("mensagem decodificada com sucesso\n");
            }
        }
    }

    // liberando a memoria
    libera_lista_c(chaves);
    free(livro_cifra);
    free(mensagem_original);
    free(saida);
    free(arquivo_de_chaves);
    free(mensagem_codificada);
    
    return 0;
}