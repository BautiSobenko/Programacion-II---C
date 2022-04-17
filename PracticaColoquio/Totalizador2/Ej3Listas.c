#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoS{
  char codMat[5];
  unsigned int cantIntentos;
  int año;
  float notaProm;
  struct NodoS* sig;
}NodoS;

typedef struct NodoS* TSubLista;

typedef struct NodoD{
  char legajo[6];
  char facultad[5];
  TSubLista SL;
  struct NodoD *ant,*sig;
}NodoD;

typedef struct NodoD* PNodoD;

typedef struct TListaD{
  PNodoD pri,ult;
}TListaD;

typedef struct NodoC{
  char legajo[6];
  char codMat[5];
  int fechaUltEval;s
  struct NodoC* sig;
}NodoC;

typedef struct NodoC* TListaC;

void Actualiza(TListaD *LD,TListaC *LC,int año,char legajo[],char facultad[],char codMat[],int nota);

int main(){

  TListaD LD;
  TListaC LC;

  Actualiza(&LD,&LC,2020,"AB324","UNMP","XX324",7):


  return 0;
}

void Actualiza(TListaD *LD,TListaC *LC,int año,char legajo[],char facultad[],char codMat[],int nota){

  PNodoD actLD = *LD.pri;
  TSubLista antSD,actSD;
  TListaC nuevoC, antC, actC;

  while( actLD != NULL && strcmp(legajo,actLD->legajo)!=0 && strcmp(facultad,actLD->facultad)!=0)
    actLD = actLD->sig;
  if( actLD != NULL ){ //Encuentro facultad + legajo
    antSD = NULL;
    actSD = actLD->SL;
    while( actSD != NULL && strcmp(actSD->codMat,codMat)<0 ){
      antSD = actSD;
      actSD = actSD->sig;
    }
    if( actSD != NULL ){ //Encuentro materia
      if( actSD->cantIntentos == 2 ){ //Se quita la materia de la SL
        nuevoC = (TListaC)malloc(sizeof(NodoC));
        nuevoC->fechaUltEval = actSD->año;
        strcpy(nuevoC->legajo,actLD->legajo);
        strcpy(nuevoC->facultad,actLD->facultad);
        if( *LC == NULL ){
          nuevoC->sig = nuevoC;
          *LC = nuevoC;
        }else{
          if( strcmp(nuevoC->legajo,(*LC)->legajo)>0 ){
            nuevoC->sig = (*LC)->sig;
            (*LC)->sig = nuevoC;
            *LC = nuevoC;
          }else{
            antC = *LC; //Importante para insertar en primera posicion
            actC = (*LC)->sig;
            while( strcmp(actC->legajo,nuevoC->legajo)<0 ){
              antC = actC;
              actC = actC->sig;
            }
            if( strcmp(actC->legajo,nuevoC->legajo)==0 ){ //Si se repite no agrego ningun nodo, solo actualizo
              actC->fechaUltEval = nuevoC->fechaUltEval;
              free(nuevoC);
            }else{
              antC->sig = nuevoC;
              nuevoC->sig = actC;
            }
          }
        }
        if( antSD == NULL )
          actLD->SL = actLD->SL->sig;
        else
          antSD->sig = actSD->sig;
        free(actSD);
      }
      if( actLD->SL == NULL ){
        if( actLD == (*LD).pri ){
          (*LD).pri = actLD->sig;
          (*LD).pri->ant = NULL;
        }else
        if( actLD == (*LD).ult ){
          (*LD).ult = actLD->ant;
          (*LD).ult->sig = NULL;
        }else{
          actLD->sig->ant = actLD->ant;
          actLD->ant->sig = actLD->sig;
        }
        free(actLD);
      }
    }
  }




}
