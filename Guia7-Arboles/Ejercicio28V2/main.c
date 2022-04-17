#include <stdio.h>
#include <stdlib.h>

int main(){

  TArbolN A;


  return 0;
}

// a) retornar la cantidad de nodos que posee.

int CantNodos(TArbolN A, posicion p){

  posicion c;

  if( Nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !Nulo(c) ){
      aux += CantNodos(A,c);
      c = HermanoDer(c,A);
    }
  return 1 + aux;
  }
}

int Esta(TArbol A, posicion p,int X){
    if( Nulo(p) )
      return 0;
    else
        return ( info(p,A) == X || Esta(A, HijoMasIzq(p,A),X) || Esta(A, HermanoDer(p,A),X) );
}

int BuscaCero(TArbolN A,posicion p){

  posicion c;
  int flag=0;

  if( Nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !Nulo(c) && flag ){
      flag = BuscaCero(A,c);
      c = HermanoDer(c,A);
    }
    return info(p,A)==0 || flag;
  }
}

int BuscaAlNeutro(TArbol A,posicion p){
   if( nulo(p) )
     return 0;
   else
     return  info(p,A)==0 || BuscaAlNeutro(A,hijoMasIzq(p,A)) || BuscaAlNeutro(A,hnoDer(p,A));
}
