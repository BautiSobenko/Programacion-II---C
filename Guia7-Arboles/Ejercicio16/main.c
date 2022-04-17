#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    inserta(abb,x);
}

void inserta(Tarbol abb,int x){
Tarbol aux,ant;

      ant=NULL;
      aux=abb;
      while(aux!=NULL){
        if(aux->dato>x){
            aux=aux->izq;
            izq=1;
        }
        else{
            aux=aux->der;
            der=1
        }
      }
      nuevon=(Tarbol)malloc(sizeof(nodo));
      nuevon->dato=x;
      nuevon->der=nuevon->izq=NULL;
      if(izq)
        ant->izq=nuevon;
      else
        ant->der=nuevon;
}
