#include <stdio.h>
#include <stdlib.h>

///Estructura de listas

typedef struct NodoD{
    int num;
    struct NodoD* ant;
    struct NodoD* sig;
}NodoD;

typedef struct NodoD* PNodoD; //Creacion de lista

typedef struct NoditoD{
    PNodoD pri;
    PNodoD ult;
}NoditoD;

typedef struct NoditoD TListaD;//Creacion de cabeza

///Prototipos

void EliminacionMultLD(TListaD *LD);

int main(){

    TListaD LD;
    EliminacionMultLD(&LD);


    return 0;
}

void EliminacionMultLD(TListaD *LD){

    PNodoD aux;
    PNodoD elim;

    if((*LD).pri != NULL){
      aux = (*LD).pri;
      while( aux != NULL ){ //Mientras que no se termine la lista
        if( aux->num %2 ==0 ){//Si es par
          elim = aux;
          if( aux->ant == NULL){ //Caso cabeza
            (*LD).pri = (*LD).pri->sig;
          }else{                 //Caso cola o cuerpo
            if(aux->sig == NULL){
              (*LD).ult = (*LD).ult->ant;
              (*LD).ult->sig = NULL;
            }
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
          }
          aux = aux->sig;
          free(elim);
        }else           //Si es impar, sigo buscando
          aux = aux->sig;
      }
    }
}
