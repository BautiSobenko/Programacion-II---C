#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void CalculaProm(TArbol A,int k,int *suma,int *n,int *prom);

void addnodo(TArbol *A, int e);

int main(){

  TArbol A;
  int k, suma=0, n=0, prom=0;


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
  addnodo(&A->izq->der->izq->izq->izq->der->der->der,16);

  CalculaProm(A,4,&suma,&n,&prom);
  printf("Suma: %d",suma);

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

void CalculaProm(TArbol A,int k,int *suma,int *n,int *prom)
{   int grado=0;
    TArbol aux;
    if(A!=NULL)
    {   aux = A->izq;
        while( aux != NULL && grado <= k )
        {   grado++;
            aux=aux->der;
        }
        if(grado == k)
        {   *suma += A->dato;
            (*n)++;
        }
        CalculaProm(A->izq,k,suma,n,prom);
        CalculaProm(A->der,k,suma,n,prom);
    }
  if(*n)
    *prom = *suma/(*n);
}




