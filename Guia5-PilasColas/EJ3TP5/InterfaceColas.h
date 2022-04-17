#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 9

typedef char TelementoC;

typedef struct Nodo{
    TelementoC dato[MAX];
    struct Nodo* sig;
}Nodo;

typedef struct Cola{
    Nodo* primero;
    Nodo* ultimo;
}Cola;

void IniciaC(Cola *C);

void Encolar(Cola *C,TelementoC x[]);

void Desencolar(Cola *C,TelementoC x[]);

TelementoC ConsultaC(Cola C);

int VaciaC(Cola C);




