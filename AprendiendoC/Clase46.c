/*Hacer un puntero array de tipo float, pedir el usuario el numero de
elementos,luego reservar memoria dinamica con calloc, luego llenar
el array, imprimir todos los elementos, y por ultimo liberar el espacio
de memoria dinamica utilizado.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    float *p_array;
    int N;

    printf("Ingrese el numero de elementos del arreglo: ");scanf("%d",&N);

    p_array = (float*)malloc(N*sizeof(float));

    if(p_array==NULL){
        printf("Memoria no disponible");
        return 1;
    }
    printf("Digite valores del arreglo: \n\n");

    for(int i=0; i<N ;i++){
        printf("\n[%d] = ",i);
        scanf("%f",&p_array[i]);
    }

    printf("Arreglo obtenido: \n\n");

    for(int j=0; j<N ;j++){
        printf("[%d] = %.2f\t ",j,p_array[j]);
    }

    free(p_array);


    return 0;
}

