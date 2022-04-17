#include <stdio.h>
#include <stdlib.h>

/**
Dado un árbol binario proveniente de la conversión de un árbol general, determinar el grado de
este último.
**/

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

//void Grado(TArbol A,int* maxGr,int gr);

int Grado(TArbol A);

void addnodo(TArbol *A, int e);

int main(){

  TArbol A;
  int maxGr,gr;

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

  //Grado(A,&maxGr,gr);

  //printf("Grado maximo del arbol generador: %d",maxGr);

  printf("%d",Grado(A));

  return 0;
}

void addnodo(TArbol *A,int e) {
    *A = (TArbol)malloc(sizeof(Nodo));
    (*A)->dato = e;
    (*A)->izq = NULL;
    (*A)->der = NULL;
}

/*void Grado(TArbol A,int* maxGr,int gr){ //!Forma recursiva

  if( A != NULL ){
    if( A->der != NULL ) //Si el nodo tiene hermano, sumo 1 al grado
      gr++;
    if( A->izq != NULL ) //Paso a un nuevo hijo
      gr = 1;
    Grado(A->izq,maxGr,gr);
    Grado(A->der,maxGr,gr);
    if( A->der == NULL && gr > *maxGr ) // Si el grado es mayor al anterior, y estoy en el ultimo hermano,guardo el maximo
      *maxGr = gr;
  }
}*/

int Grado(TArbol A){
  int izq,der,grado=0;
  TArbol aux;

   if(A == NULL)
     return 0;
   else{
    izq = Grado(A->izq);
    der = Grado(A->der);
    aux = A->izq;
    while(aux != NULL){
        grado++;
        aux = aux->der;
    }
    if(izq > der)
        der=izq;
    if(der > grado)
       return der;
    else
       return grado;
   }
}
