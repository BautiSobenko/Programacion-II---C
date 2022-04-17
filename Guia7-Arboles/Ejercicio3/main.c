#include <stdio.h>
#include <stdlib.h>

//Estructura

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbolB;

//Prototipos

int SumaMult3(TArbolB A);

int CantHojas(TArbolB A);

int BuscaX(TArbolB A, int X);

int main(){

  TArbolB A;

  printf("Suma de mult. de 3: %d",SumaMult3(A));

  printf("Cant. hojas: %d",CantHojas(A));

  if( BuscaX(A,4) )
    printf("Clave encontrada");
  else
    printf("La clave no esta en arbol");

  return 0;
}

int SumaMult3(TArbolB A){

  if( A == NULL )
    return 0;
  else
    if( A->dato%3 == 0 ) //Es multiplo de 3
      return A->dato + SumaMult3(A->izq) + SumaMult3(A->der);
    else
      return SumaMult3(A->izq) + SumaMult3(A->der);
}

int CantHojas(TArbolB A){

  if( A == NULL )
    return 0;
  else
    return ( !A->izq && !A->der ) + CantHojas(A->izq) + CantHojas(A->der);
}

int BuscaX(TArbolB A, int X){

  if( A == NULL )
    return 0;
  else
    return (A->dato == X) || BuscaX(A->izq, X) || BuscaX(A->der, X);
}



