#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntCola.h"

typedef struct NoditoPedidos{
  unsigned int idPedido;
  float importe;
  struct NoditoPedidos* sig;
}NoditoPedidos;

typedef NoditoPedidos* SubListaP; //Sublista pedidos autorizados

typedef struct NodoComercio{
  char codComercio[3];
  float totalComision;
  SubListaP SLp;
  struct NodoComercio* sig;
}NodoComercio;

typedef NodoComercio* TListaC; //Lista comercios

///PROTOTIPOS

void ActualizaLista(TListaC *Lc,TCola *Cp);

void EliminaPedidos(TListaC *Lc);

int main(){

  TListaC Lc; //Lista comercios
  TCola Cp;   //Cola pedidos

  ActualizaLista(&Lc,&Cp);

  EliminaPedidos(&Lc);

  return 0;
}

void ActualizaLista(TListaC *Lc,TCola *Cp){

  TCola Caux;
  TelementoC pedido;
  TListaC antLC,actLC, nuevoC;
  SubListaP antSLP, actSLP, nuevoP;

  IniciaC(&Caux);//!Importante
  while (!VaciaC(*Cp)){
    SacaC(Cp,&pedido);
    if(pedido.autPago){ //Pedido autorizado != 0
      antLC = NULL;
      actLC = *Lc;
      while( actLC != NULL && strcmp(pedido.codComercio,actLC->codComercio) !=0 ){//Mientras no encuentre el comercio sigo recorriendo
        antLC = actLC;
        actLC = actLC->sig;
      }
      nuevoP = (SubListaP)malloc(sizeof(NoditoPedidos)); //Se que si o si voy a insertar el nodo,por lo tanto lo creo antes(ahorro codigo)
      nuevoP->idPedido = pedido.idPedido;
      nuevoP->importe = pedido.importe;
      if( actLC != NULL){ //Encuentro el comercio
        actLC->totalComision += pedido.idPedido*0.07; //Actualizo comision
        antSLP = NULL; //Comienzo la insercion en la sublista de pedidos autorizados
        actSLP = actLC->SLp;
        while(actSLP != NULL && pedido.codComercio > actSLP->idPedido ){
          antSLP = actSLP;
          actSLP = actSLP->sig;
        }
        if( antSLP == NULL ){ //Insercion en cabeza, lista vacia o elemento a insertar menor al primero
          nuevoP->sig = actLC->SLp;
          actLC->SLp = actLC->SLp->sig;
        }else{//Insercion intermedia o al final de la lista
          antSLP->sig = nuevoP;
          nuevoP->sig = actSLP;
        }
      }else{ //No encuentro el comercio
        //!Insercion comercio al final de la lista
        nuevoC = (TListaC)malloc(sizeof(NodoComercio));
        strcpy(nuevoC->codComercio,pedido.codComercio);
        nuevoC->totalComision = pedido.importe*0.07; //Actualizo comision
        if( *Lc == NULL ){
          nuevoC->sig = *Lc;
          *Lc = nuevoC;
        }else{
          antLC->sig = nuevoC;
          nuevoC->sig = actLC;
        }
        //Insercion pedido en sublista vacia
        nuevoP->sig = nuevoC->SLp; //Como la sublista esta vacia el nuevo nodo de la sublista apuntara a null
        nuevoC->SLp = nuevoP; //La cabecera ahora apuntar al nuevo nodo
      }
    }else //Pedido no autorizado = 0
      PoneC(&Caux,pedido);
  } //Cola vacia
  while(!VaciaC(Caux)){ //Devuelvo los no autorizados a la cola de pedidos
    SacaC(&Caux,&pedido);
    PoneC(Cp,pedido);
  }
}

void EliminaPedidos(TListaC *Lc){

  char codComercio[3];
  float topeImporte, impElim=0;
  int contElim=0;
  TListaC antLC,actLC; //Variables para posible eliminacion de comercio
  SubListaP antSLP, actSLP, elimSLP;//Variables para posible eliminacion de pedido

  scanf("%s",codComercio); scanf("%d",topeImporte);

  if(*Lc != NULL ){
    antLC = NULL;
    actLC = *Lc;
  }
  while( actLC != NULL && strcmp(codComercio,actLC->codComercio) != 0 ){ //Mientras que no encuentre el codigo de comercio sigo buscando
    antLC = actLC;
    actLC = actLC->sig;
  }
  if( actLC != NULL ){//Encuentro el comercio
    antSLP = NULL; //Me preparo para la posible eliminacion
    actSLP = actLC->SLp;
    while ( actSLP != NULL ){ //Recorro la lista y elimino nodos que no cumplan cierta condicion
      if( actSLP.importe < topeImporte ){ //Pedido menor al importe minimo (No cumple condicion) --> elimino
        contElim++; //Cuento eliminados
        actLC->totalComision -= actSLP->importe*0.07; //Actualizo comision
        impElim += actSLP->importe;
        elimSLP = actSLP;
        actSLP = actSLP->sig;
        if( antSLP == NULL ) //Caso de cabecera
          actLC->SLp = actLC->SLp->sig;
        else
          antSLP->sig = actSLP;
        free(elimSLP);
      }else{ //Pedido es mayor al importe minimo (Cumple condicion) --> sigo buscando
        antSLP = actSLP;
        actSLP = actSLP->sig;
      }
    }
    if(contElim){
      printf("Total de eliminados %d\n",contElim);
      printf("Promedio de pedidos eliminados %f\n",(float)impElim/contElim);
    }
    if( actLC->SLp == NULL ){ //Si me quede sin pedidos, elimino el comercio
      if( antLC == NULL )//Caso cabeza
        *Lc = *Lc->sig;
      else //Caso intermedio/cola
        antLC->sig = actLC->sig;
      free(actLC);
    }
  }
}











