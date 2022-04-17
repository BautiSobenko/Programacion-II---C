#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  char dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void Maximo(TArbol A, char *max);

char MaximoA(TArbol A);

void Recorre(TArbol A);

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

  Recorre(A);

  printf("Maximo: %c",MaximoA(A));

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

/*
25. Dado un árbol binario de números naturales que proviene de la transformación de un bosque,
devolver un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
*/


void Recorre(TArbol A){

  char max;
  char arreglo[10];
  int n=0;

  while( A != NULL ){
    max = A->dato;
    Maximo(A->izq,&max);
    arreglo[n++] = max;
    A = A->der;
  }

  for(int i=0; i<n; i++)
    printf("[%c]  ",arreglo[i]);

}


void Maximo(TArbol A, char *max){

  if( A != NULL ){
    if( A->dato > *max )
      *max = A->dato;
    Maximo(A->izq,max);
    Maximo(A->der,max);
  }
}

char MaximoA(TArbol A){

  char res, resIzq, resDer;

  if( A == NULL )
    return ' ';
  else{
    res = A->dato;
    resIzq = MaximoA(A->izq);
    resDer = MaximoA(A->der);
    if( resIzq > res ) //Si encuentro un nodo mayor x izq o x der, lo retorno
      res = resIzq;
    if( resDer > res )
      res = resDer;
    return res; //Si der = izq -> retorno res
  }
}




