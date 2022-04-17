//PRUEBA IMPLEMENTACION

typedef int TelementoP

typedef struct Nodo{
    TelementoP dato;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* p_nodo;

void AgregarP(p_nodo *P,TelementoP x){


    p_nodo nodo; // === struct Nodo *p_nodo;

    nodo = (p_nodo)malloc(sizeof(Nodo));

    if(!nodo){
        printf("Error en asignacion de memoria");
        return -1;
    }

    nodo->dato = x;
    nodo->sig = *P;
    *P = nodo;
}

void QuitarP(p_nodo *P,TelementoP* x){

    //creo auxiliar

    p_nodo aux;

    if(*P =! NULL){
        aux = *P
        *x = (aux)->dato;
        aux = (aux)->sig;
        free(aux);
    }
}

void CreaP(p_nodo *pila){

    *pila = NULL;
}


