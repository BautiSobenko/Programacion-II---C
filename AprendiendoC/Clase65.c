//Implementacion de colas

typedef int TelementoC;

typedef struct Nodo{
    TelementoC dato;
    struct Nodo* sig;
}Nodo;

typedef struct Cola{
    Nodo* primero;
    Nodo* ultimo;
}Cola;

void IniciaC(Cola *C){
    C->primero=NULL;
    C->ultimo=NULL;
}

void Encola(Cola *C,TelementoC x){
    Nodo *aux; //Creo puntero a la estructra de nodo
    aux = (Nodo*)malloc(sizeof(Nodo)); //Asigno espacio en memoria heap
    aux->dato = x; //Asigno valor al nodo
    aux->sig = NULL; //Todo nuevo no tiene enlace, apunta a la nada
    if(!C->primero){ //Si el first pointer no esta asignado
        C->primero = aux; //Asigno un comienzo a la cola
    }else
        C->ultimo->sig = aux; //Enlazo el nodo anterior con el creado
    C->ultimo = aux; //Corro el puntero final

}

void Desencolar(Cola *C,TelementoC *x){
    Nodo* aux; //Creo pointer a estructura nodo
    aux = C->primero; //Aux apunta al comienzo de la cola
    if(C->primero != NULL){ //Si la pila no esta vacia
        *x = aux->dato;     //No pierdo info. Guardo el dato
        C->primero = C->primero->sig; //El segundo nodo ahora es el primero
    }else
        printf("\nLa cola se encuentra vacia\n");
    free(aux); //Se libera memoria. Nodo eliminado
}

TelementoC ConsultaC(Cola C){ //Consulto el ultimo elemento de la cola
    return C.ultimo;
}

int VaciaC(Cola C){
    return (!C.primero)?1:0;
}



