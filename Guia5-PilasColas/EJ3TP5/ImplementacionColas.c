#include "InterfaceColas.h"

void IniciaC(Cola *C){
    C->primero=NULL;
    C->ultimo=NULL;
}

void Encolar(Cola *C,TelementoC x[]){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->sig = NULL;
    strcpy(aux->dato,x);
    if(!C->primero){
        C->primero = aux;
    }else
        C->ultimo->sig = aux;
    C->ultimo = aux;
    printf("%s encolado con exito!\n",x);
}

void Desencolar(Cola *C,TelementoC x[]){
    if(C->primero){
        Nodo *aux = C->primero;
        strcpy(x,aux->dato);
        C->primero = C->primero->sig;
        printf("%s Desencolado\n",aux->dato);
        free(aux);
    }else
        printf("\nCola acutalmente vacia.\n");
}

int VaciaC(Cola C){
    return (!C.primero->sig);
}
