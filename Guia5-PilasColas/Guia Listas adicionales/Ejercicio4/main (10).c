#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CONSTANTES

#define MAXDOC 9 // Docuemento
#define MAXF 13  // 27/09/2002 Fecha de salida
#define MAXH 6   // 00:30 Horario de salida
#define MAXD 20  //Nombre del destino

///ESTRUCTURA DE LISTAS

typedef struct NoditoP{
    char doc[MAXDOC];
    struct NoditoP* sig;
}NoditoP;

typedef struct NoditoP* SubListaP; //Sublista de pasajes

typedef struct NoditoV{
    int codigo;
    char fecha[MAXF];
    char hora[MAXH];
    int vendidos;
    int capMax;
    struct NoditoV* sig;
    SubListaP SLP; //Sublista pasajes
}NoditoV;

typedef struct NoditoV* SubListaV; //Sublista de vuelos

typedef struct NodoD{
    char destino[MAXD];
    struct NodoD* sig;
    SubListaV SLV;
}NodoD;

typedef struct NodoD* TListaD;

///PROTOTIPOS

void Reserva(TListaD LD,char dest[],char doc[],int codVuelo);

void Cancelacion(TListaD LD,char dest[],char doc[],int codVuelo);

void AgregarDestino(TListaD *LD,char dest[]);

void AgregarVuelos(TListaD LD,char dest[],char fecha[],char hora[],int capMax,int codVuelo);

void Listar(TListaD LD,char dest[]);

///FUNCION PRINCIPAL

int main(){

    TListaD LD;
    char dest[MAXD];
    char doc[MAXDOC];
    char fecha[MAXF];
    char hora[MAXH];
    int capMax;
    int codVuelo;
    //Todos los valores anterior seran ingresados por el usuario.

    Reserva(LD,dest,doc,codVuelo);
    Cancelacion(LD,dest,doc,codVuelo);
    AgregarDestino(&LD,dest);
    AgregarVuelos(LD,dest,fecha,hora,capMax,codVuelo);
    Listar(LD,dest);

    return 0;
}

///FUNCIONES

void Reserva(TListaD LD,char dest[],char doc[],int codVuelo){

    TListaD actD = LD;
    SubListaV actV;
    SubListaP actP,nuevoP;

    while( actD != NULL && strcmp(dest,actD->destino)!=0 ){ //Busco destino en lista de destinos
      actD = actD->sig;
    }
    if( actD != NULL) { //Lo encuentro
      actV = actD->SLV; //Me paro en la cabeza de la sublista vuelos en el nodo donde se encontro el destino
      while( actV != NULL && codVuelo > actV->codigo ){ //Busqueda en sublista de vuelos ordenada ascendentemente
        actV = actV->sig;
      }
      if( codVuelo == actV->codigo && actV->vendidos+1 <= actV->capMax ){ //Encuentro codigo igual
        actP = actV->SLP; //Me paro en la cabeza de la sublista de pasajeros en el nodo donde se encontro el vuelo
        actV->vendidos++;
        nuevoP = (SubListaP)malloc(sizeof(NoditoP));
        strcpy(nuevoP->doc,doc);
        nuevoP->sig = actV->SLP;
        actV->SLP = nuevoP;
      }
    }
}

void Cancelacion(TListaD LD,char dest[],char doc[],int codVuelo){

        TListaD actD = LD;
        SubListaV actV;
        SubListaP antP,actP;

        while( actD != NULL && strcmp(dest,actD->destino) != 0 ){//Busco el destino
          actD = actD->sig;
        }
        if( actD != NULL ){ //Encuentro el destino
          actV = actD->SLV;
          while( actV != NULL && codVuelo > actV->codigo ){ //Busco el vuelo
            actV = actV->sig;
          }
          if( actV != NULL){//Encuentro el vuelo
            antP = NULL;
            actP = actV->SLP;
            while( actP != NULL && strcmp(doc,actP->doc) != 0){ //Busco el documento del pasajero
              antP = actP;
              actP = actP->sig;
            }
            if( actP != NULL ){ //Encuentro el pasajero
              if( actP == actV->SLP )
                actV->SLP = actV->SLP->sig; //Muevo la cabeza de la sublista
              else
                antP->sig = actP->sig; //Enlazo si no estoy en la cabeza
              free(actP);       //Elimino pasajero
              actV->vendidos--; //Decremento cantidad de reservas
            }
          }
        }
}

void AgregarDestino(TListaD *LD,char dest[]){

    TListaD actD,nuevoD;
    actD = *LD;

    //Ingreso siempre por cabeza ya que la lista destinos no esta ordenada.


    while( actD != NULL && strcmp(dest,actD->destino) != 0 ){
      actD = actD->sig;
    }
    //Insercion por cabeza, ya que la lista no se encuentra ordenada.
    if( actD == NULL ){ //El destino no esta en la lista, o la lista esta vacia
      nuevoD = (TListaD)malloc(sizeof(NodoD));
      strcpy(nuevoD->destino,dest);
      nuevoD->sig = *LD;
      *LD = nuevoD;
    }
}

void AgregarVuelos(TListaD LD,char dest[],char fecha[],char hora[],int capMax,int codVuelo){

    TListaD actD = LD;
    SubListaV antV,actV,nuevoV;

    while( actD != NULL && strcmp(dest,actD->destino) != 0 ){ //Busco destino
      actD = actD->sig;
    }
    if( actD != NULL ){ //Encontre el destino
      antV = NULL;
      actV = actD->SLV;
      if( actV == NULL || codVuelo < actV->codigo){ //Si no hay vuelos o el vuelo a agregar es menor que el primero
        nuevoV = (SubListaV)malloc(sizeof(NoditoV));//Insercion, caso: cabeza
        strcpy(nuevoV->fecha,fecha);
        strcpy(nuevoV->hora,hora);
        nuevoV->capMax = capMax;
        nuevoV->vendidos = 0;
        nuevoV->codigo = codVuelo;
        nuevoV->sig = actV;
        actD->SLV = nuevoV;
      }
      while( actV != NULL && codVuelo > actV->codigo ){ //Busco donde debo insertar para mantener la lista ordenada
        antV = actV;
        actV = actV->sig;
      }
      nuevoV = (SubListaV)malloc(sizeof(NoditoV)); //Insercion, caso: cuerpo,cola
      strcpy(nuevoV->fecha,fecha);
      strcpy(nuevoV->hora,hora);
      nuevoV->capMax = capMax;
      nuevoV->vendidos = 0;
      nuevoV->codigo = codVuelo;
      antV->sig = nuevoV;
      nuevoV->sig = actV;
    }
}

void Listar(TListaD LD,char dest[]){

    TListaD actD = LD;
    SubListaV actV;

    while( actD != NULL && strcmp(dest,actD->destino) != 0 ){ //Busco destino
      actD = actD->sig;
    }
    if( actD != NULL ){ //Encontre destino
      actV = actD->SLV;
      if( actV != NULL )
        while( actV != NULL ){ //Informo al usuario todos los vuelos al destino ingresado
          printf(".:Vuelo:. %d\n\n",actV->codigo);
          printf("Cantidad de reservas: %d\n",actV->vendidos);
          printf("Lugares disponibles: %d\n",actV->capMax - actV->vendidos);
          printf("Fecha y hora de salida: %s // %s\n",actV->fecha,actV->hora);
          actV = actV->sig;
        }
      else
        printf("No hay vuelos al destino ingresado\n");
    }
}


