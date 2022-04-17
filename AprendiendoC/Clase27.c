#include <stdio.h>

int agregar(int a){
    a += 10;
    return a;
}

int main(){

    int numero;
    printf("Ingrese numero: "); scanf("%d",&numero);
    printf("\nValor antes de la funcion %d",numero);
    agregar(numero);
    printf("\nValor despues de la funcion %d",numero);

    /*
    Observamos que el paso de PARAMETRO POR VALOR
    NO MODIFICA a la variable
    */

    return 0;
}
