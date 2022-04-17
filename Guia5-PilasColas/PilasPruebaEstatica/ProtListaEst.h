#define MaxArray 30

typedef int TelementoP;

typedef struct Nodo{
    int tope;
    TelementoP datos[MaxArray];
}Nodo;

typedef struct Nodo* p_pila;

void AgregaP(p_pila P,TelementoP x);

void QuitaP(p_pila P,TelementoP *x);

void IniciaP(p_pila P);

int VaciaP(Nodo P);

TelementoP ConsultaP(Nodo P);

void MuestraP(Nodo P);




