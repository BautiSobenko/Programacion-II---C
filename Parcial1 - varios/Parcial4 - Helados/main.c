#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntCola.h"

#define MAXsabor 20

typedef struct Nodo2{
  char sabor[MAXsabor];
  char fechaProd[8];
  int fila,col;
  struct Nodo* sig;
}Nodo2;

typedef struct Nodo2* TListaB;

typedef struct Nodo{
  char sabor[MAXsabor];
  float gramos;
  int fila,col;
  TCola baldes;
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

typedef struct THeladera{
  char sabor[MAXsabor];
  float gramos;
}THeladera;

void CargaLista(TLista *L);

void ProcesoSemanal(TLista *L,THeladera *M,TListaB *LB);

void GeneraEstadistiva(THeladera *M);

void InicializaMatriz(THeladera *M);

int main(){

  TLista L;
  TListaB LB;
  THeladera M[20][20];
  CargaLista(&L);
  ProcesoSemanal(L,M,&LB);
  GeneraEstadistica(M);


  return 0;
}

void CargaLista(TLista *L){

  TLista nuevoL,actL,antL;
  int cant_baldes;

  FILE* arch = fopen("HELADERA.TXT","rt"); //Abrimos archivo para su lectura
  while(!feof(arch)){
    nuevoL = (TLista)malloc(sizeof(Nodo)); //Creamos el nodo
    fscanf(arch,"%s %f %d %d %d",nuevoL->sabor,&nuevoL->gramos,&nuevoL->fila,&nuevoL->col,&cant_baldes);
    actL = *L;
    antL = NULL;
    ///Comenzamos la insercion ordenada (ascendente)
    while( actL != NULL && strcmp(nuevoL->sabor,actL->sabor)>0 ){
      antL = actL;
      actL = actL->sig;
    }
    if( actL == *L ){ //Caso cabeza
      nuevoL->sig = *L;
      *L = nuevoL;
    }else{           //Caso cuerpo/cola
      antL->sig = nuevoL;
      nuevoL->sig = actL;
    }
  }
}

void ProcesoSemanal(TLista L,THeladera *M,TListaB *LB){

  TLista actL;
  char fechaVenc[MAXF];
  TCola baldes_aux;
  char fechaProd[MAXF];
  TListaB actLB,antLB,nuevoB;

  InicializaMatriz(M);
  gets(fechaVenc); //Obtengo la fecha parametro
  if( L != NULL )
    actL = L;
  IniciaC(&baldes_aux);
  while( actL != NULL ){
     M[actL->fila-1][actL->col-1].gramos = actL->gramos;  ///Guardo en matriz (heladera) (No guardo los baldes del deposito)
     strcpy(M[actL->fila-1][actL->col-1].sabor,actL->sabor);
    while( !VaciaC(actL) ){
      QuitarC(&actL->baldes,fechaProd); ///Saco balde
      if( strcmp(fechaProd,fechaVenc)<0 ){/// Si no vencio
        AgregaC(&baldes_aux,fechaProd); ///Coloco en cola auxiliar, para luego volver a meterlo manteniendo el orden en la cola(deposito)
      }else{ ///Si vencio lo borro de la cola
        actLB = *LB;
        nuevoB = (TListaB)malloc(sizeof(Nodo2)); ///Inserto en lista auxiliar de baldes vencidos
        nuevoB->col = actL->col;
        nuevoB->fila = actL->fila;
        strcpy(nuevoB->fechaProd,fechaProd);
        strcpy(nuevoB->sabor,actL->sabor);
        while( actLB != NULL && strcmp(actL->sabor,actLB->sabor)>0 ){ ///Recorrido necesario para insercion ordenada
          antLB = actLB;
          actLB = actLB->sig;
        }
        if( actLB == *LB ){
          nuevoB->sig = *LB;
          *LB = nuevoB;
        }else{
          antLB->sig = nuevoB;
          nuevoB->sig = actLB;
        }
      }
    }
    while( !VaciaC(baldes_aux)){ ///Vuelvo a colocar los baldes en la cola
      QuitarC(&baldes_aux,fechaProd);
      AgregaC(&actL->baldes,fechaProd);
    }
    actL = actL->sig; ///Avanzo al proximo sabor de la lista
  }
}

void InicializaMatriz(THeladera *M){

  int i,j;
  for(i=0; i<20; i++)
  for (j=0; j<20; j++){
    M[i][j].gramos = 0;
    M[i][j].sabor ='';
  }
}

  for(i=0; i<20; i++){
    for(j=0; i<20; j++){

  }
}

void GeneraEstadistica(THeladera *M){

  N = NMax(M);
  M = MMax(M);
  for()


}

int NMax(THeladera *M){

  int i,j,MaxF=0;
  for(i=0; i<20; i++)
    for(j=0; j<20; j++){
      if(M[i][j].gramos != 0){
        if( i > MaxF)
          MaxF = i;
      }
    }
  return MaxF;
}

int MMax(THeladera *M){

  int i,j,MaxC=0;
  for(i=0; i<20; i++)
    for(j=0; j<20; j++){
      if(M[j][i].gramos != 0){
        if( j > MaxC)
          MaxC = j;
      }
    }
  return MaxC;
}



