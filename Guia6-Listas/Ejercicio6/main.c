#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

///DEFINICION LISTAS

typedef struct Nodito{
    char nombre[MAX];
    int edad;
    char estado;
    struct Nodito* sig;
}Nodito;

typedef struct Nodito* SubLista;

typedef struct Nodo{
    char nombre[MAX];
    int puntos;
    SubLista sub;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TListaE;

///PROTOTIPOS

void IncisoA(TListaE Le,char X);

void SuperaX(TListaE Le,int X);

int TienePuntos(TListaE Le,int P,int E);

void EliminaInactivos(TListaE Le);


int main(){

    TListaE Le;
    char X = 'A'; //Letra inicial de un equipo
    int P = 50;   //Puntos
    int E = 3;    //Numero de equipo

    IncisoA(Le,X);

    SuperaX(Le,P);

    TienePuntos(Le,E,P);

    EliminaInactivos(Le);

    return 0;
}

///FUNCIONES

void ComienzaConX(TListaE Le,char X){

/**Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado*/

    TListaE aux = Le;
    SubLista auxS;
    int CantTotal=0;
    int CantPorClub;
    int MaxClubes=0;
    char NombreClubMax[MAX];

    while(aux != NULL){ //RECORRO LISTA
      CantPorClub = 0;
      auxS = aux->sub;  //ME PARO EN LA CABEZA DE LA SUBLISTA
      while(auxS != NULL){ //RECORRO SUBLISTA
        if(auxS->nombre[0]==X){ //CUMPLE CONDICION
            CantPorClub++;
            printf("%s\n",auxS->nombre)
        }
        auxS = auxS->sig;
      }
      CantTotal += CantPorClub;
      if(CantPorClub > MaxClubes){ //SI MI CANT JUG SUPERA AL MAXIMO
        MaxClubes = CantPorClub;
        strcpy(NombreClubMax,aux->nombre); //GUARDO EL NOMBRE MAXIMO
      }
      aux = aux->sig;
    }
}

void SuperaX(TListaE Le,int X){

/**Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.*/

    TListaE aux = Le;
    SubLista auxS;
    int edadtotal;
    int cantJ;

    while(aux!=NULL){       //Recorrido de lista
        if(aux->puntos >= X){ //Cumplo condicion?
            auxS = aux->sub; //Me paro en la cabeza de la sublista del nodo que cumplio la condicion
            edadTotal = 0;   //Inicializo
            cantJ = 0;
            printf("Equipo: %s\n",aux->nombre);
            while(auxS!=NULL){ //Recorrido de sublista
                edadTotal += auxS->edad;
                cantJ++;
                auxS = auxS->sig;
                printf("%d) %s\n",CantJ,auxS->nombre);  //Lista jugadores
            }
            printf("Edad promedio del equipo: %f\n\n",edadTotal/CantJ);
        }
        aux = aux->sig;
    }
}
int TienePuntos(TListaE Le,int P,int E){

/**Verificar si el equipo E (dato) tiene P (dato) puntos*/

    TListaE aux = Le;
    int PosEquipo = 1;

    while( aux!=NULL && PosEquipo<E ){
        PosEquipo++;
        aux = aux->sig;
    }
    if( aux!=NULL )
        if(aux->puntos == P)
            return 1;
        else
            return 0;
    else
        return 0;
}

void EliminaInactivos(TListaE Le){

/***Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos.*/

    TListaE aux = Le;
    SubLista antS;
    SubLista actS;
    while( aux!=NULL ){ //RECORRO LISTA
        antS = NULL;
        actS = aux->sub;//ME PARO EN LA CABEZA DE LA SUBLISTA
        while( actS!= NULL ){ //RECORRO SUBLISTA
            if( actS->estado = 'S'){ //ESTA INACTIVO?
                elimS = actS;
                if(actS==aux->sub)  //MODIFICO LA CABEZA
                    aux->sub = aux->sub->sig;
                else
                    antS->sig = actS->sig //ENLAZO SALTANDO NODITO
                actS = actS->sigM; //MODIFICO ACT PQ SINO LO PIERDO
                free(elimS);  //ELIMINO NODITO
            }else{
                antS = actS;
                actS = actS->sig;
            }
            aux = aux->sig;
        }
    }
}




