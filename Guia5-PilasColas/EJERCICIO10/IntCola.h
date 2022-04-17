#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXid 20

typedef Proceso TelementoC;

typedef struct Nodo{
    TelementoC dato;
    struct Nodo* sig;
}Nodo;

typedef struct Proceso{
    char id[MAXid];
    unsigned float solicitud;
    unsigned float duracion;
}Proceso;

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










