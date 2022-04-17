#include <stdio.h>
#include <stdlib.h>

///DEFINICION DE TIPO Y NODO

typedef int TelementoL;

typedef struct Nodo{
    TelementoL dato;
    struct Nodo *sig;
}Nodo;

typedef Nodo* TLista;

///CONSTANTES

#define MAX 9 //Max arreglo

///PROTOTIPOS

void IngresoPorCabeza(TLista *lista,TelementoL n);

void IngresoPorCola(TLista *lista,TelementoL n);

void IngresoOrdeno(TLista *lista,TelementoL n);

void OrdenaLista(TLista lista);

void MuestraLista(TLista lista);

///PRINCIPAL

int main(){

    TLista lista;
    lista = NULL;
    TelementoL n[MAX] = {1,4,2,-3,5,3,-6,1,8};
    int i;

    for(i=0; i<MAX; i++){
        IngresoPorCabeza(&lista,n[i]);
    }

    MuestraLista(lista);
    lista = NULL;
    printf("\n\n");

   for(i=0; i<MAX; i++){
        IngresoPorCola(&lista,n[i]);
    }
    MuestraLista(lista);
    printf("\n\n");

    lista = NULL;

    for(i=0; i<MAX; i++){
        IngresoOrdeno(&lista,n[i]);
    }

    //OrdenaLista(lista);

    MuestraLista(lista);
    printf("\n");

    return 0;
}

///DESARROLLO DE FUNCIONES

void IngresoPorCabeza(TLista *lista,TelementoL n){

    TLista nuevo;
    nuevo = (TLista)malloc(sizeof(Nodo));
    nuevo->dato = n;
    nuevo->sig = *lista;
    *lista = nuevo;
}

void IngresoPorCola(TLista *lista,TelementoL n){

    TLista nuevo = (TLista)malloc(sizeof(Nodo));
    TLista ant=*lista;

    if(*lista == NULL){ //MODIFICACION CABEZA
        nuevo->dato = n;
        nuevo->sig = *lista; //Apuntaria a NULL
        *lista = nuevo;
    }else{
        while(ant->sig != NULL){
            ant = ant->sig;
        }
        nuevo->dato = n;
        nuevo->sig = NULL;
        ant->sig = nuevo;

    }
}

void IngresoOrdeno(TLista *lista,TelementoL n){

    TLista nuevo;
    TLista act=*lista;
    TLista ant=NULL;
    //INGRESO POR CABEZA
    if(*lista == NULL || (*lista)->dato >= n){
        nuevo = (TLista)malloc(sizeof(Nodo));
        nuevo->dato = n;
        nuevo->sig = *lista;
        *lista = nuevo;
    }else{
        //INGRESO POR COLA O CUERPO
        while(act != NULL && n>=(act->dato)){
            ant = act;
            act = act->sig;
        }
        nuevo = (TLista)malloc(sizeof(Nodo));
        nuevo->dato = n;
        nuevo->sig = act;
        ant->sig = nuevo;
    }
}


void OrdenaLista(TLista lista){


    //ORDENAMIENTO LISTA POR BURBUJEO

    TLista p=lista;
    while(p != NULL){
        TLista u = p->sig;
        while(u != NULL){
            if(p->dato > u->dato){
                int aux = u->dato;
                u->dato = p->dato;
                p->dato = aux;
            }
            u = u->sig;
        }
        p = p->sig;
    }
}

void MuestraLista(TLista lista){

    while(lista != NULL){
        printf("%d ->  ",lista->dato);
        lista = lista->sig;
    }
}


