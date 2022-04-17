//Paso de paramentro de array

#include <stdio.h>

void Llenar(int array[],int dimension){

    for(int i=0; i<dimension ; i++){
        printf("A[%d] = ",i);
        scanf("%d",&array[i]);
    }
}

int main(){

    int miArray[5];

    //Solo pasamos nombre del array y su dimension

    Llenar(miArray,5);

    for(int i=0; i<5 ; i++)
        printf("\nA[%d] = %d ",i,miArray[i]);


    return 0;
}
