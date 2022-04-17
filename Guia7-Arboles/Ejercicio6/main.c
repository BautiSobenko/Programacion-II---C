#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  char clave[];
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbolB;

void NivelCadMasLarga(TArbolB A, int long, int *nivel);

int main(){

  TArbolB A;
  int nivel=1;

  NivelCadMasLarga(A,long,&nivel);

  return 0;
}

void NivelCadMasLarga(TArbolB A, int long, int niv,int *nivel){

  if( A != NULL ){
    if( strlen(A->dato) > long ){
      long = strlen(A->dato);
      *nivel = niv;
    }
    NivelCadMasLarga(A->izq,long,niv+1,nivel);
    NivelCadMasLarga(A->der,long,niv+1,nivel);
  }

}

int NivelCadMasLarga(TArbolB A,int long,int niv){

  int izq,der;

  if( A == NULL )
    return 0;
  if( strlen(A->dato) > long ){
    long = strlen(A->dato);
    max = niv;
  }else
    max = 0;
  izq = NivelCadMasLarga(A->izq,long,niv+1);
  der = NivelCadMasLarga(A->der,long,niv+1);
  if( izq > max )
    max = izq;
  if( der > max)
    max = der;
  return max;

}
