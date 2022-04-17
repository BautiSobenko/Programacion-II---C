#include <stdio.h>

int main(){

    int numero;

    printf("Escribe el numero que sera ignorado: ");
    scanf("%d",&numero);

    for (int i=1; i<=20 ; i++){
        if(i == numero)
            continue;
        printf("\n%d",i);
    }
    /*Continue: Sirve para terminar una
    iteracion y seguir dentro del ciclo*/

    /*Break: Sirve para terminar con la
    iteracion y salir del ciclo*/

    return 0;
}
