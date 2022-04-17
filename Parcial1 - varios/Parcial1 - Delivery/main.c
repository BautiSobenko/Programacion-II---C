#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//No declara .h

///CONSTANTES

#define MAXCOD 3
#define COM 0.7 //Comision que percibe la empresa

///ESTRUCTURA

typedef struct Pedidos{
  char codComercio[MAXCOD];
  unsigned int id;
  int CodAutorizacion;
  float importe;
}Pedidos;

typedef Pedidos TElementoC;

typedef struct Nodito{
  unsigned int id;
  float importe;
  struct Nodito* sig;
}Nodito;

typedef struct Nodito* SubListaP; //Sublista de pedidos

typedef struct NodoC{
  char codComercio[MAXCOD];
  float importeCom; //Importe total comisiones
  SubListaP SLP;    //Sublista pedidos
  struct NodoC* sig;
}NodoC;

typedef struct NodoC* TListaC;

///PROTOTIPOS

void ActualizaLista(TListaC *LC,TCola *C);

void Elimina(TListaC *LC);

///FUNCION MAIN

int main(){

  TCola C;    //Cola de pedidos;
  TListaC LC; //Lista comercios

  ActualizaLista(&LC,&C);
  Elimina(&LC);


  return 0;

}
///FUNCIONES

void ActualizaLista(TListaC *LC,TCola *C){

  TListaC actLC, antLC, nuevoC;
  TCola Caux; //Cola auxiliar para no autorizados
  TElementoC pedido;
  SubListaP nuevoP, antSLP,actSLP;

  IniciaC(&Caux); //Inicio cola auxiliar ( NO OLVIDAR )

  while( !VaciaC(*C) ){ //Mientras que la cola no este vacia
    SacaC(C,&pedido);
    if( pedido.CodAutorizacion != 0){ //Si el pago esta autorizado
      actLC = *LC;
      antLC = NULL;
      while( actLC != NULL && strcmp(pedido.codComercio,actLC->codComercio) != 0 ){ //Busco en lista de comercio
        antLC = actLC;
        actLC = actLC->sig;
      }
      if( actLC != NULL ){ //Si encuentro el comercio
        actSLP = actLC->SLP; //Cabeza de sublista pagos
        antSLP = NULL;
        actLC->importeCom += pedido.importe*COM; //Sumo comision del pedido al total
          while( actSLP != NULL && pedido.id > actSLP->id ){ //Busco en sublista de pagos
            antSLP = actSLP;
            actSLP = actSLP->sig;
          }
          nuevoP = (SubListaP)malloc(sizeof(Nodito));   //Creo nodo
          nuevoP->id = pedido.id;                       //Guardo id
          nuevoP->importe = pedido.importe;             //Guardo importe
          if( antSLP == NULL ){ //Si la sublista esta vacia o es anterior al primer elemento
            nuevoP->sig = actSLP;
            actLC->SLP = nuevoP;
          }else{ //Si estoy en el cuerpo o cola de la sublista
            antSLP->sig = nuevoP;
            nuevoP->sig = actSLP;
          }
      }
      else{ //No encontre el comercio, ya sea pq la lista estaba vacia o llegue al fin de la lista
        nuevoC = (TLIstaC)malloc(sizeof(Nodo));          //Creo nuevo comercio
        strcpy(nuevoC->codComercio,pedido.codComercio);  //Guardo codigo de comercio
        nuevoC->importeCom = pedido.importe*COM;         //Guardo comision del comercio
        if( *LC == NULL){ //Agrego comercio si la lista esta vacia
          nuevoC->sig = *LC;
          *LC = nuevoC;
        }else{           //Agrego comercio si llegue al final de la lista y no lo encontre
          antLC->sig = nuevoC;
          nuevoC->sig = actLC;
        }
        //Como el comercio no existia no tengo que insertar en orden
        nuevoP = (SubListaP)malloc(sizeof(Nodito)); //Nuevo pedido pago del comercio
        nuevoP->id = pedido.id;
        nuevoP->importe = pedido.importe;
        nuevoP->sig = NULL; //Asigno NULL al siguiente del pedido
        actLC->SLP = nuevoP; //Desplazo la cabeza de la lista
      }
    }else
      PoneC(&Caux,pedido); //Almaceno en cola auxiliar
  }

  while( !VaciaC(Caux) ){ //Devuelvo los pedidos con pagos no autorizados a la lista original
    SacaC(&Caux,&pedido);
    PoneC(C,pedido);
  }
}

void Elimina(TListaC *LC){

  float topeImp;
  char codCom[MAXCOD];
  TListaC antC,actC;
  SubListaP antSC,actSC,elimSC;
  int contElim=0;
  float suma=0;

  printf("Ingrese codigo de comercio: ");
  gets(codCom);
  printf("\nIngrese un importe tope: ");
  scanf("%f",&topeImp);

  if(*LC != NULL){
    antC = NULL;
    actC = *LC;
  }
  while( actC != NULL && strcmp(codCom,actC->codComercio) != 0){ //Busco comercio
    antC = actC;
    actC = actC->sig;
  }
  if( actC != NULL ){ //Si encuentro comercio
    antSC = NULL;
    actSC = actC->SLP;
    while( actSC != NULL ){ // Recorro lista
      if( actSC->importe < topeImp ){ //Si cumple la condicion
        elimSC = actSC;
        actSC = actSC->sig;
        contElim++; //Cuento eliminados
        suma+=actSC->importe; //Suma de importes de pedidos eliminados
        actC->importeCom -= actSC->importe*COM; //Decremento el importe ganado por comisiones
        free(elimSC); //Elimino nodo
        if( elimSC == actC->SLP ) //Caso cabeza
          actC->SLP = actC->SLP->sig;
        else
          antSC->sig = actSC;
      }else{
        antSC = actSC;
        actSC = actSC->sig;
      }
    }
    printf("\nComercio: %s\n",actC->codComercio); //!No verifica que cont sea != 0
    printf(" Cantidad de pedidos eliminados: %d\n",contElim);
    printf(" Importe promedio de un pedido eliminado: %f\n",(float)suma/contElim);
    if( !actC->SLP ){ //Comercio se queda sin pedidos
      if( actC == *LC )
        *LC = (*LC)->sig;
      else
        antC->sig = actC->sig;
      free(actC);  //Elimino comercio
    }
  }
}
