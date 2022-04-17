#include <stdio.h>
#include <stdlib.h>
#include "IntPila.h"

#define MAX 50

typedef struct TElementoP{
  int peso;
  int vertice;
}TElementoP;

typedef struct TPila{
  TElementoP Elem[MAX];
  int tope;
}TPila;



int main(){

  LAdy L;

  return 0;
}

void Solucion(LAdy L,TPila *P){

  TElementoP elem;
  TLista actL;
  int costoTotal=0, i;
  TPila Paux;

  if( !VaciaP(*P) ){
    SacaP(P,&elem);
    for( i=0; i<N; i++){
      actL = L[i].head;
      while ( actL != NULL ){
        if( elem.vertice == actL->vert )
          costoTotal += actL->peso;
        if( elem.vertice == i )
          costoTotal -= actL->peso;
        actL = actL->sig;
     }
    }
     IniciaP(&Paux);
     if( elem.peso > costoTotal )
       PoneP(&Paux,elem);
     while( !VaciaP(PAux) ){
       SacaP(&Paux,&elem);
       PoneP(P,elem);
     }
     Solucion(L,P);
  }
}

