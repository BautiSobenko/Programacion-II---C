#include "Interface.h"

void IniciaC(Cola *C){
    C->primero = NULL;
    C->ultimo = NULL;
}

void AgregaC(Cola *C,TelementoC x){

    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    strcpy(aux->dato,x);
    aux->sig = NULL;
    if(!C->primero)
        C->primero = aux;
    else
        C->ultimo->sig = aux;
    C->ultimo = aux;
    printf("Elemento %s encolado con exito!\n",x);
}

void QuitarC(Cola *C,TelementoC x){

    if(C->primero != NULL){
        Nodo* aux = C->primero;
        strcpy(x,C->primero->dato);
        C->primero = C->primero->sig;
        free(aux);
        printf("Elemento desencolado con exito!\n");
    }else
        printf("\nCola actualemente vacia.\n");
}

int VaciaC(Cola C){
    return (!C.primero)?1:0;
}

TelementoC ConsultaC(Cola C){

    return C.ultimo->dato;
}


void MuestraC(Cola C){
    while (C.primero!=NULL){
        printf("%s\n",C.primero->dato);
        C.primero = C.primero->sig;
    }
    printf("NULL\n");
}


int LargoC(Cola C){

    int cont=0;
    while(C.primero!=NULL){
        cont++;
        C.primero = C.primero->sig;
    }
    return cont;
}

