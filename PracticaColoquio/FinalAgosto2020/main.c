#include <stdio.h>
#include <stdlib.h>

#define N 50
typedef struct TCola{
  int num[N];
  int pri,ult;
}TCola;

void Solucion(int MAdy[][N],TCola *C);

int main(){

  TCola C;
  int MAdy[N][N];

  Solucion(MAdy,N,N,N,0,&C);

  return 0;
}

void Solucion(int MAdy[][N],int i,int iAux,int j,int gr,TCola *C){

  TCola CAux;
  int num;

  if( j>=0 ){
    if( i>= 0){
      if( MAdy[i][j] )
        gr++;
      Solucion(MAdy,i-1,iAux,j,gr,C);
    }else{
      Inicia(&CAux);
      while( !VaciaC(*C) ){
        SacaC(C,&num);
        if( num != gr )
          PoneC(&CAux,num);
      }
      while( !Vacia(CAux) ){
        SacaC(CAux,&num);
        PoneC(C,num);
      }
      Solucion(MAdy,iAux,iAux,j-1,0,C);
    }
  }
}
