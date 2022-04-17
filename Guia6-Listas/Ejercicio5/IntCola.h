#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef int TelementoC;

typedef struct TCola{
    TelementoC datos[MAX];
    int pri;
    int ult;
}TCola;

void IniciaC(TCola *C);

void AgregaC(TCola *C,TelementoC x);

void QuitarC(TCola *C,TelementoC* x);

TelementoC ConsultaC(TCola C);

int VaciaC(TCola C);

void MostrarC(TCola C);

int LargoC(TCola C);

void LiberarC(TCola *C);









