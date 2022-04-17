/*
Imprimir el alfabeto con mayusculas con puntero
*/

#include <stdio.h>

int main(){

    char letra,*pLetra;

    pLetra = &letra;

    for(letra='A'; letra<='Z'; letra++){
        printf("%c ",*pLetra);
    }


    return 0;
}
