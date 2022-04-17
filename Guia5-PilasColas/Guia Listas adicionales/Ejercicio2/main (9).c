#include <stdio.h>
#include <stdlib.h>

///ESTRUCTURA DE LISTAS

typedef struct Nodo{
    int num;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

///PROTOTIPOS

void GeneraListas(TLista *LO,TLista *LI,TLista *LP);

int main(){

    TLista LO,LI,LP;
    GeneraListas(&LO,&LI,&LP);

    return 0;
}

///FUNCIONES

void GeneraListas(TLista *LO,TLista *LI,TLista *LP){

    TLista actI,antI;
    TLista actP,antP;
    TLista auxO;

    while ( *LO != NULL ){
      auxO = *LO;
      *LO = (*LO)->sig;
      if(auxO->num%2!=0){   //IMPAR --> Orden descendente
        if(auxO == NULL || auxO->num >= (*LI)->num){ //Caso cabeza
          auxO->sig = *LI;
          *LI = auxO;
        }else{ //Caso cuerpo o cola
          antI = NULL;
          actI = *LI;
          while( actI != NULL && actI->num > auxO->num){
            antI = actI;
            actI = actI->sig;
          }
          antI->sig = auxO;
          auxO->sig = actI;
        }
      }else{         //PAR --> Orden ascendente
        if(*LP == NULL || auxO->num <= (*LP)->num){ //Caso cabeza
          auxO->sig = *LP;
          *LP = auxO;
        }else{ //Caso cuerpo o cola
          antP = NULL;
          actP = *LP;
          while( actP != NULL && actP->num < auxO->num){
            antP = actP;
            actP = actP->sig;
          }
          antP->sig = auxO;
          auxO->sig = actP;
        }
      }
    }
}
