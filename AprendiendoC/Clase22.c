#include <stdio.h>

int main(){

    int A[10] = {4,0,6,-2,14,2,3,6,5,-54};
    int B[10] = {45,0,6,-2,14,2,3,6,5,-54};
    int i,aux,cambios;

    //Ordenamiento ascendente BURBUJA

    do{
    cambios = 0;
    for(i=0; i<9 ; i++)//Hasta 1 menos que el numero de elemento del array, esto me permite el uso de i+1
        if(A[i]>A[i+1]){
            aux = A[i+1];
            A[i+1] = A[i];
            A[i] = aux;
            cambios = 1;  //Si hubo un intercambio, incremenento 1=TRUE
        }
    }while(cambios!=0); //El ciclo finaliza cuando no haya mas cambios


    for(i=0; i<10; i++)
        printf("%d  ",A[i]);

    printf("\n\n");


    //Ordenamiento descendente BURBUJA

    do{
    cambios = 0;
    for(i=0; i<9 ; i++) //Hasta 1 menos que el numero de elemento del array, esto me permite el uso de i+1
        if(B[i]<B[i+1]){
            aux = B[i];
            B[i] = B[i+1];
            B[i+1] = aux;
            cambios = 1;  //Si hubo un intercambio, incremenento 1=TRUE
        }
    }while(cambios!=0); //El ciclo finaliza cuando no haya mas cambios

    for(i=0; i<10; i++)
        printf("%d  ",B[i]);

    return 0;
}
