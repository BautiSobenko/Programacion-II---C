#include <stdio.h>

#define Tam 9

//BUSQUEDA

//Prototipo
int Busqueda(int A[], int n);

int main(){

    int A[Tam] = {1,2,3,4,5,6,7,8,9};
    int n,pos;

    printf("Ingrese valor n: ");
    fflush(stdin);
    scanf("%d",&n);

    //Como lo usamos multiples veces
    //le asigno una variable (Pos)
    pos = Busqueda(A,n); // --> Debo pasa unicamente el nombre de la variable

    (pos!=-1)?printf("\nEl valor se encuentra en la posicion [%d]\n",pos):printf("\nEl valor no se encuentra en el arreglo :c \n");

    return 0;
}

int Busqueda(int A[],int n){

    int i=0;

    /* Condiciones de busqueda:
    1) Mientras no se termine el array y
    2) Mientras no se encuentre el dato
    3) Sigo buscando en el array
    */

    while((i<=Tam)&&(A[i]!=n)){
        i++;
    }
    if(i>Tam){
        return -1; //False
    }else
        return i; //Posicion en array

}
