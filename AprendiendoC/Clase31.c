/*Comprobar si un numero es par o impar
Señalar la pos. de memoria en donde se guarda
*/

#include <stdio.h>

int main(){

    int numero,*pNumero;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    pNumero = &numero; //Guardo la pos. de memoria

    printf("\n");

    (*pNumero%2 == 0)?puts("Numero par"):puts("Numero impar");

    printf("\nLa posicion en memoria del numero es: %p\n",pNumero);



    return 0;
}
