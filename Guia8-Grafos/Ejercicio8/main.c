#include <stdio.h>
#include <stdlib.h>

#define N 6 //Grafo compuesto de 6 vertices

//PROTOTIPOS

void MuestraMAdy(int MAdy[][N]);

void Grado(int MAdy[][N],int arrGrado[],int i,int j);

void GradoGrafo(int MAdy[][N],int arrGrado[],int i,int j);

int MayorGrEntrada(int MAdy[][N],int i,int j,int maxG,int contG);

//FUNCION PRINCIPAL

int main(){

  int MAdy[N][N]=
  {{1,1,0,0,0,0},
   {0,0,1,0,0,0},  //Creo matriz de adyacencia
   {0,0,0,0,1,0},
   {0,0,1,0,0,0},
   {0,1,0,1,0,1},
   {0,0,0,0,0,0}};

  int arrGrado[N]; //Arreglo grados digrafo
  int arrGrGrafo[N]; //Arreglo grados grafo
  int i,j;

  Grado(MAdy,arrGrado,0,0);//Guardo en arreglo grados de los vertices de un digrafo. (M.Ady)

  GradoGrafo(MAdy,arrGrGrafo,0,0);//Guardo en arreglo grados de los vertices de un grafo. (M.Ady)

  MuestraMAdy(MAdy);

  for(i=0;i<N;i++){ //Muestra Grado de un digrafo
    printf("[%d] ",arrGrado[i]);
  }
  printf("\n\n");
  for(i=0;i<N;i++){ //Muestra Grado de un digrafo
    printf("[%d] ",arrGrGrafo[i]);
  }

  printf("\n\nMayor grado de entrada del digrafo: %d\n",MayorGrEntrada(MAdy,0,0,0,0));

  return 0;
}

//FUNCIONES

/*
a) generar recursivamente un arreglo con el grado de cada
vértice de un grafo almacenado en una matriz
de adyacencia.
*/

void MuestraMAdy(int MAdy[][N]){

  int i,j;

  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      printf("%d ",MAdy[i][j]);
    printf("\n");
  }
  printf("\n");
}

void Grado(int MAdy[][N],int arrGrado[],int i,int j){

  if( i < N ){
    arrGrado[i]=0; //Inicializo arreglo
    if( j < N ){
      Grado(MAdy,arrGrado,i,j+1);
      if( MAdy[i][j] ) //Cuento en fila
        arrGrado[i]++;
      if( MAdy[j][i] ) //Cuento en col
        arrGrado[i]++;
    }else{
      Grado(MAdy,arrGrado,i+1,0);
      if( MAdy[i][i] ) //Resto en bucle
        arrGrado[i]--;
    }
  }
}

//! a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de adyacencia

void GradoGrafo(int MAdy[][N],int arrGrGrafo[],int i,int j){

  if( i<N ){
    arrGrGrafo[i]=0;
    if( j<N ){
      GradoGrafo(MAdy,arrGrGrafo,i,j+1);
      if( MAdy[i][j] )
        arrGrGrafo[i]++;
    }else
      GradoGrafo(MAdy,arrGrGrafo,i+1,0);
  }
}

//! b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz de adyacencia.

int MayorGrEntrada(int MAdy[][N],int i,int j,int maxG,int contG){

  if( j<N ){
    if( i<N ){
      if( MAdy[i][j] )
        contG++;
      MayorGrEntrada(MAdy,i+1,j,maxG,contG);
    }else{
      if( contG > maxG )
        maxG = contG;
      MayorGrEntrada(MAdy,0,j+1,maxG,0);
    }
  }else
    return maxG;
}

//! b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de adyacencia.

int MayorGrEntrada(int MAdy[][N],int i,int j,int maxG,int contG){


}
