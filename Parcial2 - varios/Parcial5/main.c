#include <stdio.h>
#include <stdlib.h>

int main(){


  return 0;
}

int Suma(TArbol A){

  TArbol aux;
  int suma=0;

  if ( A == NULL )
    return 0;
  else{
    aux = A->izq;
    while( aux != NULL ){
      suma += aux->dato; //Sumo hijos de A
      aux = aux->der;
    }
    return ( A->izq != NULL && A->dato < suma ) + Suma(A->izq) + Suma(A->der)
  }

}

/*
Dado un arbol Nario de enteros, verificar que existe algun
nodo no hoja con clave K en el nivel K
*/

int Verifica(TArbol A, posicion p, int K, int nivel){

  if( nulo(p) )
    return 0;
  else
    if( nivel < K)
      return Verifica(A,HijoMasIzq(p,A),k,nivel+1) || Verifica(A,HermanoDer(p,A),k,nivel);
    else
      return (!nulo(HijoMasIzq(p,A)) && A->dato == K) || Verifica(A,HermanoDer(p,A),k,nivel);
 }





