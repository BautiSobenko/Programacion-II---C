#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntPila.h"

typedef struct NoditoPaq{
  int codPaq;
  float peso;
  char destinatario[20];
  struct NoditoPaq* sig;
}NoditoPaq;

typedef NoditoPaq* SubListaP; //Sublista paquetes

typedef struct NodoDock{
  char idDock[5];
  char nombreZona[2];
  float pesoMax;
  SubListaP SLP;
  struct NodoDock* sig;
}NodoDock;

typedef NodoDock* TListaD;

///PROTOTIPOS

void ActualizaLista(TListaD LD,TPila *PP);

void Elimina(TListaD LD);

int main(){

  TListaD LD; //Lista docks
  TPila PP;   //Pila paquetes

  ActualizaLista(LD,&PP);
  Elimina(LD);

  return 0;
}

void ActualizaLista(TListaD LD,TPila *PP){

  TPila Paux;
  TelementoP paq;
  TListaD actLD;
  SubListaP antSLP,actSLP,nuevoP;
  int codPaq;
  printf("Ingrese codigo de paquete\n");
  scanf("%d",codPaq);

  if( !Vacia(*PP) )
    IniciaP(&Paux);
  while(!Vacia(*PP)){
    Desapila(PP,&paq);
    if( paq.codPaq == codPaq ){ //Encuentro paquete
      actLD = LD;
      while( actLD != NULL && (strcmp(paq.nombreZona,actLD->nombreZona) != 0 || paq.peso > actLD->pesoMax )){
        actLD = actLD->sig;
      } //Recorro la lista hasta encontrar algun dock que cumpla para el paquete localizado ambas condiciones.
    if( actLD != NULL ){ //Encuentro un dock que cumpla con las condiciones
      //Insercion al final de sublista paquetes
      antSLP = NULL;
      actSLP = actLD->SLP;
      while( actSLP != NULL ){
        antSLP = actSLP;
        actSLP = actSLP->sig;
      }
      nuevoP = (SubListaP)malloc(sizeof(NoditoPaq));
      nuevoP->peso = paq.peso;
      strcpy(nuevoP->destinatario,paq.destinatario);
      nuevoP->codPaq = paq.codPaq;
      if( antSLP == NULL )//Caso lista vacia
        actLD->SLP = nuevoP;
      else //Caso cola
        antSLP->sig = nuevoP;
      nuevoP->sig = actSLP;
    }else //El paquete es el que deseo localizar, pero no hay ningun dock que cumpla las condiciones
      Apila(&Paux,paq);
  }else //El paquete no es el que deseo localizar
    Apila(&Paux,paq);
  }
  while(!VaciaP(Paux)){ //Devuelvo elementos a la pila original en el mismo orden
    Desapila(&Paux,&paq);
    Apila(PP,paq);
  }
}

void Elimina(TListaD LD){

  int codPaq, esta=0,noEsta=0 noEstaZ1=0,noEstaZ2, contPaq=0;
  float sumaPeso=0;
  char z1[2], z2[2];
  TListaD actLD; //Recorro la lista unicamente
  SubListaP antSLP, actSLP, elimSLP; //Eliminacion en sublista

  scanf("%s",z1); scanf("%s",z2); scanf("%d",&codPaq);

  if( LD != NULL )
    actLD = LD;
  while( actLD != NULL && esta == 0 && noEsta == 0){
    if( strcmp(actLD->nombreZona,z1)== 0 || strcmp(actLD->nombreZona,z2)== 0){
      antSLP = NULL;
      actSLP = actLD->SLP;
      while( actSLP != NULL && actSLP->codPaq != codPaq ){
        antSLP = actSLP;
        actSLP = actSLP->sig;
      }//Sigo recorriendo la sublista mientras no encuentre el paquete
      if( actSLP != NULL ){ //Encuentro el paquete --> lo elimino
        esta = 1;
        elimSLP = actSLP;
        if( antSLP == NULL ) //Caso cabeza
          actLD->SLP = actLD->SLP->sig;
        else //Caso cuerpo/cola
          antSLP->sig = actSLP->sig;
        actSLP = actSLP->sig;
        free(elimSLP);
      }else
        if( strcmp(actLD->nombreZona,z1)== 0 ) //Paquete no esta en z1
          noEstaZ1 = 1;
        else //Paquete no esta en z2
          noEstaZ2 = 1;
      if( noEstaZ1 == 1 && noEstaZ2 == 1) //Si no esta en ninguno de los dos, dejo de buscar
        noEsta = 1;
    }else
      actLD = actLD->sig;
  }
  if(esta){
    actSLP = actLD->SLP;
    while( actSLP != NULL){
      contPaq++;
      sumaPeso += actSLP->peso;
      actSLP = actSLP->sig;
    }
  }
}


///Rehago inciso 1

void ActualizaLista(TListaD LD,TPila *PP){

  TPila Paux;
  TelementoP paq;
  TListaD actLD;
  SubListaP antSLP,actSLP,nuevoP;
  int codPaq;
  printf("Ingrese codigo de paquete\n");
  scanf("%d",codPaq);

  if( !Vacia(*PP) )
    IniciaP(&Paux);
  while(!Vacia(*PP)){
    Desapila(PP,&paq);
    if( paq.codPaq == codPaq ){ //Encuentro paquete
      actLD = LD;
      while( actLD != NULL && (strcmp(paq.nombreZona,actLD->nombreZona) != 0 )){
        actLD = actLD->sig;
      } //Recorro la lista hasta encontrar algun dock que coincidan zonas con el paq
    if( actLD != NULL ){ //Encuentro un dock que cumpla con las condiciones
      pesoTotPaq=0;
      actSLP = actLD->SLP;
      while( actSLP != NULL ){
        pesoTotPaq+=0;
        antSLP = actSLP;
        actSLP = actSLP->sig;
      }
      if( pesoTotPaq + paq.peso < actLD->pesoMax ){
        nuevoP = (SubListaP)malloc(sizeof(NoditoPaq));
        nuevoP->peso = paq.peso;
        strcpy(nuevoP->destinatario,paq.destinatario);
        nuevoP->codPaq = paq.codPaq;
        if( antSLP == NULL )//Caso lista vacia
          actLD->SLP = nuevoP;
        else //Caso cola
          antSLP->sig = nuevoP;
        nuevoP->sig = actSLP;
      }
    }else //El paquete es el que deseo localizar, pero no hay ningun dock que cumpla las condiciones
      Apila(&Paux,paq);
  }else //El paquete no es el que deseo localizar
    Apila(&Paux,paq);
  }
  while(!VaciaP(Paux)){ //Devuelvo elementos a la pila original en el mismo orden
    Desapila(&Paux,&paq);
    Apila(PP,paq);
  }
}












