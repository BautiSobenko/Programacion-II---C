//Implementacion Cola Circular
#include "IntColaCirc.h"

void IniciarC(TCola *C){
    C->pri = -1;
    C->ult = -1;
}

int VaciaC(TCola C){
    return (C.pri == -1);
}
//Formula para conocer cuantos elementos
//tiene mi cola circular:
//max - inicio + final + 1

int Elementos(TCola C){
    if(VaciaC(C))
        return 0;
    else
        if(C.pri <= C.ult)
            return C.ult-C.pri+1;
        else
            if(C.pri >= C.ult)
                return max - C.pri + C.ult + 1;

}

int LlenaC(TCola C){
    if(Elementos(C) == MAX)
        return 1;
    else
        return 0;
}

void poneC (TCola *C, TElementoC X) {
    if(!LlenaC(*C)){
        if(VaciaC(*C))
            C->pri = 0;

        if(C->ult == MAX-1) //Si llega al tope de la cola
            C->ult = 0;     //Se reinicia y vuelve a 0
        else
            C->ult++;// Si no se llega al tope,incremento el ultimo.

        C->datos[C->ult] = X;
    }else
        printf("La cola esta llena\n");
}

void sacaC (TCola *C, TElementoC *X) {
    if(!VaciaC(*C)){
        *X = C->datos[C->pri];
    if (C->pri == C->ult) //Solo existe 1 elemento en cola
        iniciaC(C);
    else                  //Existen multiples elementos en cola
        if (C->pri == MAX-1)
            C->pri = 0;
        else
            C->pri++;
    }else
        printf("La cola esta vacia\n");
}

