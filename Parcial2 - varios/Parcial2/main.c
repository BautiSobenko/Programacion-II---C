#include <stdio.h>
#include <stdlib.h>

int main(){


  return 0;
}

/*
Dado un AB de numeros naturales que proviene de la
transformacion de un arbol general, obtener la menor
clave de grado G, ubicado en un nivel menor a N.
En caso de no encontrar ningun nodo retornar 999
*/

void MenorClave(TArbol A, int G, int N, int nivel, unsigned int *Menor){

  TArbol aux;
  int grado = 0;

  if( A != NULL && nivel <= N ){
    aux = A->izq; //Asigno hijoMasIzq
    while( aux != NULL ){ //Recorro todos los hnos
      grado++;
      aux = aux->der;
    }
    if( grado == G && A->dato < *Menor)
      *Menor = A->dato;
    MenorClave(A->izq,G,N,nivel+1,Menor); //voy al hijo
    MenorClave(A->der,G,N,nivel,Menor);   //voy al hno
  }


}

/*
Dado un arbol Nario, verificar mendiante una funcion entera,
que exista al menos un nodo de grado G, distinto de cero
que posea mas de la mitad de sus hijos con clave neg.
*/

int Verifica(TArbol A, posicion p){

  int grado = 0, contCeros = 0;
  int flag = 0;
  posicion c;

  if( nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !nulo(c) ){
      grado++;
      if( info(c,A) == 0 )
        contCeros++;
      flag = Verifica(A,c);
    }
    return (grado == G && contCero/grado > 0.5) || flag;

  }

}

