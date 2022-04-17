#include <stdio.h>
#include <stdlib.h>

/**
Dado un árbol binario proveniente de la conversión de un árbol general, hallar la cantidad de
nodos que habia en niveles impares.
**/

typedef struct Nodo{
  char dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int CantArboles(TArbol A);

void addnodo(TArbol *A, int e);

int main(){

  TArbol A;

  //! CARGA DE ARBOL BINARIO PROVENIENTE DE BOSQUE

  addnodo(&A,'A');
  addnodo(&A->der,'B');
  addnodo(&A->der->der,'L');
  addnodo(&A->der->der->izq,'M');
  addnodo(&A->der->der->izq->der,'N');
  addnodo(&A->der->der->izq->der->izq,'O');
  addnodo(&A->der->izq,'C');
  addnodo(&A->der->izq,'C');
  addnodo(&A->der->izq->der,'D');
  addnodo(&A->der->izq->der->izq,'E');
  addnodo(&A->der->izq->der->izq->der,'F');
  addnodo(&A->der->izq->der->izq->der->der,'G');
  addnodo(&A->der->izq->der->izq->der->der->der,'H');
  addnodo(&A->der->izq->der->izq->der->izq,'I');
  addnodo(&A->der->izq->der->izq->der->izq->der,'J');
  addnodo(&A->der->izq->der->izq->der->izq->der->der,'K');

  printf("La cantidad de arboles que componian al bosque es de: %d", CantArboles(A));

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}
/*Dado un árbol binario que proviene de la
transformación de un bosque, determinar qué
cantidad de árboles lo componían. */

int CantArboles(TArbol A){

  if( A == NULL )
    return 0;
  else
    return CantArboles(A->der) + 1;

}

