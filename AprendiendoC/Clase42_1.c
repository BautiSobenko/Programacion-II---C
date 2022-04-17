//!Memoria dinamica en arreglos

#include <stdio.h>
#include <stdlib.h> //-> malloc / calloc
#include <string.h>

int main(){

    /*int *p1 = malloc(4*sizeof(int));
    int *p2 = malloc(sizeof(int[4]));
    int *p3 = malloc(4*sizeof(*p3));
    */

    char nombre[20], *p_nombre;
    int longitud;

    strcpy(nombre,"Bautista");
    longitud = strlen(nombre);

    printf("La longitud del nombre es: %d\n",longitud);

    p_nombre = malloc((longitud+1)*sizeof(char));

    strcpy(p_nombre,nombre);
    printf("Nombre: %s",p_nombre);



    return 0;
}
