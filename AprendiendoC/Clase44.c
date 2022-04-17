//! realloc

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vector;;
    int i;

    vector = malloc(3*sizeof(int)); //Array dinamico de 4 elementos

    if(vector==NULL){
        puts("No hay espacio en memoria");
        return 1;
    }else{
        puts("Memoria asignada con exito!");
    }

    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;

    for(i=0; i<3; i++)
        printf("[%d] = %d",i,vector[i]);

    //realloc

    vector = realloc(vector,5*sizeof(int));

    vector[3] = 4;
    vector[4] = 5;
    printf("\n\n");

    for(i=0; i<5; i++)
        printf("[%d] = %d",i,vector[i]);

    printf("\n");

    free(vector);


    return 0;
}
