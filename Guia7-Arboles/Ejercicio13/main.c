#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int Intervalo(TArbol,int,int);

int main(){

  TArbol arbol;
  int a,b;
  printf("Ingrese a: "); scanf("%d",&a);
  printf("\nIngrese b: "); scanf("%d",&b);

  Intervalo(arbol,a,b);

  return 0;
}

int Intervalo(TArbol arbol,int a,int b){

  //1. Caso base
  if( arbol == NULL )
    return 0; //Arbol vacio
  else
    if( a <= arbol->dato && b >= arbol->dato ){ //Si estoy en el intervalo
      return 1 + Intervalo(arbol->izq,a,b) + Intervalo(arbol->der,a,b); //Recorro preorden
    }else
      if( arbol->dato < a )
        return Intervalo(arbol->der,a,b);
      else
        return Intervalo(arbol->izq,a,b);
}

void Max(TArbol A,int nivel,int *nivelMax, char *max){

  if( A == NULL )
    *max = '';
  else{
    if( nivel > *nivelMax && A->der != NULL && A->izq != NULL ){
      *nivelMax = nivel;
      *max = A->dato;
    }
    Max(A->izq,nivel+1,max);
    Max(A->der,nivel+1,max);
  }
}
