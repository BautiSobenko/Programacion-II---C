#include <stdio.h>
#include <stdlib.h>

/**
Dado un árbol binario proveniente de la conversión de un árbol general, obtener el promedio
de las claves cuyo grado era K (dato de entrada).
**/

typedef struct Nodo{
  char dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void IncisoA(TArbol A,int nivel,int* nivelMax,char *car);

void addnodo(TArbol *A, int e);

int main(){

  TArbol A;
  int nivel,nivelMax=0;
  char car;

  addnodo(&A,'F');
  addnodo(&A->izq,'C');
  addnodo(&A->izq->der,'D');
  addnodo(&A->izq->izq,'A');
  addnodo(&A->izq->izq->der,'B');
  addnodo(&A->izq->izq->der->izq,'E');
  addnodo(&A->izq->izq->der->der,'O');
  addnodo(&A->der,'G');
  addnodo(&A->der->der,'I');
  addnodo(&A->der->der->der,'M');
  addnodo(&A->der->der->izq,'H');


  IncisoA(A,1,&nivelMax,&car);

  printf("%c",car);



  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

void IncisoA(TArbol A,int nivel,int *nivelMax,char *car){

  if( A != NULL ){
    if( A->izq != NULL && A->der != NULL && nivel > *nivelMax){
      *car = A->dato;
      *nivelMax = nivel;
    }
    IncisoA(A->izq,nivel+1,nivelMax,car);
    IncisoA(A->der,nivel+1,nivelMax,car);
  }
}


