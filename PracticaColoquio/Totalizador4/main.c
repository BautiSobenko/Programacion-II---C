#include <stdio.h>
#include <stdlib.h>
#include "intColas.h"

#define N 10

typedef struct TElementoC{
  int vertice;
  int grado;
}TElementoC;

typedef struct TCola{
  TElementoC reg[N];
  int pri,ult;
}TCola;

void Almacena(TCola *C,unsigned int T[][N],int i, int j,int jAux,int grado);

int main(){

  unsigned int T[N][N];
  TCola C;

  Almacena(&C,T,N,N,N,0);

  return 0;
}

void Almacena(TCola *C,unsigned int T[][N],int i, int j,int jAux,int grado){

  TElementoC regAux;

  if( i >= 0 ){
    if( j >= 0 ){
      Almacena(C,T,i,j-1,jAux,grado);
      if( M[i][j] )
        grado++;
      if( M[j][i] )
        grado++;
    }else{
      Almacena(C,T,i-1,jAux,jAux,0);
      if( M[i][i] )
        grado--;
      if( grado > 1 ){
        regAux.grado = grado;
        regAux.vertice = i;
      }
    }
  }else
    IniciaC(C);
}
