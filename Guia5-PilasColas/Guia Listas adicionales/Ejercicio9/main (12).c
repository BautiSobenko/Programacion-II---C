#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CONSTANTES

#define MAXDOC 11;

///ESTRUCTURA DE LISTAS

typedef struct Nodo{
  char doc[MAXDOC];
  char sexo;
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* TListaC;

///PROTOTIPOS

void ListarVotantesFem(TListaC LC);

///PROGRAMA PRINCIPAL

int main(){

    TListaC LC;

    ListarVotantesFem(LC);

    return 0;
}

///FUNCIONES

void ListarVotantesFem(TListaC LC){

  TListaC auxL = LC->sig; // Me paro en el primer elemento de la lista
  while ( auxL != LC ){
    if( auxL->sexo == 'F' )
      printf("%s\n",auxL->doc);
    auxL = auxL->sig;
  }


}
