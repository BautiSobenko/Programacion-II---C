//Listas ligadas

#include <stdio.h>
#include <stdlib.h>

typedef int TelementoL;

typedef struct Nodo{
    int dato;
    struct Nodo *sig;
}Nodo;

typedef struct Nodo* TLista;

void Iniciar(TLista *Lista){
    *Lista = NULL;
}

void Agrega(TLista *Lista,TelementoL x){
    //Creacion del nodo dinamico
    TLista nuevo_nodo;
    nuevo_nodo = (TLista)malloc(sizeof(Nodo));
    nuevo_nodo->dato = x;
    nuevo_nodo->sig = NULL;
    if(!*Lista){
        *Lista = nuevo_nodo; //Unico nodo que tenemos
    }else{
        /*//Agregar el nodo al final de la lista
        //Como la lista no esta vacia tendremos que recorrerla
        TLista nodo_aux;
        nodo_aux = *Lista;
        while(nodo_aux->sig){
            nodo_aux = nodo_aux->sig;
        }*/
        //Agregar el nodo al inicio de la lista
        nuevo_nodo-> = *Lista;
        *Lista = nuevo_nodo;
    }
}

void Quitar(TLista *Lista,TelementoL *X){

    TLista aux = *Lista;
    if(*Lista){
        //QUITAR PRIMERO
        *Lista = *Lista->sig;
        *X = aux->dato;
        free(aux);
        //QUITAR ULTIMO
        while(aux->sig->sig != NULL){
            aux = aux->sig;
        }

    }else
        printf("Lista vacia\n");

}

void Muestra(TLista Lista){
    while(Lista != NULL){
        printf("%d\n",Lista->dato);
        Lista = Lista->sig;
    }
}

int main(){
    TLista lista; // Nodo *lista
    TelementoL x;
    Iniciar(&lista);
    Agrega(&lista,10);
    Agrega(&lista,30);
    Muestra(lista);
    return 0;
}
