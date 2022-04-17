#include <stdio.h>
#include <stdlib.h>

void valorMax(int *);
void rellenaDatos(int,int*);
void muestraDatos(int,int*);

int main(){

    int *p_array,N;

    valorMax(&N);

    p_array = (int*)calloc(N,sizeof(int));

    if(p_array == NULL){
        printf("Memoria no disponible");
        return 1;
    }

    rellenaDatos(N,p_array);

    muestraDatos(N,p_array);

    /*
    No hace falta pasar un arreglo por referencia
    Ya el simple hecho de que tenga [x] es una referencia
    implicita
    */

    free(p_array);

    return 0;
}

void valorMax(int *pN){

    printf("Ingrese valor maximo del arreglo: ");
    scanf("%d",pN);
}

void rellenaDatos(int N,int arrayDatos[]){

printf("\nIngrese los elementos del arreglo: \n");

    for(int i=0; i<N ; i++){
        printf("\n[%d] = ",i);
        scanf("%d",&arrayDatos[i]);
    }
}

void muestraDatos(int N,int arrayDatos[]){

printf("\nMuestra del arreglo dinamico ingresado: ");

    for(int j=0; j<N; j++){
        printf("[%d] = %d\t",j,arrayDatos[j]);
    }
    printf("\n");

}
