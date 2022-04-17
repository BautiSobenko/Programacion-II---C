//Implementacion pilas

typedef int TelementoP; //Tipo de dato de pila: entero

typedef struct Nodo{
    TelementoP dato;  //Valor que tomara el nodo
    struct Nodo* sig; //Permite enlace con otro nodo
}Nodo;  //Creamos la estructura

typedef Nodo* p_nodo; //Apuntador a estructura Nodo

void IniciaP(p_nodo *P){ //Paso P por referencia para modificar su valor
    *P = NULL;
}

void Apila(p_nodo *P,TelementoP x){
    p_nodo aux; //Equivalente a Nodo* aux
    aux = (p_nodo)malloc(sizeof(Nodo)); //Creamos el espacio en heap
    aux->sig = *P; //El nuevo nodo se enlaza con el anterior
    aux->dato = x; //Guardo valor en el nodo
    *P = aux; //P apunta al nuevo espacio en memoria,al nodo creado
}

void Desapila(p_nodo *P,TelementoP *x){
    p_nodo aux;
    aux = *P; //Apunto al mismo lugar que P (ambos pointers al mismo nodo)
    if(P != NULL){
        *x = aux->dato; //No debo perder el valor del nodo(evito perdida de info.)
        *P = (*P)->sig;
    }else
        printf("\nLa pila se encuentra vacia\n");
    free(aux);  //Libero espacio en heap
}

TelementoP ConsultaP(p_nodo P){ //Devuelvo ultimo elemento de la pila
    return P->dato;
}

int VaciaP(p_nodo P){ //Pila vacia? 1=TRUE
    return (P==NULL)?1:0;
}
