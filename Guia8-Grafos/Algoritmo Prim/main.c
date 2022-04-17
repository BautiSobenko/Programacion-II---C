#include <stdio.h>
#include <stdlib.h>
#define N 6

void prim(int MAdy[][N],int vi,int E[][2],int *suma);

int main(){

  int MAdy[N][N]=
  {{0,5,4,0,0,0},
   {5,0,6,2,0,0},  //Creo matriz de adyacencia
   {4,6,0,2,0,0},
   {0,2,2,0,4,3},
   {0,0,0,4,0,1},
   {0,0,0,3,1,0}};

   int E[N-1][2]; //Conjunto E de aristas que conforman el aem(arbol de exp. minimo)
   int suma=0;
   int i;

   prim(MAdy,2,E,&suma); //Paso vertice de partida

   for(i=0;i<N-1;i++)
     printf("[%d , %d] - ",E[i][0],E[i][1]);
   printf("\n\nCosto total del aem: %d\n\n",suma);

  return 0;
}

void prim(int mat[][N],int vi,int E[][2],int *suma){

  int cc[N], i,j,k;
  int e[2], contE=0;
  int min, aggV;

  for(i=0;i<N;i++)
    cc[i]=0;

  cc[vi-1] = 1; //Se agrega el vertice inicial al aem

  for(i=0;i<N-1;i++){ //Se ponen N-1 aristas en el aem
    min = 999;
    for(j=0;j<N;j++) //Analizo los vertices adyacentes a cada vertice perteneciente al aem, que tenga 1 en el vector
      if(cc[j] == 1) //Si j es un vertice en el aem
        for(k=0;k<N;k++) //se agrega la arista de peso mínimo con un vértice en el aem y un vértice que no esté en el aem
          if(cc[k]==0 && mat[j][k]>0 && mat[j][k]<min){
            min = mat[j][k];
            aggV = k;
            e[0] = j; //Guardo la arista
            e[1] = k;
          }
    //Pongo vertice
    cc[aggV] = 1;
    //Pongo arista minima j,k
    E[contE][0] = e[0];
    E[contE][1] = e[1];
    contE++;
    *suma += mat[e[0]][e[1]];
  }
}

