#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  char dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int main(){


  return 0;
}

/*
1- Dado un árbol binario de búsqueda (ABB) de caracteres, desarrollar un subprograma que genere un vector V con las claves ubicadas en
niveles menores o iguales a N (N es dato).
Los elementos del vector deben insertarse ordenados descendentemente.
*/

void GeneraV(TArbol A, int N, int nivel, char V[], int *dimV){

  if( A != NULL && nivel <= N ){
    GeneraV(A->izq,N,nivel+1,V,dimV);
    V[(*dimV)++] = A->dato;
    GeneraV(A->der,N,nivel+1,V,dimV);
  }
}

/*
2- (Utilizar TDA N-ario) Dado un árbol N-Ario de enteros, verificar mediante una función entera, que todos los nodos de grado K (K es dato)
tienen al menos un hijo con clave igual a cero.
*/

int Verifica(TArbol A, posicion p, int K){

  posicion c;
  int grado = 0;
  int flag = 1, cuentaCero = 0;

  if( nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !nulo(c) && flag){
      grado++;
      if( info(c,A) == 0 )
        cuentaCero++;
      flag = Verifica(A,c,K);
      c = HermanoDer(c,A);
    }
    return (cuentaCero || grado != K) && flag
  }
}

/*
3- Dado un digrafo de N vértices con aristas ponderadas almacenado en una matriz de adyacencia, hallar cuántos nodos que tienen bucle tienen grado
de entrada par.
*/

void Cuenta(int MAdy[][N], int N, int i, int j,int iAux, int GrE, int *cont){

  if( j >= 0){
    if( !MAdy[j][j] )
      Cuenta(MAdy,i,j-1,iAux,0,cont);
    else{
      if( i >= 0 ){
        if( MAdy[i][j] )
          grE++;
        Cuenta(MAdy,i-1,j,iAux,grE,cont);
      }else{
        if( grE%2 == 0 )
          (*cont)++;
        Cuenta(MAdy,iAux,j-1,iAux,0,cont);
      }
    }
  }

}
