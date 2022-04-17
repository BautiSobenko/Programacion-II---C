//!c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.

#include <stdio.h>
#include <stdlib.h>
#define MaxCol 3
#define MaxFila 3

int busquedaMinRec(int matriz[][MaxCol],int N,int M,int M2,int min);

int main(){

    int matriz[MaxFila][MaxCol] = {{1,2,3},{4,-8,5},{4,3,6}};

    printf("El minimo del arreglo es: %d",busquedaMinRec(matriz,MaxFila-1,MaxCol-1,MaxCol-1,0));

    return 0;
}

int busquedaMinRec(int matriz[][MaxCol],int N,int M,int M2,int min){

    if(N>=0){
        if(M>=0){
            if(matriz[N][M]<min)
                min = busquedaMinRec(matriz,N,M-1,M2,matriz[N][M]);
            else
                busquedaMinRec(matriz,N,M-1,M2,min);
        }else
            busquedaMinRec(matriz,N-1,M2,M2,min);
    }else
        return min;
}
