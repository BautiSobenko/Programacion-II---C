//Apuntadores con Arrays

#include <stdio.h>

int main(){

    int array[5] = {1,2,3,4,5};

    //Apuntador a la primera posicion en memoria del array
    int *pArray = &array[0];

    //Desplazamos el pointer por el array

    while (*pArray != NULL){
        printf("\n %d",*pArray);
        pArray++; // --> Desplazo el apuntador
    }


    return 0;
}
