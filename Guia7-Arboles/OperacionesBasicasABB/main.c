#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

//PROTOTIPOS

void Insertar(TArbol*,int);

int Busqueda(TArbol,int);

int main(){

  TArbol arbol = NULL;

  Insertar(&arbol,14);
  Insertar(&arbol,11);
  Insertar(&arbol,33);
  Insertar(&arbol,9);
  Insertar(&arbol,1);
  Insertar(&arbol,25);
  Insertar(&arbol,40);

  if( Busqueda(arbol, 0) )
    printf(" El nodo existe en el arbol\n");
  else
    printf(" El nodo NO existe en el arbol\n");

  return 0;
}

void Insertar(TArbol *arbol,int valor){

  if(*arbol == NULL ){                     //Creo nodo hijo o raiz
    *arbol = (TArbol)malloc(sizeof(Nodo)); //En donde antes estaba NULL, ahora creo el nodo
    (*arbol)->dato = valor;                //El padre ya estara apuntando a este nodo
    (*arbol)->izq = (*arbol)->der = NULL;
  }else{
    if( valor > (*arbol)->der )
      Insertar(&((*arbol)->der),valor);
    else
      Insertar(&((*arbol)->izq),valor);
  }
}

int Busqueda(TArbol arbol,int x){

  if( arbol == NULL )
    return 0;
  else if( arbol->dato == x ) //Si el elemento que busco esta en la raiz
    return 1;
  else{
    if( x > arbol->dato ) //Busco por subarbol derecho
      Busqueda(arbol->der,x);
    if( x < arbol->dato )
      Busqueda(arbol->izq,x); //Busco por subarbol izquierdo
  }
}
