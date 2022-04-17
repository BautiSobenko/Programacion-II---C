#include "ProtListaEst.h"


void AgregaP(p_pila P,TelementoP x){

    if(P->tope!=MaxArray-1){
        P->datos[++P->tope] = x;
        printf("\nElemento agregado con exito!\n");
    }else
        printf("\nPila completa\n");
}

void QuitaP(p_pila P,TelementoP *x){

    if(P->tope!=-1){ // VALOR NULL
        *x = P->datos[P->tope--];
    }
}

void IniciaP(p_pila P){
    P->tope = -1;
}

int VaciaP(Nodo P){
    if(P.tope==-1){
        return 1;
    }else
        return 0;
}

TelementoP ConsultaP(Nodo P){
    if(P.tope!=-1)
        return P.datos[P.tope];
}

void MuestraP(Nodo P){

    if(P.tope>=0){
        printf("%d  ->  ",P.datos[P.tope--]);
        return MuestraP(P);
    }else
        printf("NULL (X)");
}
