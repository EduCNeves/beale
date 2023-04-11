#include "libseparar.h"

char separa_caractere(char *palavra){

    char c;
    c = palavra[0];

    if(c >= 'A' && c <= 'Z'){
        c += 32;
    }

    return c;

}