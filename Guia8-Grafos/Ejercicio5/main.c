#include <stdio.h>
#include <stdlib.h>
#define N 10;

int grEntrada(int M[][],int V);

int grSalida(int M[][],int V);

int main(){

  int M[N][N];
  int V;
  printf("Ingrese vertice");// v1,v2,...,vN
  scanf("%d",&V);

  printf("Grado de entrada %d\n",grEntrada(M,V));
  printf("Grado de salida %d\n",grSalida(M,V));
  printf("Grado del vertice %d\n",Grado(M,V));

  return 0;
}


/*
5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice
*/

int grEntrada(int M[][],int V){

  int aux = 0;
  int i;

  for( i=0 ; i<N ; i++ )
    if( M[i][V] )
      aux++;
  return aux;
}

int grSalida(int M[][],int V){

  int aux = 0;
  int j;

  for( j=0 ; j<N ; j++ )
    if( M[V][j] )
      aux++;
  return aux;
}

int Grado(int M[][],int V){

  return grEntrada(M,V) + grSalida(M,V) - M[V][V];

}

