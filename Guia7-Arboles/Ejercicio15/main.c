#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
  int dato;
  struct Nodo *izq,*der;
}Nodo;

typedef struct Nodo* TArbol;

int EsABB(TArbol);

int main(){

  TArbol arbol;

  EsABB(arbol);

  return 0;
}

int EsABB(TArbol A){

  if( A == NULL )
    return 1;
  else{
    if( A->izq == NULL && A->der == NULL ) //Grado 0, hoja
      return 1;
    else{
      if( A->dato < A->izq->dato || A->dato > A->der->dato ) //No cumple cond ABB
        return 0;
      else{
       if( A->izq == NULL ) //Grado 1
         return EsABB(A->der);
       else if( A->der == NULL ) //Grado 1
         return EsABB(A->izq);
       else if( A->der != NULL && A->der != NULL ) //Grado 2
         return EsABB(A->izq) && EsABB(A->der);
      }
    }
  }
}

int EsABB(TArbol A){

  if( A == NULL )
    return 1;
  else{
    if( A->izq == NULL && A->der == NULL ) //Grado 0, hoja
      return 1;
    else{
      if( A->dato < A->izq->dato || A->dato > A->der->dato ) //No cumple cond ABB
        return 0;
      else{
       if( A->izq == NULL ) //Grado 1
         return EsABB(A->der);
       else if( A->der == NULL ) //Grado 1
         return EsABB(A->izq);
       else if( A->der != NULL && A->der != NULL ) //Grado 2
         return EsABB(A->izq) && EsABB(A->der);
      }
    }
  }
}

int esABB(TArbol A){
    if (A!=NULL){
        if (A->izq==NULL && A->der==NULL) //hoja
            return 1;
        else
            if(A->izq && A->der==NULL) //grado 1
                if (A->izq->dato>A->dato)
                    return 0;
                else
                    return esABB(A->izq);
            else
                if(A->der && A->izq==NULL) //grado 1
                    if (A->der->dato<A->dato)
                        return 0;
                    else
                        return esABB(A->der);
                else
                    if (A->izq->dato>A->dato || A->der->dato<A->dato) //grado 2
                        return 0;
                    else
                        return esABB(A->der) && esABB(A->izq);
    }else
        return 1;
}


