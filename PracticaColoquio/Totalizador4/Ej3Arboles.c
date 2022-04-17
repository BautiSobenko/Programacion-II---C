#include <stdio.h>
#include <stdlib.h>
#include "Nario.h"

int main(){

  TArbol A;

  printf("Cantidad obtenida: %d",ContHojas(A,raiz(A),K,0));

  return 0;
}

int ContHojas(TArbol A, posicion p, int K, int nivel){

  if( nulo(p) || nivel > K)
    return 0;
  else
    if( nivel < K )
      return ContHojas(A,HijoMasIzq(p,A),K,nivel+1) + ContHojas(A,HermanoDer(p,A),K,nivel);
    else
      return (nulo(HijoMasizq(p,A)) && info(p,A) == 0 ) + ContHojas(A,HijoMasIzq(p,A),K,nivel+1) + ContHojas(A,HermanoDer(p,A),K,nivel);
}
