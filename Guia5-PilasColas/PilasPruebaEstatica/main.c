#include <stdio.h>
#include <stdlib.h>
#include "ProtListaEst.h"

int main()
{
    Nodo pila;
    Nodo pilaEliminados;
    TelementoP x;

    IniciaP(&pila);
    IniciaP(&pilaEliminados);

    AgregaP(&pila,5);
    AgregaP(&pila,10);
    AgregaP(&pila,-3);
    AgregaP(&pila,0);

    printf("\n\n");

    MuestraP(pila);

    printf("\n\n");

    QuitaP(&pila,&x);
    AgregaP(&pilaEliminados,x);

    MuestraP(pila);

    printf("\n\n");

    MuestraP(pilaEliminados);

    printf("\n\n");

    return 0;
}
