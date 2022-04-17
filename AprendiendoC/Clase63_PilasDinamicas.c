typedef int TelementoP;

typedef struct Nodo{
    TelementoP dato;
    struct Nodo *sig;
}Nodo;

typedef Nodo* p_nodo;

void IniciaP(p_nodo *P){
    *P = NULL;
}

void AgregaP(p_nodo *P,TelementoP x){

    p_nodo aux = (p_nodo)malloc(sizeof(Nodo));
    aux = P;
    aux->dato = x;
    aux->sig = P;
    *P = aux;
}

void QuitarP(p_nodo *P,TelementoP *x){

    p_nodo aux = P;
    if(!P)
        printf("\nLa pila esta actualmente vacia.\n");
    *x = aux->dato;
    *P = aux->sig;
    free(aux);
}

int VaciaP(p_nodo P){

    return (!P)? return 1:return 0;
}

TelementoP ConsultaP(p_nodo P){

    return (P->dato):

}
