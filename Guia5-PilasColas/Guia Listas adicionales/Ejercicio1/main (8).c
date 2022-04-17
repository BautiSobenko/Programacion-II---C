#include <stdio.h>
#include <stdlib.h>

///Estructura de listas

typedef struct Nodo{
    int num;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

///Proptotipos

int VerificaIgualdad(TLista L1,TLista L2);

void DeUnaAOtra(TLista *L1,TLista *L2);

void EliminaSegunPos(TLista *L1,TLista L2);

int main(){

    TLista L1,L2;
    VerificaIgualdad(L1,L2);
    DeUnaAOtra(&L1,&L2);
    EliminaSegunPos(&L1,L2);


    return 0;
}

int VerificaIgualdad(TLista L1,TLista L2){
/*
Duda:
No se como considerar que estan ordenadas
preguntar.
if(L1->num > L1->sig->sig && L2->num > L2->sig->num){//Verifica orden ascendente
}
if(L1->num < L1->sig->sig && L2->num < L2->sig->num){//Verifica orden descendente
}
*/

    TLista aux1;
    TLista aux2;



    if( L1 != NULL && L2 == NULL || L2 != NULL && L1 == NULL) //Una vacia, otra con elementos, resultaria en una desigualdad
      return 0;
    else
      if( L1 == NULL && L2 == NULL ){ //Las dos vacias resultaria en una igualdad
        return 1;
      }else
        if( L1 != NULL && L2 != NULL ){//Las dos con elementos, no me asegura nada, debo analizar
          aux1 = L1;
          aux2 = L2;
          //Si un aux llega a NULL significa que ambos llegaron
          while( aux1 != NULL && aux1->num==aux2->num){//Mientras que las listas no se terminen..
            aux1 = aux1->sig;
            aux2 = aux2->sig;
          }
          if(aux1->num != aux2->num) //Sale del while pq los elementos difieren
            return 0;
          if(aux1 == NULL && aux2 == NULL) //Cuando sale del while ambos punteros quedan iguales
            return 1;
    }

void DeUnaAOtra(TLista *L1,TLista *L2){

    TLista aux1, aux2;

    if(*L1 != NULL && *L2 != NULL){
      aux1 = *L1;
      while( aux1->sig != NULL ) // Me paro al final de L1
        aux1 = aux1->sig;
      }
      if(*L2->num > aux1->num){ //Si cumple la condicion
        aux1->sig = *L2; //Enlazo el ultimo elemento de L1 a la cabeza de L2
      }else{
        aux2 = *L2;
        while( aux2->sig != NULL ) // Me paro al final de L2
          aux2 = aux2->sig;//Enlazo el ultimo elemento de L2 a la cabeza de L1
        }
        aux2->sig = *L1;
      }

void EliminaSegunPos(TLista *L1,TLista L2){

    TLista act1,ant1,aux2;
    int cont;

    if(*L1 != NULL && L2 != NULL){ //Si ambas pilas tienen elementos
      aux2 = L2;//Me paro en la cabeza
      while( aux2 != NULL ){ //Mientras que no se termine
        cont = 1; //Inicializo siempre el contador en 1
        act1 = *L1;
        ant1 = NULL;
        if( aux2->num > 0){ //Positivo ya que no tengo posiciones negativas
          while( act1 != NULL && cont<aux2->num){ //Contador para saber en que posicion pararme
            cont++;
            ant1 = act1;
            act1 = act1->sig;
          }
          if( act1 != NULL ){ //Si no me cai
            elim = act1;
            if( act1 = *L1 ) //Caso cabeza
              *L1 = *L1->sig;
            else             //Caso cuerpo,cola
              ant1->sig = act1->sig;
            act1 = act1->sig;
            free(elim);
          }
        }
        aux2 = aux->sig; //Sigo recorriendo L2
      }
    }
}
