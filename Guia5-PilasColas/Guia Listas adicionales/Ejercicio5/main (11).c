#include <stdio.h>
#include <stdlib.h>

///ESTRUCTURA DE LISTAS

typedef struct NodoD{
    int num;
    struct NodoD *sig,*ant;
}NodoD;

typedef struct NodoD* PNodoD;

typedef struct TListaD{
    PNodoD pri;
    PNodoD ult;
}TListaD;

///PROTOTIPOS

void InsertaMedio(TListaD *LD, int num);

void EliminaX(TListaD *LD, int x);

void MuestraLista(TListaD LD);

int main(){

  TListaD LD;
  LD.pri = NULL;
  LD.ult = NULL;
  InsertaMedio(&LD,3);
  InsertaMedio(&LD,2);
  InsertaMedio(&LD,5);
  InsertaMedio(&LD,10);
  InsertaMedio(&LD,20);
  InsertaMedio(&LD,40);
  InsertaMedio(&LD,60);
  InsertaMedio(&LD,100);
  InsertaMedio(&LD,60);
  InsertaMedio(&LD,100);
  InsertaMedio(&LD,60);
  InsertaMedio(&LD,60);
  InsertaMedio(&LD,60);
  InsertaMedio(&LD,60);
  InsertaMedio(&LD,60);

  EliminaX(&LD,60);

  MuestraLista(LD);


  return 0;
}

///FUNCIONES

void InsertaMedio(TListaD *LD, int num){

  PNodoD actPri, actUlt;
  actPri = (*LD).pri;
  actUlt = (*LD).ult;
  PNodoD nuevoD = (PNodoD)malloc(sizeof(NodoD));
  nuevoD->num = num;

  if( actPri == NULL ){ //La list esta vacia
    nuevoD->ant = NULL;
    nuevoD->sig = NULL;
    (*LD).pri = nuevoD;
    (*LD).ult = nuevoD;
  }else{
  while( actPri->sig != actUlt && actPri != actUlt ){
    actPri = actPri->sig;
    actUlt = actUlt->ant;
  }
  if( actPri->sig == actUlt ){ //Cantidad de datos par
    actPri->sig = nuevoD;
    nuevoD->ant = actPri;
    nuevoD->sig = actUlt;
    actUlt->ant = nuevoD;
  }else{
    if( actPri == actUlt ){ //Cantidad de datos impar
      if( (*LD).pri == (*LD).ult )
        (*LD).ult = nuevoD;
      else
        actUlt->sig->ant = nuevoD;
      nuevoD->sig = actUlt->sig; //o actPri
      nuevoD->ant = actUlt;
      actUlt->sig = nuevoD;
    }
  }
  }
}

void EliminaX(TListaD *LD, int x){

  PNodoD actPri = (*LD).pri;
  PNodoD actUlt = (*LD).ult;
  PNodoD elim;


  while( actPri->ant != actUlt &&  actPri != actUlt){ //Busqueda en lista doble en casos par e impar
    if( x == actPri->num ){ //Si encuentro con el pri
      elim = actPri;
      if( actPri == (*LD).pri ){ //Caso cabeza de pri
        (*LD).pri = (*LD).pri->sig;
        (*LD).pri->ant = NULL;
      }else{ //Caso cuerpo/cola de pri
        actPri->ant->sig = actPri->sig;
        actPri->sig->ant = actPri->ant;
      }
      actPri = actPri->sig;
      free(elim);
    }else
      actPri = actPri->sig; //Si no es igual sigo buscando

    if( x == actUlt->num ){ //Si encuentro con ult
      elim = actUlt;
      if( actUlt == (*LD).ult ){ //Caso cabeza con ult
        (*LD).ult = (*LD).ult->ant;
        (*LD).ult->sig = NULL;
      }else{
        actUlt->ant->sig = actUlt->sig;
        actUlt->sig->ant = actUlt->ant;
      }
      actUlt = actUlt->ant;
      free(elim);
    }else
      actUlt = actUlt->ant;
  }
  if(actPri == actUlt && actPri->num == x){
    free(actPri);
  }
}

void MuestraLista(TListaD LD){

  PNodoD auxL = LD.pri;

  while ( auxL != NULL ){
    printf("%d\n",auxL->num);
    auxL = auxL->sig;
  }
}


