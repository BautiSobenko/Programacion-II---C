#include <stdio.h>
#include <stdlib.h>

typedef struct NodoS{
  char palabra[10];
  unsigned int apariciones;
  struct NodoS* sig;
}NodoS;

typedef struct NodoS* TSubLista;

typedef struct NodoS* TListaC;

typedef struct Nodo{
  char letra;
  TSubLista SL;
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

void Elimina(TLista L, char palabra[]);

void GeneraListaC(TLista L, TListaC *LC);

int main(){

  TLista L;
  TListaC LC,

  Elimina(L,"Mesada");

  GeneraListaC(L,&LC);

  return 0;
}

void Elimina(TLista L, char palabra[]){

  TLista actL = L;
  TSubLista antSL,actSL;

  while( actL != NULL && actL->letra < palabra[0] )
    actL = actL->sig;
  if( actL != NULL ){ //Encuentro la letra
    antSL = NULL;
    actSL = actL->SL;
    while( actSL != NULL && strcmp(actSL->palabra,palabra)< 0 ){
      antSL = actSL;
      actSL = actSL->sig;
    }
    if( actSL != NULL ){ //Encuentro la palabra
      if( antSL == NULL ) //Elimino
        actL->SL = actL->SL->sig;
      else
        antSL->sig = actSL->sig;
      free(actSL);
    }
  }
}

void GeneraListaC(TLista L, TListaC *LC){

  TLista actL = L;
  TSubLista actSL;
  TListaC nuevoLC;


  while( actL != NULL ){
    if( actL->letra == 'a' ||
        actL->letra == 'e' ||
        actL->letra == 'i' ||
        actL->letra == 'o' ||
        actL->letra == 'u' ){

         actSL = actL->SL;
         while( actSL != NULL ){
           if( actSL->apariciones > 5 ){
             nuevoLC = (TListaC)malloc(sizeof(NodoS));
             nuevoLC->apariciones = actSL->apariciones;
             strcpy(nuevoLC->palabra,actSL->palabra);
             if( *LC == NULL )
               nuevoLC->sig = nuevoLC;
             else{
               nuevoLC->sig = (*LC)->sig;
               (*LC)->sig = nuevoLC;
             }
             *LC = nuevoLC;
           }
           actSL = actSL->sig;
         }
        }
        actL = actL->sig;
  }
}

void EliminaLC(TListaC *LC, int X){

  TListaC antLC , actLC;

  if( *LC != NULL ){
    antLC = *LC;
    actLC = (*LC)->sig;
  }

  while( actLC->sig != *LC->sig && actLC->dato == X ){
    antLC = actLC;
    actLC = actLC->sig;
  }
  if( actLC->dato == X){
    if( *LC->sig = *LC)
      *LC = NULL;
    else{
      if( actLC == *LC )
        *LC = antLC;
      antLC->sig = actLC->sig;
    }
    free(actLC);
  }
}

