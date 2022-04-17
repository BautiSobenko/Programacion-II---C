#include <stdio.h>
#include <string.h>

/*
strlen(Cadena);
Devuelve un entero que representa la longitud de la cadena
*/

int main(){
    char arreglo[200];

    printf("Escribe cualquier cosa: ");
    fflush(stdin);
    gets(arreglo);
    printf("La longitud del arreglo es de: %d",strlen(arreglo));

    return 0;
}

