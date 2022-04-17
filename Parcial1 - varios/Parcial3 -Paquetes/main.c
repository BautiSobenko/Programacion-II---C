#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntPilas.h"

///CONSTANTES

#define MAXD 5
#define MAXZ 2
#define MAXDEST 50

///ESTRUCTURA

typedef struct Pila{
  char zona[MAXZ];
  int cod_paq;
  char destinatario[MAXDEST];
  float alto,largo;
  float peso;
}Pila;

typedef Pila TelementoP;

typedef struct Nodito{
  int cod_paq;
  float peso;
  char destinatario[MAXDEST];
  struct Nodito *sig;
}Nodito;

typedef struct Nodito* SubListaP;

typedef struct Nodo{
  char id_dock[MAXD];
  char zona[MAXZ];
  float pesoPerm;
  SubListaP* SL;
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

///PROTOTIPOS

void CargaPaquete(TLista *LD,TPila *PD);

void EliminaPaquete(TLista LD);

///FUNCION MAIN

int main(){

  TLista LD; //Lista docks
  TPila PD;  //Pila docks

  CargaPaquete(&LD,&PD);
  EliminaPaquete(LD);

  return 0;
}

///FUNCIONES

void CargaPaquete(TLista *LD,TPila *PD){

  int codPaq;
  int localizado=0, condicion=0;
  TelementoP paq,paqAux;
  TPila PDaux;
  TLista antL,actL;
  SubListaP antSL,actSL,nuevoL;

  printf("Ingrese codigo de paquete a localizar: ");
  scanf("%d",codPaq);

  while( !VaciaP(*PD) && localizado == 0 ){
    Desapila(PD,&paq);
    iniciaP(&PDaux);
    if( codPaq != paq.cod_paq )
      Apila(&PDaux,paq);
    else{
      localizado = 1;
      while( !VaciaP(PDaux) ){
        Desapila(*PDaux,&paqAux);
        Apila(PD,paqAux);
      }
    }
  }
  //Me quedo el paquete localizado
  if( *LD != NULL ){
    actL = *LD;
  }
  while( actL != NULL && condicion == 0 ){
    if( strcmp(paq.zona,actL->zona) == 0 ){ //Zona buscada
      actSL = actL->SL; //Me paro en la cabeza de la sublista
      antSL = NULL;
      pesoDock = 0;
      while( actSL != NULL ){ //recorro sublista
        pesoDock += actSL->peso;
        actSL = actSL->sig;
      }
      if( pesoDock + paq.peso > actL->pesoPerm ){ // supera permitido
        actL = actL->sig;
      }else{
        condicion = 1; // peso permitido, salgo del while
        nuevoL = (SubListaP)malloc(sizeof(Nodito));
        nuevoL->cod_paq = paq.cod_paq;
        strcpy(nuevoL->destinatario,paq.destinatario);
        strcpy(nuevoL->peso,paq.peso);
        antSL->sig = nuevoL; //Inserto al final de la sublista
        nuevoL->sig = actSL;
      }
    }else{ //La zona no es la que busco, sigo recorriendo
      actL = actL->sig;
    }
  }
}

void EliminaPaquete(TLista LD){

  int codPaq, contZona=0;
  char z1[MAXZ], z2[MAXZ];
  TLista actL;
  SubListaP antSL, actSL;
  printf("Codigo de paquete a eliminar: ");
  scanf("%d",&codPaq);
  printf("Zona 1: ");
  scanf("%s",z1);
  printf("Zona 2: ");
  scanf("%s",z2);

  if( LD != NULL)
    actL = LD;
  while( actL != NULL && paq_encontrado == 0 && contZona < 2){ //Recorro la lista de docks para encontrar la zona
    if( strcmp(z1,actL->zona) == 0 || strcmp(z2,actL->zona) == 0){ //Encuentro paquete en la zona 1 o 2
      antSL = NULL;  //Inicializo para posible eliminacion
      actSL = actL->SL;
      while( actSL != NULL && codPaq != actSL->cod_paq ){ //Busco si el paquete se encuentra en la zona
        antSL = actSL;
        actSL = actSL->sig;
      }
      if( actSL != NULL ){ //Localizo el paquete
        paq_encontrado = 1;
        elimSL = actSL;
        if( antSL = NULL )  //Caso cabeza
          actL->SL = actL->SL->sig;
        else //Caso cuerpo/cola
          antSL->sig = actSL->sig;
        actSL = actSL->sig;
        free(elimSL); //Elimino paquete
      }else{
        actL = actL->sig; //Si no esta el paquete sigo buscando
        contZona++; // Si paso por las dos zonas y no se encontro se corta el ciclo
      }
    }else
      actL = actL->sig;
  }
}

void EliminaPaquete(TLista LD){

  int codPaq, cont_paq=0;
  char z1[MAXZ], z2[MAXZ];
  float pesoTot=0;
  TLista actL;
  SubListaP antSL, actSL;
  printf("Codigo de paquete a eliminar: ");
  scanf("%d",codPaq);
  printf("Zona 1: ");
  scanf("%s",z1);
  printf("Zona 2: ");
  scanf("%s",z2);

  if( LD != NULL )
    actL = LD;
  while( actL != NULL && (strcmp(z1,actL->zona) != 0 && strcmp(z2,actL->zona) != 0){ //Recorro la lista de docks para encontrar la zona
    actL = actL->sig;
  }
  if( actL != NULL ){
    antSL = NULL;  //Inicializo para posible eliminacion
    actSL = actL->SL;
    while( actSL != NULL && codPaq != actSL->cod_paq ){ //Busco si el paquete se encuentra en la zona
      antSL = actSL;
      actSL = actSL->sig;
    }
    if( actSL != NULL ){ //Localizo el paquete
      elimSL = actSL;
      if( antSL = NULL )  //Caso cabeza
        actL->SL = actL->SL->sig;
      else //Caso cuerpo/cola
        antSL->sig = actSL->sig;
      actSL = actSL->sig;
      free(elimSL); //Elimino paquete
    }
    actSL = actL->SL;
    while( actSL != NULL ){
      cont_paq++;
      pesoTotal += actSL->peso;
      actSL = actSL->sig;
    }
    if(cont)
      printf("Peso promedio de paquetes: %f",(float)pesoTotal/cont_paq);
  }
}
