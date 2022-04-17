typedef int posicion;

typedef struct nodoAN{
  posicion izq,der; //Enlace al padre y al hijo
  int dato;
}nodoAN;

typedef struct{
    int raiz;
    nodoAN nodos[100]; //Lista de nodos
} TArbolN;


void carga(TArbolN *AN); // Carga del N-ario para poder trabajar

int Nulo(posicion p);
posicion HijoMasIzq(posicion p, TArbolN AN);
posicion HermanoDer(posicion p, TArbolN AN);
int Vacio(TArbolN AN);
posicion Raiz(TArbolN AN);
int Info(posicion p, TArbolN AN);

