#include <stdio.h>
#include "TDAANario.h"

void CantidadNodos(TArbolN A,posicion p,int *cant);

int main(){

  TArbolN A;
  int cant=0;

  printf("%d",Raiz(A));

  CantidadNodos(A,Raiz(A),&cant);

  printf("Cantidad de nodos: %d",cant);

  return 0;
}

int CantidadNodos(TArbolN A,posicion p){

  posicion c;
  int aux;

  if( Nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !Nulo(c) ){
      aux += CantidadNodos(A,c);
      c = HermanoDer(A,c); //Vuelta de recursividad
    }
   return aux+1;
  }
}

void ClavesPares(TArbolN A,posicion p,int *cant,int *CantPares){

  posicion c;

  if( !Nulo(p) ){
    (*cant)++;
    if( info(p,A)%2==0 )
      (*CantPares)++;
    c = HijoMasIzq(p,A);
    while( !Nulo(c) ){
      ClavesPares(A,c,cant,suma);
      c = HermanoDer(c,A);
    }
  }
}

int Grado(TArbolN A,posicion p){

  int gradoLocal=0;
  int max=0;

  if( Nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !Nulo(c) ){
      gradoLocal ++;
      if( Grado(A,c) > max )
        max = grado(A,c);
      c = HermanoDer(c,A);
    }
    return (gradoLocal>max)?gradoLocal:max;
  }
}

int NodosImpares(TArbolN A, posicion p, int nivel){

  int grado=0;

  if( Nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !Nulo(c) ){
      grado++;
      aux += NodosImpares(A,c,nivel+1);
      c = HermanoDer(p,A);
    }
   return (nivel%2 && grado%2) + aux;
  }
}

int IncisoE(TArbolN A, posicion p){

  int cantHijos=0;
  int flag=1;

  if( Nulo(p) )
    return 0;
  else{
    c = HijoMasIzq(p,A);
    while( !Nulo(c) && flag){
      cantHijos++;
      flag = IncisoE(A,c);
      c = HermanoDer(c,A);
    } //Salgo cuando el nodo no tenga hijos, o no existan mas hermanos
    if (!cantHijos)
      return 1;
    else
      return flag && (cantHijos == info(p,A));
  }
}

void IncisoE(TArbolN A, posicion p,int *flag){

  int cantHijos=0;
  posicion c;
  if( !Nulo(p) ){
    c = HijoMasIzq(p,A);
    while( !Nulo(c) ){
      cantHijos++;
      IncisoE(A,p,flag);
      c = HermanoDer(c,A);
    }
    if( !cantHijos || cantHijos == info(p,A) )
      *flag = 1;
    else
      *flag = 0;
  }
}

void PromedioClaves(TArbolN A,posicion p,int K,int nivel,int *suma,int *cant){

  if( !Nulo(p) ){
    if( nivel == k ){ //Lo hago para todos los nodos
      (*cant)++;
      *suma += info(p,A);
    }
    c = HijoMasIzq(p,A);
    while( !Nulo(c) && nivel <= K ){
      PromedioClaves(A,p,k,nivel+1,suma,cant);
      c = HermanoDer(c,A);
    }
  }
}
