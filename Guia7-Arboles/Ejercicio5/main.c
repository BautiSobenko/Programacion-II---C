#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbolB;

//Prototipos

int Profundidad(TArbolB A);

void CadMasLarga(TArbolB A, int long, char cad[]);

int CantHijosDerechos(TArbolB A);

int main(){

  char cad[];

  printf("Profundidad de AB: %d",Profundidad(A));

  CadMasLarga(A,0,cad);

  printf("Cant. hijos dchos. %d",CantHijosDerechos(A))

  return 0;
}

int Profundidad(TArbolB A){

  int izq,der;

  if( A == NULL )
    return 0;
  else{
    izq = Profundidad(A->izq);
    der = Profundidad(A->der);
    if( izq > der )
      return izq+1;
    else
      return der+1;
  }
}

void Profundidad(TArbolB A,int altAux,int *altura){

  if( A != NULL ){
    Profundidad(A->izq,altAux+1,altura);
    if( altAux > *altura )
      *altura = altAux;
    Profundidad(A->der,altAux+1,altura);
  }
}

void CadMasLarga(TArbolB A, int long, char cad[]){


  if( A != NULL ){
    if( strlen(A->dato) > long ){ //Supera longitud
      long = strlen(A->dato); //Acutalizo long
      strcpy(cad,A->dato);    //Actualizo maximo
    }
    CadMasLarga(A->izq,long,cad);
    CadMasLarga(A->der,long,cad);
  }

}

int CantHijosDerechos(TArbolB A){

  if( A == NULL )
    return 0;
  else
    return (A->der) + CantHijosDerechos(A->izq) + CantHijosDerechos(A->der);

}


