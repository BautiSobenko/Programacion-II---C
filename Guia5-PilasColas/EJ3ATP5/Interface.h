#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* TelementoC; //Tipo de elemento de cola: STRING => CHAR*

typedef struct Nodo{
    TelementoC dato;  //Dato tipo string
    struct Nodo* sig;
}Nodo;

typedef struct Cola{
    Nodo* primero;
    Nodo* ultimo;
}Cola;

void IniciaC(Cola *C);

void Encolar(Cola *C,TelementoC x);

void Desencolar(Cola *C,TelementoC x);

TelementoC ConsultaC(Cola C); //Devuelve una cadena

int VaciaC(Cola C);

int LargoC(Cola C);

void MuestraC(Cola C);


