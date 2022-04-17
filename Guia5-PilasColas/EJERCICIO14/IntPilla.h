#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxComp 50

typedef struct id{
    char inicial;
    char ids[MaxComp][20]; //Array de strings de 50 pos.
    int Qcomp;
}id;

typedef id TelementoP; //Defino tipo de elemento que contendra la pila

typedef struct Nodo{  //Definimos la estructura de un nodo
    TelementoP dato;
    struct Nodo* sig;
}Nodo;

typedef Nodo* p_nodo; //Pointer a estructura nodo

void IniciaP(p_nodo *P);

void Apila(p_nodo *P,TelementoP x);

void Desapila(p_nodo *P,TelementoP *x);

int VaciaP(p_nodo P);

TelementoP ConsultaP(p_nodo P);

void MuestraP(p_nodo P);

int LargoP(p_nodo P);

