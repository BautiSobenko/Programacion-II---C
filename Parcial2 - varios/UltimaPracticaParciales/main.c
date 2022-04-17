#include <stdio.h>
#include <stdlib.h>

int main(){


  return 0;
}

/*  dado un arbol binario que proviene de la transformaci�n de un �rbol general,obtener
mediante una funci�n entera la suma de las claves que en el �rbol general su clave coincida con
su altura y su grado
-mostrar la invocaci�n de la soluci�n desarrollada*/

int Suma(TArbol A,int nivel){

  TArbol aux; //La utilizo para recorrer por los hnos
  int grado=0;

  if( A == NULL )
    return 0;
  else{
    if( A->dato != nivel )
      return Suma(A->izq,nivel+1) + Suma(A->der,nivel);
    else{ //Clave igual al nivel
      aux = A->izq;
      while( aux != NULL ){
        grado++;
        aux = A->der
      }
      if( grado == A->dato )
        return A->dato + Suma(A->izq,nivel+1) + Suma(A->der,nivel);
      else
        return Suma(A->izq,nivel+1) + Suma(A->der,nivel);
    }
  }
}
/*EJ2 (utilizando TDA N-ario) Dado un �rbol N-ario de enteros que contiene exactamente dos ceros, desarrollar una funci�n que
 obtenga el mayor nivel en el que haya un cero
-mostrar la invocaci�n de la soluci�n desarrollada*/

void MayorNivel(TArbol A, posicion p, int nivel, int *contCero,int *mayorNivel){

  if( !nulo(p) && *contCero < 2 ){
    if( info(p,A) == 0 ){
      (*contCero)++;
      if( nivel > *mayorNivel )
        *mayorNivel = nivel;
    }
    MayorNivel(A,HijoMasIzq(p,A),nivel+1,contCero,mayorNivel);
    MayorNivel(A,HermanoDer(p,A),nivel,contCero,mayorNivel);
  }

}

/*EJ1 Dado un ABB de caracteres, obtener la clave del nodo de grado 2 que se encuentre
ubicado en el mayor nivel. Si no hubiera ning�n nodo de grado 2 en el �rbol, retornar el caracter blanco.*/

void MayorNivel(TArbol A, int nivel, int *mayorNivel, char *clave){

  if( A != NULL ){
    if( A->izq && A->der && nivel > *mayorNivel ){
      *mayorNivel = nivel;
      *clave = A->dato;
    }
    MayorNivel(A->izq,nivel+1,mayorNivel,clave);
    MayorNivel(A->der,nivel+1,mayorNivel,clave);
  }

}

/*EJ2 (utilizar TDA N-ario) Dado un �rbol N-ario de enteros, desarrollar una funci�n entera que obtenga
la cantidad de nodos de grado mayor a 1, ubicados entre los niveles K1 y K2, que verifican que las claves
del primer y del �ltimo hijo son mayores al nivel del nodo. K1 y K2 son dato.*/

int CantidadNodos(TArbol A, posicion p, int nivel, int K1, int K2){

  posicion c;
  int grado=0;

  if( nulo(p) || nivel > K2 )
    return 0;
  else{
    if( nivel < K1 )
      return CantidadNodos(A,HijoMasIzq(p,A),nivel+1,K1,K2) + CantidadNodos(A,HermanoDer(p,A),nivel,K1,K2);
    else{
      c = HijoMasIzq(p,A);
      priHijo = info(c,A);
      while( !nulo(c) ){
        grado++;
        ultHijo = info(c,A)
        c = HermanoDer(c,A);
      }
      return (grado>1 && priHijo > nivel && ultHijo > nivel) + CantidadNodos(A,HijoMasIzq(p,A),nivel+1,K1,K2) + CantidadNodos(A,HermanoDer(p,A),nivel,K1,K2);
    }
  }

}

/*EJ1 Dado un �rbol binario que proviene de la transformaci�n de un �rbol general de claves enteras,
desarrollar una FUNCI�N ENTERA que cuente cu�ntas claves de nodos NO HOJA, eran menores a la suma
de las claves de sus hijos (en el �rbol general)*/

int Cuenta(TArbol A){

  if( A == NULL )
    return 0;
  else{
    aux = A->izq;
    while( aux != NULL ){
      sumaHijos += aux->dato;
      aux = aux->der;
    }
    return ( A->izq != NULL && A->dato < sumaHijos ) + Cuenta(A->izq) + Cuenta(A->der);
  }

}

/*EJ2 Dado un �rbol N-Ario de enteros, verificar que exista alg�n nodo NO HOJA con clave K en el nivel K
(K dato)*/

int Verifica(TArbol A, posicion p, int K, int nivel){

  if( nulo(p) || nivel > k )
    return 0;
  else
    if( !nulo(HijoMasIzq(p,A) && nivel == K && info(p,A) == K )
      return 1;
    else
      return Verifica(A,HijoMasIzq(p,A),K,nivel+1) || Verifica(A,HermanoDer(p,A),K,nivel);

}

/*EJ1 dado un arbol binario proveniente de la transformaci�n de un bosque,
verificar si todos los �rboles del bosque ten�an alg�n nodo de grado exactamente X(X es dato)*/

int Verifica(TArbol A){

  TArbol aux = A;
  int flag = 1;
  while( aux != NULL && flag ){
    aux = aux->izq;
      while( aux != NULL ){
        grado++;
        aux = aux->der;
      }
      if(grado != X)
        flag = 0;
    if( flag )
      if( !gradoX(aux->izq,X) )
        flag = 0;
    aux = aux->der;
  }
  (flag)? return 1 : return 0;
}

int gradoX(TArbol A,int X){

  TArbol aux=A;
  int grado=0;

  aux = aux->izq
  while( aux != NULL ){
    grado++;
    aux = aux->der;
  }
  return (grado = X) || gradoX(A->izq,X) || grado(A->der,X);


}

while( aux != NULL && flag ){
    if( gradoX(aux,2) == 0 )
      flag = 0;
    aux = aux->der;
  }
  if( flag )
    return 1;
  else
    return 0;
}

int gradoX(TArbol A,int X){

  TArbol aux;
  int grado=0;
  int flag=0;

  if( A == NULL )
    return 0;
  aux = A->izq;
  while( aux != NULL && !flag ){
    grado++;
    flag = gradoX(aux,X);
    aux = aux->der;
  }
  return (grado == X) || flag;
}

int Verifica(TArbol A){

  TArbol aux = A;
  int flag = 1;
  while( aux != NULL && flag ){
    if( !gradoX(aux->izq,X) )
      flag = 0;
    aux = aux->der;
  }
  (flag)? return 1 : return 0;
}

int gradoX(TArbol A,int X){

  TArbol aux=A;
  int grado=0;
  int flag=0;

  aux = aux->izq
  while( aux != NULL && !flag ){
    grado++;
    flag = gradoX(aux,X);
    aux = aux->der;
  }
  return (grado = X) || flag;
}





