#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    int tiempo;
}Nodo;

typedef struct Nodo* p_nodo;

int main(){

   p_nodo p;
   p = &Nodo;

   p->dato = 10;
   p->tiempo = 60;

    printf("Dato %d\n",p->dato);
    printf("Tiempo %d\n",p->tiempo);

    return 0;
}
