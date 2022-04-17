#include <stdio.h>
#include <stdlib.h>

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

  CantArboles(A);

  return 0;
}

int CantArboles(TArbol A){ //Forma recursiva

  if( A == NULL )
    return 0;
  else
    return 1 + CantArboles(A->izq);
}

int CantArboles(TArbol A){ //Forma iterativa

  int cont=0;

  while( A != NULL ){
    cont++;
    A = A->der;
  }
  return cont;

}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}
