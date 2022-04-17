#include "IntCola.h"
#include "IntPila.h"


///DEFINICION TIPO LISTA

typedef struct NodoLista{ //Defino lista enlazada
    TCola C;          //Creo cola dentro de nodo
    struct Nodo* sig;
}NodoLista;

typedef struct NodoLista* TLista;

///PROTOTIPOS

void MaximosSublista(TLista L, TPila *P);

int main(){

    TLista L;
    TPila P;
    MaximosSublista(L,&P);


    return 0;
}

void MaximosSublista(TLista L, TPila *P){

    TLista aux = L;
    int i;
    int MaxC; //Maximo de sublista(cola)
    IniciaP(P);

    while( aux != NULL ){ ///RECORRIDO DE LISTA
      MaxC = aux->C->datos[aux->C->pri];
      ///PRI < ULT
      if(aux->C->pri < aux->C->ult){
        for(i=aux->C->pri; i<=aux->C->ult ;i++){
          if(aux->C->datos[i]>MaxC)
            MaxC = aux->C->datos[i];
        }
      }else{
        ///PRI > ULT
        if(aux->C->pri > aux->C->ult){
          for(i=0; i<= aux->C->ult;i++) ///PARA ULT
            if(aux->C->datos[i]>MaxC)
              MaxC = aux->C->datos[i];
          for(i=aux->C->pri; i<MaxElem;i++) ///PARA PRI
            if(aux->C->datos[i]>MaxC)
              MaxC = aux->C->datos[i];
          }
        }else{
          ///PRI = ULT
          if(aux->C->pri == aux->C->ult){
            MaxC = aux->C->datos[aux->C->pri];
          }
        }
      PoneP(P,MaxC); ///INSERTA EN PILA EL MAXIMO
      aux = aux->sig;
    }





    }



}
