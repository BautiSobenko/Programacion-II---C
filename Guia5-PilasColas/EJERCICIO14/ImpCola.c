
#include "IntCola.h"

void IniciaC(Cola *C){

    C->primero = NULL;
    C->ultimo = NULL;

}

void AgregaC(Cola *C,TelementoC x){

    NodoC* aux = (NodoC*)malloc(sizeof(NodoC));
    aux->dato = x;
    aux->sig = NULL;
    if(!C->primero)
        C->primero = aux;
    else
        C->ultimo->sig = aux;
    C->ultimo = aux;
}

void QuitarC(Cola *C,TelementoC* x){

    if(C->primero){
        NodoC* aux = C->primero;
        *x = C->primero->dato;
        C->primero = C->primero->sig;
        free(aux);
    }else
        printf("\nCola actualemente vacia.\n");
}

int VaciaC(Cola C){
    return (!C.primero)?1:0;
}

TelementoC ConsultaC(Cola C){
    return C.primero->dato;
}

void MostrarC(Cola C){

    printf("\n-------------------------------------------\n");

    while(C.primero!=NULL){
        printf("|%s|\n",C.primero->dato);
        C.primero = C.primero->sig;
    }
    printf("NULL\n");
    printf("\n-------------------------------------------\n");
}

void LiberarC(Cola *C){

    Cola aux;
    while(C->primero!=NULL){
        aux.primero = C->primero;
        C->primero = C->primero->sig;
        free(aux.primero);
    }
    printf("\nCola liberada con exito!\n");
}

int LargoC(Cola C){

    int cont=0;

    while(C.primero){
        cont++;
        C.primero = C.primero->sig;
    }
    return cont;

}


