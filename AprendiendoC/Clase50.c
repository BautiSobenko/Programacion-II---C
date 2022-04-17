#include <stdio.h>

void f(int *);

int main(){

    int a=10;

    f(&a);

    printf("Valor modificado: %d",a);

    printf("\nValor de a: %d\n",a);

    return 0;
}

void f(int *x){

    *x=3;

}
