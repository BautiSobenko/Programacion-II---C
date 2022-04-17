#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoS{
  char CodMat[5];
  int cantIntentos;
  int año;
  float notaProm;
  struct NodoS *sig;
}NodoS;

typedef struct NodoS* TSubLista;

typedef struct Nodo{
  char legajo[6];
  char facultad[5];
  TSubLista SLM; //Sublista materias
  struct Nodo *sig,*ant;
}Nodo;

typedef struct Nodo* PNodo;

typedef struct TListaD{
  PNodo pri,ult;
}TListaD;

typedef struct NodoC{
  char legajo[6];
  char codMat[5];
  int año;
  struct NodoC* sig;
}NodoC;

typedef struct NodoC* TListaC;

void ActualizaLista(TListaD *LD,TListaC *LC,int año,char legajo[],char codMat[],int nota);

int main(){

  TListaC LC;
  TListaD LD;

  ActualizaLista(&LD,&LC,2020,"ADE43","UNMDP","A232",3);


  return 0;
}


void ActualizaLista(TListaD *LD,TListaC *LC,int año,char legajo[],char facultad[],char codMat[],int nota){

  PNodo actL = (*LD).pri;
  TSubLista actSL, antSL; //Eliminacion en sublista
  TListaC nuevo,actLC;

  while( actL != NULL && strcmp(legajo,actL->legajo)!=0 && strcmp(facultad,actL->facultad)!=0 ){
    actL = actL->sig;
  }
  if( actL != NULL ){ //Se encuentra alumno (legajo y facultad)
    antSL = NULL;
    actSL = actL->SLM;
    while( actSL != NULL && strcmp(actSL->CodMat,codMat)<0 ){
      antSL = actSL;
      actSL = actSL->sig;
    }
    if( actSL != NULL ){ //Encontramos la materia
      if( actSL->cantIntentos == 2 ){ //3er intento fallido c/este
        nuevo = (TListaC)malloc(sizeof(NodoC));
        nuevo->año = actSL->año;
        strcpy(nuevo->codMat,actSL->CodMat);
        strcpy(nuevo->legajo,actL->legajo);
        actLC = (*LC)
        while( actLC != NULL && actLC->sig != *LC && strcmp(actLC->legajo,nuevo->legajo)<0 ){
          actLC = actLC->sig;
        }
        if( actLC != NULL ){ //Lista vacia
          nuevo->sig = nuevo;
          *LC = nuevo;
        }else{
          nuevo->sig = actLC->sig;
          actLC->sig = nuevo;
          if( actLC == *LC )
            *LC = nuevo;
        }
       if( antSL == NULL )
         actL->SLM = actL->SLM->sig;
       else
         antSL->sig = actSL->sig;
       free(actSL);
      }
    }
    if( actL->SLM == NULL ){ //Me quedo sin materias pendientes de aprobacion
      if( actL->ant == NULL ) //Caso pri
        (*LD).pri = (*LD).pri->sig;
        (*LD).pri->ant = NULL;
      else
      if( actL->sig == NULL)  //Caso ult
        (*LD).ult = (*LD).ult->ant
        (*LD).ult->sig = NULL;
      else{
        actL->sig->ant = actL->ant;
        actL->ant->sig = actL->sig;
      }
      free(actL);
    }
  }
}

void Aparicion(TArbol A, posicion p, int K, int nivel,int *nivelK){

  if( !nulo(p) ){
    Aparicion(A,HijoMasIzq(p,A),K,nivel+1,nivelK);
    if( info(p,A) == K )
      *nivelK = nivel;
    else{
      Aparicion(A,HermanoDer(p,A),K,nivel,nivelK);
    }
  }
}

int TodasEnNivelK(TArbol A, posicion p,int K, int nivel ){

  if( nulo(p) || nivel%2 != 0 && info(p,A) == K)
    return 0;
  else
    return TodasEnNivelK(A,HijoMasIzq(p,A),K,nivel+1) && TodasEnNivelK(A,HijoMasIzq(p,A),K,nivel);
}

