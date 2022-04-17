#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct TCola{
  int num[MAX];
  int pri,ult;
}TCola;

int main(){



    return 0;
}

int EstaEnABB(TArbol A, int num){

  if( A == NULL )
    return 0;
  else{
    if( num == A->dato )
      return 1
    if( num > A->dato )
      return EstaEnABB(A->der,num);
    else
      return EstaEnABB(A->izq,num);
  }
}

void EliminaCola(TCola *C, int X, int Y){

  TCola CAux;
  int num;
  IniciaC(&CAux);
  TArbol A;

  while( !VaciaC(*C) ){
    SacaC(C,&num);
    if( num <= X || num >= Y || !EstaEnABB(A,num) )
      PoneC(&Caux,num);
  }
  while( !VaciaC(CAux){
    SacaC(&CAux,num);
    PoneC(C,num);
  }
}
