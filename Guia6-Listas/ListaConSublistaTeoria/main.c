#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Se tiene una lista de clientes que registran pagos de un credito con el siguiente diseño:
*NUMERO DE CLIENTE
*TOTAL EN CREDITO EN $
*ADEUDADO EN $
*SUBLISTA DE PAGOS:
    -Fecha
    -Importe
Se pide:
a- Dado un numero de cliente correcto , una fecha y un importe, insertar el pago actualizando el valor adecuado
b- Dado un numero de cliente y una fecha , eliminar el pago (Si existe) actualizando el valor adecuado.
c- Dado un numero de cliente eliminarlo de la lista.
d- Eliminar de la lista los clientes que ya no tienen deuda.*/

///ESTRUCTURA LISTA
#define MAX 10

typedef struct Nodito{
    char fecha[MAX];
    float importe;
    struct Nodito* sig;
}Nodito;

typedef struct Nodito* SubLista;

typedef struct Nodo{
    int cliente;
    float credito;
    float deuda;
    SubLista sub;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

///PROTOTIPOS

void IncisoA(TLista L,int numero,char *fecha,float imp);

typedef struct Nodo* TLista;

int main(){

    TLista L;
    int numero;
    char fecha[MAX];
    float imp;

    IncisoA(L,numero,fecha,imp);

    return 0;
}

///FUNCIONES

///a- Dado un numero de cliente correcto , una fecha y un importe, insertar el pago actualizando el valor adecuado

void IncisoA(TLista L,int numero,char *fecha,float imp){

    TLista aux = L;
    SubLista nuevoS;

    while( numero != aux->cliente ){
        aux = aux->sig;
    }
    nuevoS = (SubLista)malloc(sizeof(Nodito));
    strcpy(nuevoS,fecha);
    nuevoS->importe = imp;
    nuevoS->sig = aux->sub;
    aux->sub = nuevoS; //! PUEDO TENER PAGOS ATRASADOS(CORREGIR)
    aux->deuda -= imp;

///Dado un numero de cliente y una fecha , eliminar el pago (Si existe) actualizando el valor adecuado.

void IncisoB(TLista L,int num,char *fecha){

    TLista aux = L;
    Sublista actS;
    Sublista antS;

    while( aux != NULL && num != aux->cliente){ //Mientras no se termine ListaClientes y no encuentre,sigo buscando
      aux = aux->sig;
    }
    if(aux != NULL){     //Si encontre
        actS = aux->sub; //Me posiciono en el primer nodito del nodo encontrado
        antS = NULL
        while( actS != NULL && strcmp(fecha,aux->fecha)!=0){ //Mientras no se termina SubListaPagos y no encuentre,sigo buscando
            antS = actS;
            actS = actS->sig;
        }
        if(actS != NULL){
            if(actS == aux->sub)
                aux->sub = aux->sub->sig;
            else
                antS->sig = actS->sig;
            free(actS);
        }
    }
}


///c- Dado un numero de cliente eliminarlo de la lista.

void EliminaLista(TLista *L,int numero){

    TLista act = *L;
    TLista ant = NULL;
    SubLista elimS,auxS;

    while(act!=NULL && numero!=act->cliente){ //Mientras no se termina la lista y no encuentre, sigo buscando
        ant = act;
        act = act->sig;
    }
    if(act!=NULL){
        if(act==*L)
            *L = (*L)->sig;
        else
            ant->sig = act->sig;
        auxS = act->sub;
        while( auxS!=NULL ){
            act->sub = act->sub->sig;
            elimS = auxS;
            auxS = aux->sig;;
            free(elimS);
        }
        free(act);
    }
}

///d- Eliminar de la lista los clientes que ya no tienen deuda.

void EliminarSinDeuda(TLista *L){

    TLista act = *L;
    TLista ant = NULL;
    TLista elim;

    while(act != NULL){
        if(act->deuda == 0){
            elim = act;
            if(act==*L)
                *L = *L->sig;
            else
                ant->sig = act->sig;
            act = act->sig;
            free(elim);
            }else{
                ant = act;
                act = act->sig;
            }
    }
}
