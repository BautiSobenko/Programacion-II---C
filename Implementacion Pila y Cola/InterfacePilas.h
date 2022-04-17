#include "InterfacePilas.h" ///AGREGAR AL .C

typedef char TelementoP; //Defino tipo de elemento que contendra la pila

///Pila dinamica

typedef struct Nodo{  //Definimos la estructura de un nodo
    TelementoP dato;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TPila;

///Pila estatica

#define MAX 40

typedef struct  TPila{
  TelementoP datos[MAX];
  int tope;
}TPila;

typedef Nodo* TPila; //Pointer a estructura nodo

///Prototipos

void IniciaP(TPila *P);

void Apila(TPila *P,TelementoP x);

void Desapila(TPila *P,TelementoP *x);

int VaciaP(TPila P);

TelementoP ConsultaP(TPila P);

void MuestraP(TPila P);

int LargoP(TPila P);
