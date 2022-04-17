#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CONSTANTES
#define MAXL 5
#define MAXF 4
#define MAXM 4

///ESTRUCTURAS

typedef struct Materia{
  char codigo[MAXM];
  int intentos;
  int anio;
  float prom;
}Materia;

typedef Materia TElementoP;

typedef struct Nodo{
  char legajo[MAXL];
  char facultad[MAXF];
  TPila materias;
  struct Nodo *ant,*sig;
}Nodo;

typedef struct Nodo* pNodo;

typedef struct TListaD{
  pNodo pri,ult;
}TListaD;

///PROTOTIPOS

void regAprobado(TListaD *LD);

void MasMaterias(TListaD *LD, char Max1[],char Max2[]);

int main(){

  TListaD LD;

  regAprobado(&LD);

  MasMaterias(&LD,Max1,Max2);

  return 0;
}

///FUNCIONES

void regAprobado(TListaD *LD){

  char legajo[MAXL];
  char facultad[MAXF];
  char codigo[MAXM];
  pNodo actA;
  TPila paux;
  Materia mat;

  //Solicito al usuario la informacion para registrar la aprobacion
  gets(legajo);
  gets(facultad);
  gets(codigo);

  if( *LD.pri != NULL )
    actA = *LD.pri;
  while( actA != NULL && strcmp(legajo,actA->legajo) != 0 && strcmp(facultad,actA->facultad) != 0){ //Busco alumno
    actA = actA->sig;
  }
  if( actA != NULL ){//El alumno fue encontrado
    iniciaP(&paux);
    while(!VaciaP(actA->materias) && strcmp( mat.codigo,codigo) != 0){ //Saco de la pila hasta encontrar la materia o hasta que la misma quede vacia
      sacaP(&actA->materias,&mat);           //Saco de la pila
      if( strcmp( mat.codigo,codigo) != 0 ){ // Si no es la materia buscada
        poneP(&paux,mat);                    //Almaceno en pila auxiliar
      }else{
        while(!VaciaP(paux)){                //Si es la materia buscada devuelvo las materias en su orden a la pila original
          sacaP(&paux,&mat);
          poneP(&actA->materias,mat);
        }
      }
      if( vaciaP(actA->materias)){ //Si el alumno se quedo sin materia pendientes se lo elimina de la lista alumnos
        if( *LD->pri == *LD->ult ){
          *LD.pri = NULL;
          *LD.ult = NULL;
        }
        if( actA == *LD.pri ){
          *LD.pri = *LD.pri->sig;
          *LD.pri->ant = NULL;
        }else{
          if( actA == *LD.ult ){
            *LD.ult = *LD.ult->ant;
            *LD.ult->sig = NULL;
          }else{
            actA->ant->sig = actA->sig;
            actA->sig->ant = actA->ant;
          }
        }
        free(actA);
      }
    }
  }
}

void MasMaterias(TListaD *LD, char MaxLeg1[],char MaxLeg2[]){

  int Max1=0; Max2=0;
  pNodo aux;
  TPila Paux;
  TElementoP info;

  if( aux == NULL)
    aux = aux.pri;
  while( aux != NULL ){
    while( !VaciaP(aux->materias) ){
      SacaP(&aux->materias,&info);

    }

  }



}




