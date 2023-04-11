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

        elem = separa_caractere(palavra); //separa 

        insere_carcter(chaves, elem, i);

        fscanf (arq, "%s", palavra);  // tenta ler a próxima linha
        i++;
    }
 
    // fecha o arquivo
    fclose (arq);
}

