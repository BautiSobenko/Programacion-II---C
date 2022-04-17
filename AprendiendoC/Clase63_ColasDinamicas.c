typedef int TelementoC;

typedef struct Nodo{
    TelementoC dato;
    struct Nodo *sig;
}Nodo;

typedef struct Cola{
    Nodo* primero;
    Nodo* ultimo;
}Cola;

void IniciaC(Cola *C){

    Cola->primero = NULL;
    Cola->ultimo = NULL;

}

void AgregaC(Cola *C,TelementoC x){

    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = x;
    aux->sig = NULL;
    if(!C->primero)
        C->primero = aux;
    else
        C->ultimo->sig = aux;
    C->ultimo = aux;
}

void QuitarC(Cola *C,TelementoC* x){

    if(C->primero != NULL){
        Nodo* aux = C->primero;
        *x = C->primero->dato;
        C->primero = C->primero->sig;
        free(aux);
    }else
        printf("\nCola actualemente vacia.\n");
    free(aux);
}

int VaciaC(Cola C){
    return (C->primero==NULL)?return 1: return 0;
}

TelementoC ConsultaC(Cola C){

    return C->primero->dato;
}
