#include <stdio.h>
#include <stdlib.h>

//No pasa dimv por referencia para su modificacion.
void arrgrado2(arbol a, char v[N], int dimv){
 if (a != NULL) {
   if(a->izq != NULL && a->der == NULL)
//Si A->der == NULL y A->izq != NULL, el nodo seria de grado 1
 (*dimv)++;
 v[dimv] = a->dato; //Paso por referencia o por valor???
 } else // Mal el else, no avanzaria nunca en el arbol
 arrgrado2(a->izq, v[], dimv); //Pasamos v, y no v[]
 arrgrado2(a->der, v[], dimv);
 }
}

