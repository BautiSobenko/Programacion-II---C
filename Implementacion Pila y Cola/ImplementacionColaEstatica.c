#define MAX 50

typedef int TElementoC;

typedef struct TCola{
    TElementoC datos[MAX];
    int pri;
    int ult;
}TCola;

void IniciaC (TCola *C) {
    (*C).pri=-1;
    (*C).ult=-1;
}

int VaciaC(TCola C){
    return C.pri==-1;
}

int LlenaC(TCola C){
    if(C.ult == MAX-1){
        return 1;
    }else
        return 0;
}

void poneC (TCola *C, TElementoC X) {
    if(!LlenaC(*Cola)){
        if(VaciaC(*Cola)){
            (*C).pri = 0;
        }
        (*C).datos[++((*C).ult)] = X;
    }else
        printf("La cola esta llena\n");
}


void sacaC (TCola *C, TElementoC *X) {
    if(!VaciaC(*Cola)){
        if(C->pri == C->ult)
            IniciaC(C);
        else{
            *X = C->datos[C->pri];
            C->pri++;
        }
    }else
        printf("La cola esta vacia\n");
}
