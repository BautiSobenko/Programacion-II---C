/*!
a) Sea V un arreglo de enteros, se pide:
I. Calcular e informar la suma de sus elementos.
II. Mostrar sus elementos.
III. Mostrar sus elementos en orden inverso.
*/

#include <stdio.h>

#define MaxElem 5

int sumaRec(int array[],int N);
void muestraRec(int array[],int N);
void muestraInvRec(int array[],int N);

int main(){

    int array[MaxElem] = {1,2,3,4,5};


    printf("La suma de los elementos del arreglo es: %d\n",sumaRec(array,MaxElem-1));

    printf("\nMuestra de los elementos del arreglo: \n");

    muestraRec(array,MaxElem-1);

    printf("\n\n");

    muestraInvRec(array,MaxElem-1);

    printf("\n");

    return 0;
}

int sumaRec(int array[],int N){

    if(N==0)
        return array[N];
    else
        return (array[N]+sumaRec(array,N-1));
}

void muestraRec(int array[],int N){

    if(N>=0){
        muestraRec(array,N-1);
        printf("\n[%d] = %d",N,array[N]);
    }
}

void muestraInvRec(int array[],int N){

    if(N>=0){
        printf("\n[%d] = %d",N,array[N]);
        muestraInvRec(array,N-1);
    }
}


