#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int Altura(TArbol A);

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

  printf("%d",altGral(A));

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

/*
22. Dado un árbol binario que proviene de la transformación
de un árbol general, obtener la altura del árbol original
*/

int altGral(TArbol A){
    int i, d;

    if(A == NULL)
        return 0;
    else{
        i = 1 + altGral(A->izq);
        d = altGral(A->der);
        if(i > d)
            return i;
        else
            return d;
    }
}
