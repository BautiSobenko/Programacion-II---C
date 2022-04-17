#include <stdio.h>
#include <stdlib.h>

///ESTRUCTURA DE LISTAS

typedef struct NodoS{
    int num;
    struct NodoS* sig;
}NodoS;

typedef struct NodoS* TListaS;

typedef struct NodoD{
    int num;
    struct NodoD *ant,*sig;
}NodoD;

typedef struct PNodoD* ;

typedef struct TListaD{
    PNodoD pri;
    PNodoD ult;
}TListaD;

///PROTOTIPOS

void Copia(TListaS LS, TListaD *LD);

int main(){

    TListaS LS;


    return 0;
}

void Copia(TListaS LS, TListaD *LD){

    TListaS auxLS;
    PNodoD auxLD;

    if( auxLS != NULL ){
      auxLS = LS;
      TListaD.pri=NULL;
      TListaD.ult=NULL;
      auxLD = (*LD).pri
      while( auxLS != NULL ){
        if(  )

      }
    }


}
