#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char TelementoC;

typedef struct Nodo{
    TelementoC dato;
    struct Nodo* sig;
}Nodo;

typedef struct Cola{
    Nodo* primero;
    Nodo* ultimo;
}Cola;

void IniciaC(Cola *C);

void AgregaC(Cola *C,TelementoC x);

void QuitarC(Cola *C,TelementoC* x);

TelementoC ConsultaC(Cola C);

int VaciaC(Cola C);

void MostrarC(Cola C);

int LargoC(Cola C);

void LiberarC(Cola *C);










