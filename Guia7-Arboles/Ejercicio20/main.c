#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int CompuestoCantidad(TArbol A);

int main(){

  TArbol A;

  CompuestoCantidad(A);

  return 0;
}

/**
Dado un árbol binario proveniente de la conversión de un árbol general, obtener el promedio
de las claves cuyo grado era K (dato de entrada).
**/

int CompuestoCantidad(TArbol A){

  if( A == NULL )
    return 0;
  else
    return 1 + CompuestoCantidad(A->der);

}
