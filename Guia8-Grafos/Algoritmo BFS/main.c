#include <stdio.h>
#include <stdlib.h>
#include "TdaCola.h"

#define N 6

void BFS(int MAdy[][N],int Vi);

int main(){

  int MAdy[N][N]=
  {{0,1,1,0,0,0},
   {1,0,1,0,0,0},  //Creo matriz de adyacencia
   {1,1,0,1,0,0},
   {0,0,1,0,1,1},
   {0,0,0,1,0,0},
   {0,0,0,1,0,0}};

  int Vi = 1; //Nodo inicial
  int CantCC=1;

  BFS(MAdy,Vi);

  BFSD(MAdy,Vi,&CantCC); //Grafo disconexo

  return 0;
}

void BFS(int MAdy[][N],int Vi){

  int visitados[N];
  int i, v, cantVV=0;
  TCola C;

  for(i=0;i<N;i++)
    visitados[i]=0;

  visitados[vi-1]=1;

  IniciaC(&C);
  PoneC(&C,vi);

  cantVV++;
  printf("[%d] ",v);

  while( cantVV < N-1 ){
    SacaC(&C,&v);
    for(j=0;j<N;j++){
      if( MAdy[v][j] && visitados[j] ){
        PoneC(&C,j);
        visitados[j]=1;
        printf("[%d] ",j);
        cantVV++;
      }
    }
  }
}

void BFSD(int MAdy[][N],int Vi,int *CantCC){

  int visitados[N];
  int i, v, cantVV=0; //Q vertices visitados
  TCola C;

  for(i=0;i<N;i++)
    visitados[i]=0;

  visitados[vi-1]= *CantCC;

  IniciaC(&C);
  PoneC(&C,vi);

  cantVV++;

  while (cantVV != N-1){
    while (!VaciaC(C)){
      SacaC(&C, &v);
      printf("%d ", v);
      for (j=0;j<N;j++){
        if (MAdy[v][j] != 0 && visitados[j] != 0){
          visitados[j] = (*cantCC);
          cantVV++;
          PoneC(&C, j);
        }
      }
    }
    j = 0;
    while (j < N && visitados[j] != 0)
      j++;
    if (j < N){
      PoneC(&C, j);
      (*cantCC)++;
      visitados[j] = *cantCC;
      cantVV++;
    }
  }
}
