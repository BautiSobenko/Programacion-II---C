#include <stdio.h>
#include <stdlib.h>

int main(){



  return 0;
}



int Ej(Tarbol a,posicion p,int nivelact,int k){

  int contV=0;

  if(nulo(p))
      return 0;
  else
    if( nivelact < k )
      return Ej(a,hijomasizq(p,a),nivelact+1) && Ej(a,hermanoder(p,a),nivelact);
    else{
      c=hijomasizq(p,a);
      while(!nulo(c) && contV!=2){
        if(info(c,a)=='a' || info(c,a)=='e'|| info(c,a)=='i'|| info(c,a)=='o'|| info(c,a)=='u')
          contV++;
          c=hermanoder(c,a);
        }
      return contV==2;
    }

}



/*
Dado un N-ario de enteros,mediante una funcion int,
determinar la cantidad de nodos que no tienen
hijos cuya clave sea 0/
*/


int Cantidad(TArbol A,posicion p){

  posicion c;
  int cont=0;
  int tieneCero=0;

  if( !nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !nulo(c) ){
      if( info(c,A) == 0 )
        tieneCero = 1;
      cont += Cantidad(A,c);
      c = HermanoDer(c,A);
    }
    return !tieneCero + cont;
  }

}
