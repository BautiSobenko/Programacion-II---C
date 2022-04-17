#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  char dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

void Contenido(TArbol,char*,int*);

int main(){

  TArbol arbol;
  char a[50];
  int i=0;

  Contenido(arbol,a,&i);

  return 0;
}

void Contenido(TArbol arbol,char *array, int *i){

  if( A != NULL ){
    Contenido(arbol->izq,array,&i);
    array[(*i)++] = arbol->dato;
    Contenido(arbol->der,array,&i);
  }
}
