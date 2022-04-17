#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  char dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int Recorre(TArbol A);

int altGral(TArbol A);

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

  printf("%d",Recorre(A));

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

int Recorre(TArbol A){

  int cantArboles=0;
  int alt = 2;

  while( A != NULL ){
    if( 1 + altGral(A->izq) >= alt ) //Sumo la raiz
      cantArboles++;
    A = A->der;
  }

  return cantArboles;
}

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



