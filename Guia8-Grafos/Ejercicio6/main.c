#include <stdio.h>
#include <stdlib.h>

#define N 10;

typedef struct Nodo{
  int V;
  struct Nodo* sig;
}Nodo;

struct LAdy{
  int V;
  TListaAdy L;
}LAdy[N];

typedef struct Nodo* TListaAdy;

//PROTOTIPOS

int grEntrada(int M[][],int V);

int grSalida(int M[][],int V);

//FUNCION PRINCIPAL

int main(){


  int V;
  printf("Ingrese vertice");// v1,v2,...,vN
  scanf("%d",&V);



    printf("Grado de entrada %d\n",grEntrada(LAdy,V));
    printf("Grado de salida %d\n",grSalida(LAdy,V));
    printf("Grado del vertice %d\n",Grado(LAdy,V));
  }

  return 0;
}


/*
5. Dado un vértice determinado de un digrafo representado en una lista de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice
*/

int grSalida(struct LAdy LAdy[],int V){

  int i,grado=0;
  TListaAdy auxL; //puntero a nodo

  while( i <= N && V != LAdy[i].V )
    i++;
  }
  if(i>N)
    return -1;
  else{
    auxL = LAdy[i].L; //Me paro en la cabeza de la lista
    while( auxL != NULL ){
      grado++;
      auxL = auxL->sig;
    }
    return grado;
  }
}

int grEntrada(struct LAdy LAdy[],int V){

  int i, grado=0, flag=0;
  TListaAdy auxL; //puntero a nodo

  for( i=0; i<N ; i++){
    auxL = LAdy[i].L; //Me paro en la cabeza de la lista
    while( auxL != NULL && auxL->V != V ) //Salgo si ya encontre el vertice
      auxL = auxL->sig; //Solo hay un nodo en la lista de un digrafo
    if( auxL ) //Encuentro el nodo
      grado++;
    if( V == LAdy[i].V )
      flag = 1;
  }
  if ( flag ) //Me indica que encontre el vertice en el grafo
    return grado;
  else //La bandera permanece en 0
    return -1; //El nodo no existe en el grafo.
}

int Grado(struct LAdy LAdy[],int V){

  int i,grado=0;
  TListaAdy auxL; //puntero a nodo

  while( i <= N && V != LAdy[i].V ) //Busco el vertice en el arreglo
    i++;
  }
  if(i>N) // Si no esta en el arreglo
    return -1;
  else{
    auxL = LAdy[i].L; //Me paro en la cabeza de la lista
    while( auxL != NULL && auxL->V != LAdy[i].L ){
      auxL = auxL->sig;
    }
    if( auxL ) //Encuentro un bucle.
      return grEntrada(LAdy,V) + grSalida(LAdy,V) - 1;
    else
      return grEntrada(LAdy,V) + grSalida(LAdy,V)
  }
}

