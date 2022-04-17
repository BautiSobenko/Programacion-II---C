#define MAX 29 // Maximo 30 baldes disponibles
#define MAXF 8 // Caracteres maximo de fecha

typedef char* TElementoC; //string

typedef struct TCola{
    TElementoC datos[MAX]; //Arreglo de caracteres
    int pri;
    int ult;
}TCola;

void IniciaC(TCola *C);

void AgregaC(TCola *C,TElementoC x);

void QuitarC(TCola *C,TElementoC* x);

TElementoC ConsultaC(TCola C);

int VaciaC(TCola C);

void MostrarC(TCola C);

int LargoC(TCola C);

void LiberarC(TCola *C);










