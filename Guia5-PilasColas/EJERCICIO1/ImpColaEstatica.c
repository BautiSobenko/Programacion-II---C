typedef int TElementoC;

typedef struct TCola{
     TElementoC datos[50];
     int pri, ult;
}TCola

void IniciaC (TCola *C) {
    (*C).pri=-1;
    (*C).ult=-1;
}

int VaciaC(TCola C){
    return C.pri==-1;
}

void poneC (TCola *C, TElementoC X) {
     if ((*C).ult != 49) {
        if ((*C).pri==-1)
             (*C).pri = 0;
        (*C).datos[++((*C).ult)]=X;
 }
}
void sacaC (TCola *C, TElementoC *X) {
     if ((*C).pri != -1) { // !vaciaC(*C)
        *dato = (*C).datos[(*C).pri];
     if ((*C).pri == (*C).ult)
        iniciaC(C);
     else
        (*C).pri +=1;
    }
}
TElementoC consultaC (TCola C){
if (C.pri !=-1)
    return C.dato[C.pri];
}
