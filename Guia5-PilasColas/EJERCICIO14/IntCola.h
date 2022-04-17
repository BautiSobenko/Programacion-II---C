#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Competidores{
    char Apellido[20];
    char Nombre[20];
}Competidores;

typedef Competidores TelementoC;

typedef struct NodoC{
    TelementoC dato;
    struct NodoC* sig;
}NodoC;

typedef struct Cola{
    NodoC* primero;
    NodoC* ultimo;
}Cola;

void IniciaC(Cola *C);

void AgregaC(Cola *C,TelementoC x);

void QuitarC(Cola *C,TelementoC* x);

TelementoC ConsultaC(Cola C);

int VaciaC(Cola C);

void MostrarC(Cola C);

int LargoC(Cola C);

void LiberarC(Cola *C);










