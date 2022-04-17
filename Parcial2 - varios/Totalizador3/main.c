#include <stdio.h>
#include <stdlib.h>
#include "intCola.h"

void Elimina(TCola *C,TArbol A,int x, int y);

int main(){

  TCola C;
  TArbol A;
  int x,y,

  printf("Ingrese  X e Y: ");
  scanf("%d",&x);scanf("%d",&y);

  Elimina(&C,A,x,y);

  return 0;
}

int EstaEnABB(TArbol A, int num ){

  if( A == NULL )
    return 0;
  else
    return ( A->dato == num ) || EstaEnABB(A->izq,num) || EstaEnABB(A->der,num);
}

void Elimina(TCola *C,TArbol A,int x, int y){

  TCola aux;
  int num;

  IniciaC(&aux);
  while( !VaciaC(*C) ){
    SacaC(C,&num);
    if( num <= X || num >= Y || !EstaEnABB(A,num) )
      PoneC(&aux,num);
  }
  while( !VaciaC(aux) ){
    SacaC(&aux,&num);
    PoneC(C,num);
  }
}
