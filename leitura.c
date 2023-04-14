#include "leitura.h"
#include "libseparar.h"

void ler_livro_cifra(char *livro_cifra, lista_t *chaves){
    
    FILE *arq;
    char *palavra = malloc (sizeof(char)*LINESIZE);
    int i;
    
    // abre o arquivo em leitura
    arq = fopen (livro_cifra, "r") ;
    if ( ! arq ) {
     perror ("Erro ao abrir arquivo") ;
     exit (1);
    }

    i = 0;
    char elem;

    fscanf (arq, "%s", palavra);
    while (! feof (arq)) {

        elem = separa_caractere(palavra); //separa o caractere da palavra

        insere_caracter(chaves, elem, i);

        fscanf (arq, "%s", palavra);  // tenta ler a próxima linha
        i++;
    }

    free(palavra);
 
    // fecha o arquivo
    fclose (arq);
}


void ler_arquivos_de_chaves(char *arquivo_de_chaves, lista_t *chaves){

    FILE *arq;
    char *palavra = malloc (sizeof(char)*LINESIZE);
    Node *aux;
    
    // abre o arquivo em leitura
    arq = fopen (arquivo_de_chaves, "r") ;
    if ( ! arq ) {
     perror ("Erro ao abrir arquivo") ;
     exit (1);
    }

    fscanf (arq, "%s", palavra);
    // printf("palavra: %s\n", palavra);
    insere_caracter(chaves,palavra[0],-1);
    aux = chaves->inicio;
    while (! feof (arq)) {

        fscanf (arq, "%s", palavra);  //ler a próxima palavra
        // printf("palavra: %s\n", palavra);
        
        if(palavra[1] == ':'){
            insere_caracter(chaves,palavra[0], -1);
            aux = aux->prox;
        }
        else {
            int num = atoi(palavra);
            // printf("num0: %d\n", num);

            insere_numero(aux->listaN, num);
        }

    } 

    free(palavra);
    // fecha o arquivo
    fclose (arq);

}
