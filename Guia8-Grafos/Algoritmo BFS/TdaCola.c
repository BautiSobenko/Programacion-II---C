#include "TdaCola.h"

void IniciaC(TCola *C){

    C->primero = NULL;
    C->ultimo = NULL;

}

void AgregaC(TCola *C,TelementoC x){

    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = x;
    aux->sig = NULL;
    if(!C->primero)
        C->primero = aux;
    else
        C->ultimo->sig = aux;
    C->ultimo = aux;
    printf("\nEl elemento %d se agrego a la cola\n",x);
}

void QuitarC(TCola *C,TelementoC* x){

    if(C->primero){
        Nodo* aux = C->primero;
        *x = C->primero->dato;
        C->primero = C->primero->sig;
        free(aux);
        printf("\nEl elemento %d se quito de la cola\n",*x);
    }else
        printf("\nCola actualemente vacia.\n");
}

int VaciaC(TCola C){
    return (!C.primero)?1:0;
}

TelementoC ConsultaC(TCola C){
    return C.primero->dato;
}

void MostrarC(TCola C){

    printf("\n-------------------------------------------\n");

    while(C.primero!=NULL){
        printf("|%d|\n",C.primero->dato);
        C.primero = C.primero->sig;
    }
    printf("NULL\n");
    printf("\n-------------------------------------------\n");
}

void LiberarC(TCola *C){

    Cola aux;
    while(C->primero!=NULL){
        aux.primero = C->primero;
        C->primero = C->primero->sig;
        free(aux.primero);
    }
    printf("\nCola liberada con exito!\n");
}

int LargoC(TCola C){

    int cont=0;

    while(C.primero){
        cont++;
        C.primero = C.primero->sig;
    }
    return cont;

}


