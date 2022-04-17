#include "TDAAnario.h"
#include <stdio.h>
#include <stdlib.h>

void carga(TArbolN *AN){
    (*AN).raiz=0;

    (*AN).nodos[0].izq=1;  //Hijos
    (*AN).nodos[0].der=-1; //Padre
    (*AN).nodos[0].dato=17;


    (*AN).nodos[1].izq=2;
    (*AN).nodos[1].der=3;
    (*AN).nodos[1].dato=23;

    (*AN).nodos[2].izq=-1; //Primer hijo izquierdo
    (*AN).nodos[2].der=4;  //Hermano derecho
    (*AN).nodos[2].dato=14;//Dato del nodo

    (*AN).nodos[3].izq=5;
    (*AN).nodos[3].der=6;
    (*AN).nodos[3].dato=45;

    (*AN).nodos[4].izq=-1;
    (*AN).nodos[4].der=-1;
    (*AN).nodos[4].dato=13;

    (*AN).nodos[5].izq=-1;
    (*AN).nodos[5].der=7;
    (*AN).nodos[5].dato=5;

    (*AN).nodos[6].izq=8;
    (*AN).nodos[6].der=10;
    (*AN).nodos[6].dato=56;

    (*AN).nodos[7].izq=-1;
    (*AN).nodos[7].der=9;
    (*AN).nodos[7].dato=4;

    (*AN).nodos[8].izq=-1;
    (*AN).nodos[8].der=10;
    (*AN).nodos[8].dato=2;

    (*AN).nodos[9].izq=-1;
    (*AN).nodos[9].der=-1;
    (*AN).nodos[9].dato=3;

    (*AN).nodos[10].izq=-1;
    (*AN).nodos[10].der=-1;
    (*AN).nodos[10].dato=1;

}

int Nulo(posicion p){
    return p==-1;
}

posicion HijoMasIzq(posicion p, TArbolN AN){
    return AN.nodos[p].izq;
}

posicion HermanoDer(posicion p, TArbolN AN){
    return AN.nodos[p].der;
}

int Vacio(TArbolN AN){
    return Raiz(AN)==-1;
}

posicion Raiz(TArbolN AN){
    return AN.raiz;
}

int Info(posicion p, TArbolN AN){
    return AN.nodos[p].dato;
}

