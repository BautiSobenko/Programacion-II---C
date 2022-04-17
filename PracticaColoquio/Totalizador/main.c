#include <stdio.h>
#include <stdlib.h>

int main(){


  return 0;
}

void GeneraLista(TArbol A, posicion p, int nivel, TListaD *LD){

  posicion c;
  int grado=0;
  PNodoD nuevoLD;

  if( !nulo(p,A) ){
    if( nivel%2 != 0 ){
      GeneraLista(A,HijoMasIzq(p,A),nivel+1,LD);
      GeneraLista(A,HermanoDer(p,A),nivel,LD);
    }else{
      c = HijoMasIzq(p,A);
      while( !nulo(c) ){
        grado++;
        c = HermanoDer(c,A);
      }
      if( grado%2 == 0){
        nuevoLD = (PNodoD)malloc(sizeof(NodoD));
        nuevoLD->dato = info(p,A);
        if( *LD.pri == NULL ){ //Insercion en primera pos.
          *LD.pri = nuevoLD;
          *LD.ult = nuevoLD;
          nuevoLD->sig = NULL;
          nuevoLD->ant = NULL;
        }else{
          nuevoLD->ant = NULL;
          nuevoLD->sig = *LD.pri;
          *LD.pri->ant = nuevoLD;
          *LD.pri = nuevoLD;
        }
      }
      GeneraLista(A,HijoMasIzq(p,A),nivel+1,LD);
      GeneraLista(A,HermanoDer(p,A),nivel,LD);

    }
  }



}
