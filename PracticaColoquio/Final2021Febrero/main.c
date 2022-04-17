#include <stdio.h>
#include <stdlib.h>

typedef struct NodoS{
  int N;
  struct NodoS* sig;
}NodoS;

typedef struct NodoS* TSubLista;

typedef struct NodoD{
  int N;
  TSubLista SLdiv;
  struct NodoD *sig,*ant;
}NodoD;

typedef struct NodoD* Pnodo;

typedef struct TListaD{
  Pnodo pri,ult;
}TListaD;

int Verifica(TListaD LD, int K);

void GeneraArch(TListaD LD, int X);

int main(){

  int K;
  TListaD LD;

  if( Verifica(LD,K) )
    printf("Se verifica la condicion");
  else
    printf("NO se verifica la condicion");

  GeneraArch(LD,X);

  return 0;
}

int Verifica(TListaD LD, int K){

  Pnodo actLD = LD.pri;
  TSubLista antSL,actSL,elimSL;

  while( actLD != NULL && K != actLD->N ){
    actLD = actLD->sig;
  }
  if( actLD != NULL ){
    antSL = NULL;
    actSL = actLD->SLdiv;
    while( actSL != NULL ){
      if( actSL->N%K != 0 ){
        elimSL = actSL;
        actSL = actSL->sig;
        if( antSL == NULL )
          actLD->SLdiv = actLD->SLdiv->sig;
        else
          antSL->sig = elimSL->sig;
        free(elimSL);
      }else{
        antSL = actSL;
        actSL = actSL->sig;
      }
    }
  }
}

void GeneraArch(TListaD LD, int X){

  Pnodo actLD = LD.pri;
  TSubLista actSL;

  file* arch = fopen("DIVI.TXT","w")
  if( arch ){
    while( actLD != NULL ){
      if( actLD->N%2 == 0 ){
        actSL = actLD->SLdiv;
        while( actSL != NULL ){
          contDiv++;
          actSL = actSL->sig;
        }
        if( contDiv == X )
          fprintf(arch,"%d",actLD->N);
      }
      actLD = actLD->sig;
    }
  }
}



