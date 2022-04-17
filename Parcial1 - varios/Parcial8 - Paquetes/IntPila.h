
typedef struct TPaq{
  char nombreZona[2];
  int codPaq;
  char destinatario[20];
  float alto,largo,peso;
}TPaq;

typedef TPaq TelementoP; //Defino tipo de elemento que contendra la pila

///Pila estatica

#define MAX 40

typedef struct  TPila{
  TelementoP datos[MAX];
  int tope;
}TPila;

typedef Nodo* TPila; //Pointer a estructura nodo

///Prototipos

void IniciaP(TPila *P);

void Apila(TPila *P,TelementoP x);

void Desapila(TPila *P,TelementoP *x);

int VaciaP(TPila P);

TelementoP ConsultaP(TPila P);

void MuestraP(TPila P);

int LargoP(TPila P);

