#include <stdio.h>
#include <stdlib.h>

int main(){


  return 0;
}

/*
Dado un arbol N-ario de numeros positivos obtener
mediante una funcion int, el nivel maximo en
el que haya un nodo de grado 3
*/

int Ej(Tarbol a,posicion p,int nivel){

  posicion c;
  int gr=0;
  int max=0;
  int nvHijo;

   if( nulo(p) )
      return 0;
    else
       c=hijomasizq(p,A);
       while( !nulo(c) ){
         gr++;
         c = hermanoDer(c,a);
         nvHijo = Ej(a,c,nivel+1);
         if(nvHijo>max)
           max=nvHijo;
         }
        if(gr==3)
          (max>nivel)?return max:return nivel;
        else
           return max;
}

/*Dado un AB de caracteres proveniente de un
bosque, verificar que existian al menos 2
arboles que cumplian tener al menos un nodo
de grado K cuyos hijos eran todas vocales*/

int Recorre(TArbol A){

  TArbol aux = A;

  while ( aux != NULL && cont != 2){
    if( Verifica(aux,K) )
      cont++;
    aux = aux->der;
  }
  (cont == 2)? return 1 : return 0;
}

int Verifica(TArbol A,int K){

  TArbol aux;
  int grado=0, flag=0;

  aux = A->izq;
  while ( aux != NULL && !flag){ //Recorro hermanos
    grado++;
    if( aux->dato != 'a' || aux->dato != 'e' || aux->dato != 'i' || aux->dato != 'o' || aux->dato != 'u')
      flag = 1;
    aux = aux->der;
  }
  return (grado == K && !flag) || Verifica(A->izq,K) || Verifica(A->der,K);

}

/*Dado un Arbol N-ario de enteros
verificar mediante una funcion int, que
existe algun nodo con grado mayor a J entre
los niveles K y L.
*/

int Verifica(TArbol A, posicion p, int J, int K, int L, int nivel){

  if( nulo(p) || nivel > L )
    return 0;
  else
    if( nivel < K )
      return Verifica(A,HijoMasIzq(p,A),J,K,L,nivel+1) || Verifica(A,HermanoDer(p,A),J,K,L,nivel);
    else{ // nivel -> [K,L]
      c = HijoMasIzq(p,A);
      while( !nulo(c) && grado <= J ){
        grado++;
        c = HermanoDer(c,A);
      }
      return (grado > J) || Verifica(A,HijoMasIzq(p,A),J,K,L,nivel+1) || Verifica(A,HermanoDer(p,A),J,K,L,nivel);
    }

}

