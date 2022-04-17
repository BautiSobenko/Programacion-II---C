Implementacion(Pila)

Pila
    int tope;
    Lista elementos;// --> Cuantos elementos
                    //    metemos en la lista

Pila crearPila()
    Pila P;
    Lista lista1;
    p.tope = 0;
    p.elementos = lista1;
    return p;

---------------------------

Implementacion(isEmpty)

bool esVacio(Pila p)

    if(p.tope==0) // --> Pila vacia
        return true;
    return false;

---------------------------
Implementacion(push)

void meter(Pila p, (T.dato) x)

    p.elementos[p.tope] = x;
    p.tope = p.tope+1;

---------------------------
Implementacion(pop)

int sacar(Pila p)

    if(esVacia(p))
        printf("Error")
        return -1
    else
        int aux = p.elementos[p.tope] //--> Guardo el elemento del tope
        p.elementos[p.tope] == NULL //--> Eliminamos tope
        p.tope = p.tope-1 // --> Un indice menor
        return aux;

----------------------------
Implementacion(top)

int top(Pila p)
    if (esVacio(p))
        printf("Error")
        return -1
    else
        return p.elementos[p.tope]

