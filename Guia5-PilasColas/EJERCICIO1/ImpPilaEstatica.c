typedef int TElementoP; //Tipo de elemento de la pila

typedef struct TPila{
    TElementoP datos[50]; //El tamaño de la pila
    int tope; //Guardara la ultima posicion de la pila
}TPila;

void poneP(TPila *P, TElementoP x) {
 if ( ((*P).tope)!=49) // Si la cola no esta completa
    (*P).datos[++((*P).tope)] = x; //Subo de posicion y agrego el elemento
}
void sacaP(TPila *P, TElementoP* x) {
 if (((*P).tope) != -1) //Si la cola no esta vacia
    (*x) = (*P).datos[((*P).tope)--]; //Quito el ultimo elemento y bajo de posicion
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
