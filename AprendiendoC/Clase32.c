/*
Numeros pares de un arreglo con pointer
*/

#include <stdio.h>

int main(){

    int array[7] = {1,2,3,4,5,6,7};
    int *pArray;

    pArray = &array[0];

    for(int i=0; i<7 ;i++){
        if(*pArray%2==0)
            printf("\nA[%d] = %d --> %p",i,*pArray,pArray);
        pArray++; //Paso a la siguiente pos. en memoria
    }

    return 0;
}

