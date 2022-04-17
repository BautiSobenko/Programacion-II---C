#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CONSTANTES

#define MAXC 20

///ESTRUCTURA DE LISTAS

typedef struct Nodo{
  char apellido[MAXC];
  char nombre[MAXC];
  char categoria;
  struct Nodo *ant,*sig;
}Nodo;

typedef struct Nodo* pNodo;

typedef struct TListaD{
  pNodo pri;
  pNodo ult;
}TListaD;

///PROTOTIPOS

void Listado(TListaD LD,float importe);

void ListadoDescendenteExt(TListaD LD);

int BuscaNomApell(TListaD LD,char nombre[],char apellido[]);

int main(){

  Listado(LD,importe);

  ListadoDescendenteExt(LD);

  BuscaNomApell(LD,nombre,apellido);

  return 0;
}

///FUNCIONES

void Listado(TListaD LD,float importe){

  pNodo actL;
  float total=0;

  if( LD.pri != NULL )
    actL = LD.pri;
  while ( actL != NULL ){
    switch(actL->categoria){
      case 'D':total+=importe*0.7;break;
      case 'A':total+=importe*0.9;break;
      case 'E':total+=importe;break;
      default:break;
    }
    printf("\n%s %s\n",actL->nombre,actL->apellido);
    actL = actL->sig;
  }
  printf("%f\n",total);
}

void ListadoDescendenteExt(TListaD LD){

  pNodo actL;

  if( LD.ult != NULL )
    actL = LD.ult;
  while (actL != NULL ){
    if( actL == 'E' )
      printf("%s %s\n",actL->nombre,actL->apellido);
    actL = actL->ult;
  }
}

int BuscaNomApell(TListaD LD,char nombre[],char apellido[]){

  pNodo auxL;

  if( auxL != NULL )
    auxL = LD.pri;
  while( auxL != NULL && strcmp(nombre,auxL->nombre) > 0 && strcmp(apellido,auxL->apellido) > 0){
    auxL = auxL->sig;
  }
  if( auxL != NULL )
    return 1;
  else
    return 0;
}

