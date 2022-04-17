#include <stdio.h>
#include <stdlib.h>

int main(){


}

/*
Dado un ABB de caracteres, obtener la clave del nodo de
grado 2 que se encuentre en el mayor nivel.
Si no hubiera nodos de grado 2,retornar el caracter blanco
*/


void MayorNivel(TArbol A, int nivel,int *nivelMax, char *C){

  if( A != NULL ){
    if( A->der && A->izq && nivel > *nivelMax ){
      *nivelMax = nivel;
      *C = A->dato;
    }
    MayorNivel(A->izq,nivel+1,nivelMax,C);
    MayorNivel(A->der,nivel+1,nivelMax,C);
  }
}

/*
Dado un arbol Nario, desarrollar una funcion int,
que obtenga la cantidad de nodos de grado mayor a 1,
ubicados entre los niveles k1 y k2, que verifican
que las claves del primer y ultimo hijo son mayores
al nivel del nodo
*/

int Cuenta(TArbol A, posicion p, int K1, int K2, int nivel){

  posicion c;
  int priHijo,ultHijo;
  int grado=0;

  if( nulo(p) || nivel > k2)
    return 0;
  else
    if( nivel < k1 )
      return Cuenta(A,HijoMasIzq(p,A),K1,K2,nivel+1) + Cuenta(A,HermanoDer(p,A),K1,K2,nivel);
    else{
    c = HijoMasIzq(p,A);
    priHijo = info(c,A); //Guardo 1er hijos
    while( !nulo(c) ){
      grado++;
      ultHijo = info(c,A); //Guardo ult hijo
      c = HermanoDer(c,A);
    }
    if( priHijo > nivel && ultHijo > nivel && grado > 1)
      return 1 + Cuenta(A,HijoMasIzq(p,A),K1,K2,nivel+1) + Cuenta(A,HermanoDer(p,A),K1,K2,nivel);
    else
      return Cuenta(A,HijoMasIzq(p,A),K1,K2,nivel+1) + Cuenta(A,HermanoDer(p,A),K1,K2,nivel);
  }

}

