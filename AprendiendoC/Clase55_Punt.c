/*!4. Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución.*/

#include <stdio.h>
#include <stdlib.h>


void ingresaArreglo(int p[], int N); // *p => p[]
void positivos(int *p,int N);

int main(){

    int N;

    printf("Ingrese cuantos elementos desea que tenga el arreglo: ");
    scanf("%d",&N);

    int *p = (int*)calloc(N,sizeof(int));

    ingresaArreglo(p,N); //Paso de parametro la direccion en memoria heap del arreglo dinamico creado

    //printf("\n%d\n",p[2]);  p[2] => *(p+2)

    positivos(p,N);


    return 0;
}

void ingresaArreglo(int p[],int N){

printf("\nIngrese elementos del arreglo: \n");

for(int i=0; i<N ;++i){
    fflush(stdin);
    printf("[%d] = ",i);
    scanf("%d",&p[i]);
}
}

void positivos(int *p, int N){

printf("\n");

for(int i=0; i<N; ++i){
    if(*(p+i)>=0)
        printf("\n%d POSITIVO ",*(p+i));
}
printf("\n");
}
