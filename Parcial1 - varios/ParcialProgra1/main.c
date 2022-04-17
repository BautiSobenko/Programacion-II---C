#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntCola.h"

typedef TAuto TelementoC;

typedef struct TAuto{
  char patente[8];
  char tipoCombustible[3];
  float cargaLitros;
}TAuto;

//!Estructura cola

typedef struct NoditoC{
  char tipoCombustible[3];
  float disponibilidad;
  struct NoditoC* sig;
}NoditoC;

typedef struct NoditoC* SubListaC; //Sublista deposito de combustibles

typedef struct NodoS{
  unsigned int NumSurtidor;
  SubListaC SLC;
  struct NodoS* sig;
}NodoS;

typedef struct NodoS* TListaS; //Lista de surtidores

///PROTOTIPOS

void Distribucion(TListaS LS,TCola *CA);

void Reabastecimiento(TListaS LS);

int main(){

  TCola CA; //Cola autos
  TListaS LS;
  Carga(&CA);
  CargaL(&LS);

  Distribucion(LS,&CA);

  Reabastecimiento(LS);

  return 0;
}

///FUNCIONES

void Distribucion(TListaS LS,TCola *CA){

  TelementoC auto;
  TListaS actS; //Utilizo la variable para realizar el recorrido
  SubListaC actSLC;
  int encuentro=0, noAtendidos=0;

  while( !VaciaC(*CA) ){
    sacaC(CA,&auto);
    if( encuentro == 0 )
      actS = LS; //Me paro en la cabeza de la lista surtidores
    else{
      actS = actS->sig; //Si previamente encontre, me paro en el siguiente surtidor
      encuentro = 0;
    }
    while( actS != NULL && encuentro == 0 ){ //Recorro lista surtidores
      actSLC = actS->SLC; //Me paro en la cabecera de la sublista
      while( actSLC != NULL && ( strcmp(auto.tipoCombustible > actSLC->tipoCombustible) > 0 || auto.cargaLitros >= actSLC->disponibilidad )){
       actSLC = actSLC->sig;
      } //Recorro lista de deposito
      if( actSLC != NULL ){ //Surtidor cumple las condiciones (Mismo tipo de combustible y disponibilidad suficiente del mismo)
        encuentro = 1;
        actSLC->disponibilidad -= auto.cargaLitros; //Actualizo la disponibilidad del combustible
      }else //Surtidor no cumple las condiciones o llego al final de la sublista
        actS = actS->sig; //Paso al siguiente surtidor
    }
    if( actS == NULL ) // No se pudo asignar un automovil a un surtidor
      noAtendidos++;
  }
  if( noAtendidos )
    printf("La cantidad de autos no atendidos es: %d\n",noAtendidos);
  else
    printf("Todos los autos fueron atendidos\n");
}

void Reabastecimiento(TListaS LS){

  float K;
  char TC[3];
  TListaS actS;
  SubListaC antSLC, actSLC, nuevoC;
  int contReabast=0;

  printf("Tipo de combustible: "); scanf("%s",TC);
  printf("\nLitros de combustible: "); scanf("%f",&K);

  if( LS != NULL )
    actS = LS;
  while( actS != NULL && K > 0 ){ //Recorro lista de surtidores
    if( (actS->NumSurtidor)%2 != 0  ){ //Encuentro surtidor de numero impar
      antSLC = NULL;
      actSLC = actS->SLC;
      while( actSLC != NULL && strcmp(TC,actSLC->tipoCombustible) > 0){
        antSLC = actSLC;
        actSLC = actSLC->sig;
      }//Recorro sublista hasta encontrar el tipo de combustible
      if( actSLC != NULL ){//Encontre el tipo de combustible
        if( K <= 10000 ){ //! Lo hice mal
          nuevoC->disponibilidad = K;
          K = 0
        }else{
          nuevoC->disponibilidad = 10000;
          contReabast++;
          K -= nuevoC->disponibilidad;
        }
      }else{ //No encuentro tipo de combustible, Insercion ordenada
        nuevoC = (SubListaC)malloc(sizeof(NoditoC));
        strcpy(nuevoC->tipoCombustible,TC);
        if( K <= 10000){
          nuevoC->disponibilidad = K;
          K = 0
        }else{
          nuevoC->disponibilidad = 10000;
          K -= 10000;
        }
        nuevoC->sig = actSLC;
        if( antSLC == NULL ) //Caso cabeza
          actS->SLC = nuevoC;
        else
          antSLC->sig = nuevoC;
      }
    }
    actS = actS->sig;
  }
  if(K){
    printf("No se pudieron distribuir todos los litros de combustible de tipo %s\n",TC);
    printf("Excedente = %f\n",K);
    printf("Surtidores reabastecidos %d\n",contReabast);
  }else
    printf("Todos los litros de combustible %s han sido distribuidos\n",TC);
}
