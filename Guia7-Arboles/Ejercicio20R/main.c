#include <stdio.h>
#include <stdlib.h>

/**
Dado un árbol binario proveniente de la conversión de un árbol general, hallar la cantidad de
nodos que habia en niveles impares.
**/

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int NodosEnNivImp(TArbol A,int nivel);

void addnodo(TArbol *A, int e);

int main(){

  TArbol A;

  //! CARGA DE ARBOL BINARIO PROVENIENTE DE ARBOL GENERAL

  addnodo(&A,1);
  addnodo(&A->izq,3);
  addnodo(&A->izq->izq,5);
  addnodo(&A->izq->izq->der,6);
  addnodo(&A->izq->izq->der->der,7);
  addnodo(&A->izq->izq->der->der->der,8);
  addnodo(&A->izq->der,4);
  addnodo(&A->izq->der->izq,9);
  addnodo(&A->izq->der->izq->izq,10);
  addnodo(&A->izq->der->izq->izq->der,11);
  addnodo(&A->izq->der->izq->izq->izq,12);
  addnodo(&A->izq->der->izq->izq->izq->der,13);
  addnodo(&A->izq->der->izq->izq->izq->der->der,14);

  printf("Cantidad de nodos en niveles impares del arbol generador de AB: %d\n",NodosEnNivImp(A,1));

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

/*
20. Dado un árbol binario proveniente de la conversión de un árbol general,
hallar la cantidad denodos que habia en niveles impares.
*/

int NodosEnNivImp(TArbol A,int nivel){

  if( A == NULL )
    return 0;
  else
    return ( nivel%2 != 0 ) + NodosEnNivImp(A->izq,nivel+1) + NodosEnNivImp(A->der,nivel);
}
