#include <stdio.h>

int main(){

    int A,meses,semanas,dias,horas,minutos,segundos;

    printf("Digite cantidad de anios: ");
    scanf("%d",&A);

    meses = A*12;
    semanas = meses*4;
    dias = semanas*7;
    horas = dias*24;
    minutos = horas*60;
    segundos = minutos*60;

    printf("\nViviste un total de %d segundos\n",dias);


    return 0;
}
