typedef int TelementoP; //Defino tipo de elemento que contendra la pila

typedef struct Nodo{  //Definimos la estructura de un nodo
    TelementoP dato;
    struct Nodo* sig;
}Nodo;

typedef Nodo* TPila; //Pointer a estructura nodo

void IniciaP(TPila *P);

void Apila(TPila *P,TelementoP x);

void Desapila(TPila *P,TelementoP *x);

int VaciaP(TPila P);

TelementoP ConsultaP(TPila P);

void MuestraP(TPila P);

int LargoP(TPila P);

