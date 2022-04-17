#include <stdio.h>

void agregar(int *a){
    *a += 10;
}

int main(){

    int numero;
    printf("Ingrese numero: "); scanf("%d",&numero);
    printf("\nValor antes de la funcion %d",numero);
    agregar(&numero);
    printf("\nValor despues de la funcion %d",numero);

    /*
    Observamos que el paso de PARAMETRO POR REFERENCIA
    MODIFICA la variable al utilizar
    APUNTADORES
    */

    return 0;
}

