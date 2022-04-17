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
    C->primero = NULL;
    C->ultimo = NULL;
}

void AgregaC(Cola *C,TelementoC x){

    Nodo *aux = (Nodo)malloc(sizeof(Nodo)); //Asignacion de memoria
    if(aux==NULL){
        printf("Error en la asignacion de espacio en memoria");
        return -1;
    }

    aux->dato = x; //Guardo el elemento en el dato
    aux->sig = NULL; //Siempre el ultimo nodo tiene su puntero en NULL

    if(C->primero==NULL) //Si no hay nodos
        C->primero = aux //Apunto "primero" al primer nodo creado
    else
        c->ultimo->sig = aux;//Enlazo los nodos, el anterior con el nodo ahora creado
    c->ultimo = aux; //Apunto "ultimo" al nodo ultimo y recien creado

}

void QuitarC(Cola *C,TelementoC *x){

    Cola *aux;
    if(C->primero != NULL && C->ultimo != NULL){
        *x = C->primero->dato;
        aux = C->primero;
        C->primero = C->primero->sig;
        free(aux);
    }
}

TelementoC ConsultaC(Cola C){

    return C->primero->dato;
}

int VaciaC(Cola C){

    if(C->primero)? return 1: return 0;
}


