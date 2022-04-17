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

/*
Para obtener por cuantos arboles se encuentra compuesto AB proveniente del bosque,
debo ver cuantos nodos posee el camino de mas a la derecha,
cada nodo de este camino es la raiz correspondiente a cada arbol perteneciente al bosque
*/

int CompuestoCantidad(TArbol A){

  if( A == NULL )
    return 0;
  else
    return 1 + CompuestoCantidad(A->der);

}
