#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void Suma(TArbol,int,int);

int main(){

  TArbol A;
  int x,nivel;
  printf("Ingrese nivel X: ");
  scanf("%d",&X);

  Suma(A,X,0);

  return 0;
}

int Suma(TArbol A,int X,int nivel){ //Como puedo inicializar?

  if( A != NULL ){
    if( nivel != X ){ // Estoy por debajo del nivel
      return Suma(A->izq,X,nivel+1) + Suma(A->der,X,nivel+1);
    }else{
      if( A->izq == NULL && A->der != NULL || A->izq != NULL && A->der == NULL ) //Nodo de grado 1
        return A->dato;
      else //Nodo de grado 2 o 0
        return 0;
    }
  }else
    return 0;
}
