#include "IntPilaD.h"

int main(){

    p_nodo pila,pilaAux;
    TelementoP n;
    FILE* arch = fopen("datos.txt","rt");
    if(!arch){
        printf("Error en la apertura del archivo\n");
        return 1;
    }
    IniciaP(&pila);
    do{
        fscanf(arch,"%d",&n);
        Apila(&pila,n);
    }while(!feof(arch));


    printf("\n");
    MuestraP(pila);
    printf("\n");

    IniciaP(&pilaAux);

    //Intercambio de pilas

    while(!VaciaP(pila)){
        Desapila(&pila,&n);
        Apila(&pilaAux,-1*n);
    }
    while(!VaciaP(pilaAux)){
        Desapila(&pilaAux,&n);
        Apila(&pila,n);
    }

    printf("\nPILA CAMBIADA DE SIGNO\n\n");
    MuestraP(pila);
    printf("\n");

    fclose(arch);
    //Libero heap
    p_nodo aux = pila;
    while(!VaciaP(pila)){
        pila = pila->sig;
        free(aux);
        aux = pila;
    }


    return 0;
}

