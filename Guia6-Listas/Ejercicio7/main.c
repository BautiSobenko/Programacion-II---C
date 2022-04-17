#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

///Sublista del autor
typedef struct NoditoA{
    char titulo[MAX];
    int edicion;
    struct NoditoA* sig;
}NoditoA;

typedef NoditoA* SubListaA;

///Lista de autores
typedef struct NodoA{
    char nombre[MAX]; //Nombre autor
    SubListaA subA;   //Libros del autor
    struct NodoA* sig;
}NodoA;

typedef NodoA* TListaA;

///Sublista de socios
typedef struct NoditoS{
    char titulo[MAX]; //Nombre del libro prestado
    int edicion;
    struct NoditoS* sig;
}NoditoS;

typedef struct NoditoS* SubListaS;

///Lista de socios
typedef struct NodoS{ //Lista de socios
    char nombre[MAX]; //Nombre socio
    SubListaS subS;   //Libros prestados al socio
    struct NodoS* sig;
}NodoS;

typedef NodoS* TListaS;

///Defino estructura que tendra el arreglo
typedef struct Arreglo{
    char inicial;
    TListaA A;
}Arreglo;


///PROTOTIPOS

void NuevoLibro(Arreglo *LA,char *autor,char *libro,int edicion);

void RegistraPrestamos(Arrego LA[],TListaS *LS,char *autor,char *libro);

int main(){

    Arreglo LA[26]; //Arreglo de listas
    TListaS LS;
    char autor[MAX],libro[MAX]; //Libros a agregar
    int edicion;
    NuevoLibro(LA,autor,libro,edicion);
    RegistrarPrestamos(LA,&LS,autor,libro);

    return 0;
}

void NuevoLibro(Arreglo LA[],char *autor,char *libro,int edicion){

/**Insercion ordenada en sublista*/

    TListaA auxA,nuevoA;
    SubListaA actSA ,antSA, nuevoL;
    nuevoL = (SubListaA)malloc(sizeof(NoditoA)); // Yo se que si o si lo voy a usar, entonces lo creo afuera
    int i=0;

    while( autor[0] != LA[i].inicial ){ //ARREGLO
      i++;
    }
    auxA = LA[i].A; //A es el puntero a la cabeza de la lista de autores
    while( auxA!=NULL && strcmp(autor,auxA->nombre)>0 ){ //LISTA
      auxA = auxA->sig;
    }
    if(auxA!= NULL && strcmp(autor,auxA->nombre)==0){ //Si el autor existe
      actSA = auxA->subA;
      antSA = NULL;
      if(auxA->subA==NULL || strcmp(libro,auxA->subA->titulo)<0){ //Caso cabeza
        nuevoL->edicion = edicion;
        strcpy(nuevoL->titulo,libro);
        nuevoL->sig = auxA->subA;
        auxA->subA = nuevoL;
      }else{                                              //Caso cuerpo o cola
        while (actSA!=NULL && strcmp(libro,actSA->titulo)>0){
          antSA = actSA;
          actSA = actSA->sig;
        }
        nuevoL->edicion = edicion;
        strcpy(nuevoL->titulo,libro);
        antSA->sig = nuevoL;
        nuevoL->sig = actSA;
      }else{ //Si el autor no existe
          nuevoA = (TListaA)malloc(sizeof(NodoA));
          strcpy(nuevoA->nombre,autor);
          nuevoA->sig = auxA;
          LA[i].A = nuevoA;
          strcpy(nuevoL->titulo,libro);
          nuevoL->edicion = edicion;
          nuevoL->sig = LA[i].A;
          LA[i].A->subA = nuevoL;
      }
    }
}

void RegistraPrestamos(Arreglo LA[],TListaS LS,char *autor,char *libro){

/**Mover el nodo de la sublista del autor al final de la sublista
de libros prestados para el socio*/

    TListaA auxA;
    SubListaA actSA, antSA;
    TListaS auxS;

    while( LA[i].inicial != autor[0] ){ //Busco en arreglo hasta encontras la primera letra correspondiente al autor
      i++;
    } //Cuando salgo del while encontre a la incial del autor en la posicion i
    auxA = LA[i].A;  //Accedo a la lista de nombres de autores con dicha inicial
    while( auxA!=NULL && strcmp(autor,auxA->nombre)>0 ){ //Busco en la lista el nombre del autor
      auxA = auxA->sig;
    }
    if(auxA != NULL && strcmp(autor,auxA->nombre)==0){  //Si lo encuentro
      actSA = auxA->subA;  //Uso estos auxiliares ya que voy a proceder a eliminar un elemento(libro) de la sublista
      antSA = NULL;
      while( actSA!=NULL && strcmp(libro,actSA->titulo)>0 ){ //Busco en la sublista el titulo del libro
        antSA = actSA;
        actSA = actSA->sig;
      }
      if(actSA!= NULL && strcmp(libro,actSA->titulo)==0){ //Me fijo si la sublista esta vacia, si no lo esta, me fijo si encontre el libro
        InsertaOrdenado(LS,actSA->edicion);
        if(actSA == auxA->subA) //Si estoy en la cabeza
          auxA->subA = auxA->subA->sig //Corro la cabeza
        else
          antSA->sig = actSA->sig;    //Enlazo
        free(actSA);
      }
    }
}

void InsertaOrdenado(TListaS LS,int edicion){

        TListaS auxS = LS;
        SubListaS actSS, antSS, nuevoSS;

        while( auxS!= NULL && strcmp(socio,auxS->nombre)>0 ){ //Busqueda del nombre del socio
            auxS = auxS->sig;
        }
        actSS = auxS->subS; //Uso estos auxiliares ya que voy a proceder a insertar un elemento(libro) en la sublista
        antSS = NULL;
        if(actSS == NULL || strcmp(libro,actSS->titulo)<0){ //Caso de insertar en cabeza
          nuevoSS = (SubListaS)malloc(sizeof(NoditoS));
          nuevoSS->edicion = actSA->edicion;
          strcpy(nuevoSS->titulo,libro);
          nuevoSS->sig = actSS;
          auxS->subS = nuevoSS;
        }else{
          while( actSS!=NULL && strcmp(libro,actSS->titulo)>0){ //Recorro para encontrar donde insertar segun el orden
            antSS = actSS;
            actSS = actSS->sig;
          }
          if(strcmp(libro,actSS->titulo)!=0){   //Caso de insertar en cuerpo o cola
            nuevoSS = (SubListaS)malloc(sizeof(NoditoS));
            nuevoSS->edicion = actSA->edicion;
            strcpy(nuevoSS->titulo,libro);
            antSS->sig = nuevoSS;
            nuevoSS->sig = actSS;
          }
        }
}
