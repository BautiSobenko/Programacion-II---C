#include <stdio.h>

//Programa para conocer los divisores de un numero

int main(){
    int N,i,cont=0;

    printf("Ingrese un numero para conocer sus divisores: ");
    scanf("%d",&N);
    printf("\n");

    for (i=1; i<=N ; i++){
        if (N%i==0) {
            printf("%d  ",i);
            cont++;
        }
    }
    if (cont>2)
        puts("--> Numero compuesto");
    else
        puts("--> Numero primo");

    return 0;
}
