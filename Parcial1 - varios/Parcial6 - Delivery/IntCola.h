
typedef struct TPedido{
  char codComercio[3];
  unsigned int idPedido;
  int autPago;
  float importe;
}TPedido;

typedef TPedido TelementoC;

#define MAX 40

typedef struct TCola{
    TelementoC datos[MAX];
    int pri;
    int ult;
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









