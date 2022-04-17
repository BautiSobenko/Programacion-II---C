#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void MinimoABB(TArbol,int*);

int main(){

  TArbol A;

  MinimoABB(TArbol A);

  MaximoABB(TArbol A);

  return 0;
}

int MaximoABB(TArbol A){

    TArbol aux = A;
    while (aux->der != NULL)
        aux = aux->der;

    return aux->data;
}

int MinimoABB(TArbol A){

    TArbol aux = A;
    while (aux->izq != NULL)
        aux = aux->izq;

    return aux->data;
}

int MaximoABB(TArbol A){

    if (A->der == NULL)
      return A->dato;
    return maxValue(A->der);
}



