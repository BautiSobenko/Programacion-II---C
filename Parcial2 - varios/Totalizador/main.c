#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intPilas.h"

typedef struct NodoS{
  char dni[10];
  int numLote;
  float m2;
  struct NodoS* sig;
}NodoS;

typedef NodoS* TSubLista;

typedef struct NodoL{
  int numBarrio;
  TSubLista SLT; //SubLista terrenos
}NodoL;

typedef NodoL* TLista;

typedef struct NodoD{
  char dni[10];
  float m2;
  int cantLotesExc;
  struct NodoD *sig,*ant;
}NodoD;

typedef NodoD* PNodoD;

typedef struct TListaD{
  PNodoD pri,ult;
}TListaD;

typedef struct regPila{
  int nroBarrio;
  int nroLote;
  float maxM2;
}regPila;

typedef struct TPila{
  regPila regP[MAX];
  int tope;
}TPila;

int main(){

  TLista L;
  TListaD LD;

  GeneraListaD()

  return 0;
}

void GeneraLista(){

  TPila pilaAux;
  regPila regAux;
  TLista actL;
  TSubLista actSL;
  PNodoD nuevo,actLD;

  while( !VaciaP(*P) ){
    SacaP(P,&regAux);
    actL = L;
    while( actL != NULL && actL->numBarrio < regAux.nroBarrio ){ //Busqueda en lista ordenada
      actL = actL->sig;
    }
    if( actL != NULL ){ //Encuentro barrio
      actSL = actL->SLT;
      while( actSL != NULL && actSL->numLote != regAux.nroLote ){ //Busqueda en sublista no ordenada
        actSL = actSL->sig;
      }
      if( actSL != NULL && actSL->m2 > regAux.maxM2 ){ //Encuentro lote que supere el maximo de m2 permitido
        actLD = *LD.pri;
        while( actLD != NULL && strcmp(actLD->dni,actSL->dni) != 0){ //Busqueda en lista doble
          actLD = actLD->sig;
        }
        if( actLD == NULL ){ //Si no encuentro DNI(nuevo DNI)
          nuevo = (TListaD)malloc(sizeof(NodoD));
          nuevo->ant = NULL;
          nuevo->sig = (*LD).pri;
          nuevo->cantLotesExc = 1;
          nuevo->m2 = regAux.maxM2 - actSL->m2;
          strcpy(nuevo->dni,actSL->dni);
          (*LD).pri = nuevo;
        }else{ //encuentro DNI ya registrado y lo actualizo
          actLD->m2 += regAux.maxM2 - actSL->m2;
          actLD->cantLotesExc++;
        }
      }else//Lote que no se excede de los m2
        PoneP(&pilaAux,regAux);
    }
  }
  while( !VaciaP(pilaAux) ){
    SacaP(&pilaAux,&regAux);
    PoneP(P,regAux);
  }
}
