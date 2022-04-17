#include <stdio.h>

/* struct
   Coleccion de datos de diferentes tipos
*/

struct persona{
    char nombre[20];
    int edad;
    char carrera[30];
}
//Variables que tendran dicha estructura
persona1 = {"Bautista",20,"Ing.Informatica"},
persona2 = {"Juan",20,"Medicina"};

int main(){

    printf("Alumno 1: \n");
    printf("%s\n",persona1.nombre);
    printf("%d\n",persona1.edad);
    printf("%s\n",persona1.carrera);

    printf("\nAlumno 2: \n");
    printf("%s\n",persona2.nombre);
    printf("%d\n",persona2.edad);
    printf("%s\n",persona2.carrera);

    return 0;
}
