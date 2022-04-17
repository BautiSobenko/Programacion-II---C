#include <stdio.h>

int main(){

    int a = 10;
    int b = 20;

    int *pA = &a;
    int *pB = &b;

    //Cambiamos valor al apuntador
    //Como esta apuntando a la posicion en memoria de a
    //Cambiamos el valor de la variable a la que apuntaba

    *pA = 144;

    printf("%d",a);


    return 0;
}
