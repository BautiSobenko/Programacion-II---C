#include <stdio.h>
#include <stdlib.h>

///DEFINICION TIPO LISTA

typedef struct Nodo{
    int dato;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

///PROTOTIPOS

void DestruirLista(TLista *L);

void DestruirAparicionesX(TLista *L,int x);

void DestruirOrdAparicionesX(TLista *L,int x);


int main(){

    TLista L = NULL;
    int x;

    DestruirLista(&L);

    DestruirAparicionesX(&L,x);

    DestuirOrdAparicionesX(&L,x);




    return 0;
}

void DestruirLista(TLista *L){

    TLista aux=*L;
    while( aux != NULL ){
        *L = *L->sig;
        free(aux);
        aux = *L;
    }
}

void DestruirAparicionesX(TLista *L,int x){

    TLista ant = NULL
    TLista act = *L;
    TLista elim;
    while( act != NULL ){
        if( act->dato == x ){
            elim = act;
            if(act == *L){ ///CASO CABEZA
                *L = (*L)->sig;
            }else
                act = act->sig;
            ant->sig = act;
            free(elim);
        }else{
            ant = act;
            act = act->sig;
        }
    }
}

void DestruirOrdAparicionesX(TLista *L,int x){

    TLista ant = NULL,act = *L;
    TLista elim;
    while(act != NULL && x >= act->dato){
        if( act->dato == x ){
            elim = act;
            if(act == *L){
                *L = (*L)->sig;
                act = *L;
            }else{
                act = act->sig;
            ant->sig = act;
            }
            free(elim);
        }else{
            ant = act;
            act = act->sig;
        }
    }
}








