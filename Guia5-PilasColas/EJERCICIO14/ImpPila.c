#include "IntPilla.h"

void IniciaP(p_nodo *P){
    *P = NULL;  //Inicializamos puntero
}

void Apila(p_nodo *P,TelementoP x){
    p_nodo aux = (p_nodo)malloc(sizeof(Nodo)); //Memoria heap que contendra al nodo
    aux->dato = x; //Guardamos dato en nodo
    aux->sig = *P; //Enlazamos el nodo con el anterior
    *P = aux;      //Avanzamos el puntero que marcara el ultimo elemento de la pila
}

void Desapila(p_nodo *P,TelementoP *x){
    if(*P){
        p_nodo aux = *P; //Nodo auxiliar apunta al ultimo de la pila LIFO
        *x = aux->dato;
        *P = aux->sig;
        free(aux);
    }else
        printf("\nLa pila esta vacia.\n");
}

TelementoP ConsultaP(p_nodo P){
    return P->dato;
}

int VaciaP(p_nodo P){
    return (!P)? 1:0;
}

void MuestraP(p_nodo P){
    if(P){
        printf("%c\n",P->dato);
        return MuestraP(P->sig);
    }else
        printf("%s\n","NULL");
}

int LargoP(p_nodo P){

    int cont=0;
    while(P){
        cont++;
        P = P->sig;
    }
    return cont;
}

