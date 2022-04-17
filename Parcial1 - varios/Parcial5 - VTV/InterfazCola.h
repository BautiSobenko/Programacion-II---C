typedef int TelementoC;

///Cola dinamica

typedef struct Nodo{
    TelementoC dato;
    struct Nodo* sig;
}Nodo;

typedef struct TCola{
    Nodo* primero;
    Nodo* ultimo;
}TCola;

///Prototipos

void IniciaC(TCola *C);

void PoneC(TCola *C,TelementoC x);

void SacaC(TCola *C,TelementoC *x);

TelementoC ConsultaC(TCola C);

int VaciaC(TCola C);

void MostrarC(TCola C);

int LargoC(TCola C);

void LiberarC(TCola *C);









