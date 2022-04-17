#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intColas.h"

#define MAX 50

typedef struct NodoS{
  char palabra[15];
  unsigned int apariciones;
  struct Nodo* sig;
}NodoS;

typedef struct NodoS* TSubLista;

typedef struct Nodo{
  char letra;
  TSubLista SLP; //Sublista palabras
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

void Elimina(TLista L, char palabra[]);

void GeneraLC(TLista L, TLista *LC);

int main(){

  TLista L, LC;
  char palabra[15];

  printf("Ingrese palabra: ");
  scanf("%s",palabra);

  Elimina(L,palabra);

  GeneraLC(L,&LC);

  return 0;
}

void Elimina(TLista L, char palabra[]){

  char letra = palabra[0];
  TLista auxL = L;
  TSubLista antSL,actSL;

  while( auxL != NULL && auxL->letra < letra ){
    auxL = auxL->sig;
  }
  if( auxL != NULL ){ //Encontre la letra
    antSL = NULL;
    actSL = auxL->SLP;
    while( actSL != NULL && strcmp(actSL->palabra,palabra)<0 ){
      antSL = actSL;
      actSL = actSL->sig;
    }
    if( actSL != NULL ){//Encuentro palabra
      if( antSL == NULL ){
        auxL->SLP = auxL->SLP->sig;
      }else
        antSL->sig = actSL->sig;
      free(actSL);
    }
  }
}


void GeneraLC(TLista L, TLista *LC){

  TLista actL = L;
  TSubLista actSL;
  TLista nuevo;

  while( actL != NULL && actL->letra <= 'u' ){
    if( actL->letra == 'a' ||
        actL->letra == 'e' ||
        actL->letra == 'i' ||
        actL->letra == 'o' ||
        actL->letra == 'u' || ){
      actSL = actL->SLP;
      while( actSL != NULL ){
        if( actSL->apariciones > 5 ){
          nuevo = (TLista)malloc(sizeof(Nodo));
          strcpy(nuevo,actSL->palabra);
          if( *LC == NULL ){
            nuevo->sig = nuevo;
          }else{
            (*LC)->sig = nuevo;
            nuevo->sig = (*LC)->sig;
          }
          *LC = nuevo;
        }
        actSL = actSL->sig;
      }
    }
    actL = actL->sig;
  }
}

int Contar(TArbol A, posicion p, int K, int nivel ){

  if( nulo(p) || nivel > K )
    return 0;
  else
    if( nivel < K )
      return Contar(A,HijoMasIzq(p,A),K,nivel) + Contar(A,HermanoDer(p,A),K,nivel+1);
    else
      return (nulo(HijoMasIzq(p,A)) && info(p,A) == 0 ) + Contar(A,HijoMasIzq(p,A),K,nivel) + Contar(A,HermanoDer(p,A),K,nivel+1);
}

void AAM(MAdy M[][N],int grado,int i,int j,int jAux,TCola *C){

  if( i >= 0 ){
    if( j >= 0 ){
      AAM(M,grado,i,j-1,jAux,C);
      if( M[i][j] )
        grado++;
    }else{
      AAM(M,0,i-1,jAux,jAux,C);
      if( grado > 1 ){
        reg.vertice = i;
        reg.grado = grado;
        PoneC(C,reg);
      }
    }
  }else
    Inicia(C);
}
