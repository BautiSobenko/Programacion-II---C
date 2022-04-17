#include <stdio.h>
#include <stdlib.h>

int main(){

    int *dinamico = (int*)malloc(4*sizeof(int));

    //Array dinamico de 4 elementos

    *dinamico = 10; // pos 0
    *(dinamico+1) = 20; //pos 1
    dinamico[2] = 30; //pos 2;

    /*
    Podemos imprimir lo que hay en memoria con:
    *(dinamico+1) --> Forma de puntero
    dinamico[1] --> Forma de arreglo
    Ambas formas son equivalentes.
    */



    return 0;
}
