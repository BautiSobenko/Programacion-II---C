#include <stdio.h>

int Sumar(int,int); //PROTOTIPO (especifico el tipo de dato de parametro)

int main() {

    int a,b;

    printf("Ingrese 2 valores (a y b) para realizar su suma: ");
    scanf("%d %d",&a,&b);

    printf("\nLa suma de a y b es: %d\n",Sumar(a,b));//INVOCACION DE FUNCION

    return 0;
}

int Sumar(int n1,int n2){ //DEFINICION DE FUNCION
    int suma=0;

    suma = n1+n2;

    return suma;
}
