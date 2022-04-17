#include <stdio.h>

int main(){
    int N,i=1,mult=1,suma=0;

    puts("Ingrese un numero: ");
    scanf("%d",&N);

    if (N>10){
        while (i<=10){
            mult *= i;
            i++;
        }
    printf("%d <= 10 --> Mult = %d",N,mult);
    }else {
        while (i<=10){
            suma += i;
            i++;
    }
    printf("%d > 10 --> Suma = %d",N,suma);
    }

    return 0;
}
