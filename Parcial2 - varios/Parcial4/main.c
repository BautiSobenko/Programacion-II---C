#include <stdio.h>
#include <stdlib.h>

int main(){

  return 0;
}

/*
Dado un arbol binario que proviene de la transformacion
de un arbol general, desarrollar una funcion int que
verifique si en el arbol general existia algun nodo de
grado 2 tal que las claves de sus hijos sean igual
u opuestas
*/

int Verifica(TArbol A){

  TArbol aux;
  int grado=0;

  if( A == NULL )
    return 0;
  else{
    aux = A->izq;
    while( aux != NULL && grado <= 3){
      grado++;
      aux = aux->der;
    }
    if( A->izq != NULL )
      if( grado == 2 && (A->izq == A->izq->der || A->izq == -(A->izq->der)) )
        return 1;
    return Verifica(A->izq) || Verifica(A-der);
  }

}

/*
(Utilizar TDA N-Ario) Dado un árbol N-Ario de claves
reales, obtener la suma de las
claves de los nodos cuyo nivel pertenece al
intervalo cerrado [K1, K2].
*/

float Suma(TArbol A, posicion p, int K1, int K2, int nivel){

  if( nulo(p) || nivel > K2)
    return 0;
  else{
    if( nivel < K1 )
      return Suma(A,HijoMasIzq(p,A),K1,K2,nivel+1) + Suma(A,HermanoDer(p,A),K1,K2,nivel);
    else
      return info(p,A) + Suma(A,HijoMasIzq(p,A),K1,K2,nivel+1) + Suma(A,HermanoDer(p,A),K1,K2,nivel);
  }

}

/*
Dado un Arbol nario de enteros, verificar que exista
algun nodo no hoja con clave K en el nivel K
*/

int Existe(TArbol A, posicion p, int nivel, int K){

  if( nulo(p) || nivel > K)
    return 0;
  else
    if( !nulo(HijoMasIzq(p,A)) && nivel == K && info(p,A) == K )
      return 1;
    else
      return Existe(A,HijoMasIzq(p,A),nivel+1,K) || Existe(A,HermanoDer(p,A),nivel,K);
}

/*
3 - Dado un grafo almacenado en media matriz de adyacencia (triangulo inferior), generar
mediante una función void recursiva, un arreglo con el grado de cada uno de sus
vertices.
* Mostrar la invocación de la solución desarrollada
* La función recursiva no debe contener ciclos
*/

void Grado(int MAdy[][N],int i,int j,int iAux,int jAux, int V[]){

      if(i >= 0){
        if( i > jAux ){ //No llego a la diagonal
          if( MAdy[i][j] )
            V[jAux]++;
          Grado(MAdy,i-1,j,iAux,jAux,V);
        }else{
          if( i == j ) //No analizo la diagonal, voy a dcha.
            Grado(MAdy,i,j-1,iAux,jAux,V);
          else{
            if( j >= 0){ //Me muevo hacia la derecha
              if( MAdy[i][j] )
                V[jAux]++;
              Grado(MAdy,i,j-1,iAux,jAux,V);
            }else //LLego al final de la matriz
              Grado(MAdy,iAux,jAux-1,iAux,jAux-1,V)
          }
        }
      }
}

