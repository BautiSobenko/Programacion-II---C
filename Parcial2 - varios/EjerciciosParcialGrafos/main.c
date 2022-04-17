#include <stdio.h>
#include <stdlib.h>

#define N 6

int main(){

  int cont=0;
  int Mady[N][N];

  CargaMAdy(Mady,N);

  Porc(MAdy,N-1,N-1,N-1,0,0,&cont);

  if(cont)
    printf("El porcentaje es: %f %",(float)(N/cont)*100);
//Podria haber devuelto el porcentaje dentro de la funcion

  return 0;
}

/*
Dado un digrafo de N vertices con aristas ponderadas
almacenado en una matriz de adyacencia, hallar el
porcentaje de vertices que teniendo bucle
poseen el grado max de salida.
*/

//Grado de salida -> 1's en fila

void Porc(int MAdy[][N],int i,int j,int jAux,int grMax,int gr,int *cont){

  if( i >= 0 ){
    if( MAdy[i][i] == 0 )//No tiene bucle
      Porc(MAdy,i-1,j,jAux,grMax,0,cont);
    else{ //Tiene bucle
      if( j >= 0 ){
        if( MAdy[i][j] )
          gr++;
        Porc(MAdy,i,j-1,jAux,grMax,cont);
      }else{ //Me caigo de la matriz
        if( gr > grMax ){
          grMax = gr;
          *cont = 0;
        }
        if( gr == grMax )
          (*cont)++;
        Porc(MAdy,i-1,jAux,jAux,grMax,0,cont);
      }
    }
  }//Si quiero devolver algo, este seria el lugar
}

/*
Dado un digrado con N aristas ponderadas , almacenado
en una lista de adyacencia determinar cual es el
vertice que, conteniendo bucle tiene el mayor costo
promedio de las aristas que llegan a el desde otros
vertices
*/

typedef struct Nodo{
  int vertice;
  int peso;
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

typedef struct LAdy{
  int vertice;
  int peso;
  TLista head;
}LAdy;

typedef struct reg{
  int peso;
  int cont;
}reg;

int main(){

  LAdy Lista[N];
  reg ArrProm[N];


  return 0;
}

void Prom(LAdy Lista[],reg ArrProm[],float *maxCosto){

  TLista aux;
  int tieneBucle[N];
  float prom;

  for(i=0;i<N;i++){
    aux = Lista.head;
    //Me fijo si tiene bucle
    while( aux != NULL && (aux->vertice)-1 != i){
      aux = aux->sig;
    }
    if( aux ){ //Tiene bucle
      aux = Lista.head;
      tieneBucle[i]=1;
      //Opero con los grados de salida
      while( aux != NULL ){
        ArrProm[(aux->vertice)-1].peso += aux->peso;
        ArrProm[(aux->vertice)-1].cont++;
        aux = aux->sig;
      }
    }else
      tieneBucle[i]=0;
  }
  for(i=0;i<N;i++){
    if( tieneBucle[i] ){
      prom = (float)ArrProm[i].peso/ArrProm[i].cont
      if( prom  > *maxCosto )
        *maxCosto = prom;
    }
  }
}
