#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterfazCola.h"

typedef struct TAuto{
  char patente[7];
  unsigned int modelo;
}TAuto;

typedef TAuto TelementoC;

typedef struct NodoPuesto{
  char codigo[4];
  char disponible;
  unsigned int cantAtendidos;
  TCola pend;
  struct NodoPuesto* sig;
}NodoPuesto;

typedef struct NodoPuesto* TListaP;

typedef struct NodoVerif{
  char patente[7];
  unsigned int modelo;
  unsigned int puestoAtencion;
  char estadoVerif;
  struct nodoVerif* sig;
}NodoVerif;

typedef struct NodoVerif* TListaV;

///PROTOTIPOS

void Atencion(TListaP Lp,TListaV Lv);

void Elimina(TListaV *Lv);

int main(){

  TListaP Lp; //Lista -> puestos de atencion
  TListaV Lv; //Lista -> Vehiculos verificados
  Atencion(Lp,Lp)
  Elimina(&Lv);

  return 0;
}

void Atencion(TListaP Lp,TListaV Lv){

  char codPuesto[4];
  unsigned int modelo;
  int cantAtendidos=0;
  TListaP actP; //Variable utilizada para recorrido
  TCola vehic_aux;
  TelementoC vehic;
  TListaV actV,nuevoV; //Variables utilizadas para insercion al final de lista
  scanf("%s",codPuesto); scanf("%d",&modelo);

  actP = Lp;
  while( actP != NULL && (strcmp(codPuesto,actP->codigo)>0 || actP->disponible = 'N')){ //Busco el codigo de puesto
    actP = actP->sig;
  }
  if( actP != NULL ){ //Encuentro puesto con estado disponible.
    IniciaC(&vehic_aux);
    while( !VaciaC(actP->pend) ){
      SacaC(&actP->pend,&vehic);
      if( vehic.modelo == modelo ){ //Modelo buscado -> inserto al final de la lista
        cantAtendidos++;
        actV = Lv;
      while( actV->sig != NULL ){ //Insercion al final de la lista
        actV = actV->sig;
      }
      nuevoV = (TListaV)malloc(sizeof(NodoVerif));
      nuevoV->modelo = vehic.patente;
      strcpy(nuevoV->patente,vehic.patente);
      nuevoV->estadoVerif = 'P';
      nuevoV->sig = NULL;
      if( actV == Lv ) //Caso lista vacia
        Lv = nuevoV;
      else
        actV->sig = nuevoV;
      }else{
      PoneC(&vehic_aux,vehic); //Modelo no buscado -> almaceno temporalmente en cola aux
      }
    }
    while( !VaciaC(vehic_aux) ){ //Devuelvo los vehiculos de distinto modelo a la cola original
      SacaC(&vehic_aux,&vehic);
      PoneC(&actP->disponible,vehic);
    }
    if(cantAtendidos)
      printf("La cantidad de atendidos es: %d",cantAtendidos);
    else
      printf("No se encontraron autos del modelo buscado, 0 atendidos");
  }else //No se encontro el puesto
    printf("Puesto ingresado erroneo");
}

void Elimina(TLista *Lv){

 int K, contVTV_desap=0;
 TListaV antV,actV,elimV; //Utilizo las variables para la eliminacion


 scanf("%d",&K); //K primero con VTV desaprobada

 if( *Lv != NULL ){
   actV = *Lv;
   antV = NULL;
 }
 while( contVTV_desap != K ){ //Se que no voy a salir de la lista sin encontrar los K autos con VTV desaprobados
   if( actV->estadoVerif = 'D' ){ //Si la VTV esta desaprobada elimino de la lista
     contVTV_desap++;
     elimV = actV;
     printf("Patente: %s\n",actV->patente);
     printf("Puesto de atencion %d",actV->puestoAtencion);
     actV = actV->sig;
     if( antV == NULL ){ //Cabecera
       *Lv = *Lv->sig;
     }else
        antV->sig = actV;
     free(elimV);
     }else{
       antV = actV;
       actV = actV->sig;
     }
   }
 }





