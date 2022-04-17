#include "InterfazPila.h"

void poneP(TPila *P, TElementoP x) {
 if ( ((*P).tope)!=49){ // Si la cola no esta completa
    (*P).datos[++((*P).tope)] = x; //Subo de posicion y agrego el elemento
    //printf("Elemento %c apilado con exito\n",x);
 }else
    printf("Pila completa\n",x);
}
void sacaP(TPila *P, TElementoP* x) {
 if (((*P).tope) != -1){ //Si la cola no esta vacia
    (*x) = (*P).datos[((*P).tope)--]; //Quito el ultimo elemento y bajo de posicion
    //printf("Elemento %c desapilado con exito\n",*x);
 }else
    printf("Pila vacia\n",x);
}
TElementoP consultaP(TPila P) {
 if ((P.tope) != -1) //Si la cola no esta vacia
    return P.datos[P.tope]; //Devuelte el tope de la pila (elemento de ult. pos)
}
int VaciaP(TPila P) {
 return (P.tope == -1); //Retornara 1 si la pila se encuentra vacia, y 0 si no
}
void IniciaP (TPila *P) {
(*P).tope=-1; //Tope sin asignar
}

void MuestraP(TPila P){
    int i;
    for(i=0; i<P.tope;i++){
        printf("|%c|\n",P.datos[i]);
    }

}
void MuestraPRec(TPila P){

    if(P.tope>0){
        printf("|%c|\n",P.datos[P.tope--]);
        MuestraPRec(P);
    }else
        printf("|%c|\n",P.datos[P.tope]);

}
