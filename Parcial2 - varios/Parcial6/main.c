#include <stdio.h>
#include <stdlib.h>

int main(){

  return 0;
}

/*Dado un AB proveniente de la transformacion
de un arbol general, obtener mediante una
funcion int, la suma de las claves
que en el arbol general, su clave coincidia
con su altura
*/

int Suma(TArbol A,int nivel){

  TArbol aux;
  int grado=0;

  if( A == NULL )
    return 0;
  else{
    if( nivel == A->dato){
      aux = A->izq;
      while( aux != NULL ){
        grado++
        aux = aux->der;
      }
    if( grado == A->dato )
      return A->dato + Suma(A->izq,nivel+1) + Suma(A->der,nivel);
    }
    return Suma(A->izq,nivel+1) + Suma(A->der,nivel);
  }

}

void MayorNivel(TArbol A,posicion p,int nivel,int *mayorNivel){

 int contCero=0;

  if( !nulo(p) && contCero <= 2)
    if( info(p,A) != 0 ){
      MayorNivel(A,HijoMasIzq(p,A),nivel+1);
      MayorNivel(A,HermanoDer(p,A),nivel);
    }else{
      if( nivel > *mayorNivel){
        *mayorNivel = nivel;
        contCeros++;
      }
      MayorNivel(A,HijoMasIzq(p,A),nivel+1);
      MayorNivel(A,HermanoDer(p,A),nivel);
    }

}




