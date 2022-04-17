//Factorial de un numero

#include <stdio.h>

int main(){

    int N,i=1,Fact=1;
    puts("Ingrese un valor de N para calcular su factorial: ");
    scanf("%d",&N);

    while (i<=N){
        Fact *= i;
        i++;
    }
/*
0! = 1;
1! = 1;
2! = 2;
3! = 2.3 = 6
*/

printf("\n%d! = %d\n",N,Fact);

    return 0;
}

