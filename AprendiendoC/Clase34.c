/*
Cantidad de vocales en una string (pointers)
*/

#include <stdio.h>

int Vocales(char *);

int main(){

    char name[20];
    char *nombre;

    printf("Ingrese su nombre: ");
    gets(name);

    nombre = &name[0];

    printf("La cantidad de vocales del nombre es: %d",Vocales(nombre));

    return 0;
}

int Vocales(char *nombre){

    int cont=0;

    while(*nombre){ //--> Mientras que el char no sea nulo \0

        switch(*nombre){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': cont++;
        }

        nombre++;
    }

    return cont;
}
