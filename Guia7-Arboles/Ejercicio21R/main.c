#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void PromedioClaves(TArbol A,int *auxGrado,int K,int *suma);

void addnodo(TArbol *A, int e);

int main(){

  TArbol A;
  int K, suma=0, auxGrado = 0;

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
  addnodo(&A->izq->der->izq->izq->izq->der->der->der,15);

  printf("Ingrese grado K: "); scanf("%d",&K);

  PromedioClaves(A,&auxGrado,4,&suma);

  printf("Suma total %d",suma);

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

/*
21. Dado un árbol binario proveniente de la conversión
 de un árbol general, obtener el promedio
de las claves cuyo grado era K (dato de entrada).
*/

void PromedioClaves(TArbol A,int *auxGrado,int K,int *suma){

  if( A != NULL ){
    PromedioClaves(A->izq,auxGrado,K,suma);
    if( *auxGrado == K )
      *suma += A->dato;
    if( A->izq != NULL )
      *auxGrado = 0;
    PromedioClaves(A->der,auxGrado,K,suma);
    (*auxGrado)++;
  }
}
