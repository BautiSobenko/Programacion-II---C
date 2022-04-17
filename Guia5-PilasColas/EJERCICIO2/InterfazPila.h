#include <stdio.h>
#include <stdlib.h>

typedef char TElementoP; //Tipo de elemento de la pila

typedef struct TPila{
    TElementoP datos[50]; //El tamaño de la pila
    int tope; //Guardara la ultima posicion de la pila
}TPila;

void IniciaP(TPila *P);

void poneP(TPila *P,TElementoP x);

void sacaP(TPila *P,TElementoP *x);

int VaciaP(TPila P);

TElementoP ConsultaP(TPila P);

void MuestraP(TPila P);

void MuestraPRec(TPila P);




