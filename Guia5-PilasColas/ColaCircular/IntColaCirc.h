#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TElementoC;

typedef struct TCola{
    TElementoC datos[MAX];
    int pri, ult;
}TCola;

void IniciaC (TCola *C) {
(*C).pri=-1;
(*C).ult=-1;
}

void IniciaC (TCola * C);

int VaciaC (TCola C);

void sacaC (TCola *C, TElementoC* x);

void poneC (TCola *C, TElementoC x);
