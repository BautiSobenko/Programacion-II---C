
typedef int TelementP;

typedef struct Nodo{
    TelementoC dato;
    struct Nodo* sig;
}Nodo;

typedef Nodo* p_nodo;

void iniciaP(p_nodo *P){
    *P = NULL;
}

void AgregaP(p_nodo *P,TelementoP x){

    p_nodo aux = (p_nodo)malloc(sizeof(Nodo));
    aux->dato = x;
    aux->sig = (*P);
    *P = aux;
}

void QuitarP(p_nodo *P, TelementoP *x){

    if(*P){
        p_nodo aux;
        aux = *P;
        *x = aux->dato;
        *P = aux->sig;
        free(aux);
    }
}

TelementoP ConsultarP(p_nodo P){
    if(P)
        return P->dato;
}

int VaciaP(p_nodo P){

    if(!P)
        return 1;
    else
        return 0;
}
