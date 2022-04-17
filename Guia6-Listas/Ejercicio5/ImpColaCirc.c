#include "IntCola.h"

void IniciarC(TCola *C){
    C->pri = -1;
    C->ult = -1;
}

int VaciaC(TCola C){
    return (C.pri == -1);
}


void poneC (TCola *C, TelementoC X) {
 if (!((*C).ult==49 && (*C).pri==0 || (*C).ult+1==(*C).pri)) {
    if ((*C).pri==-1){
     (*C).pri = 0;
     (*C).ult = 0;
    }
    else
     if (*C).ult == 49)
      (*C).ult = 0;
     else
      (*C).ult += 1;
 (*C).datos[(*C).ult]=X;
 }
}
void sacaC (TCola *C, TelementoC *X) {
 if ((*C).pri != -1) {
 *X = (*C).datos[(*C).pri];
 if ((*C).pri == (*C).ult)
 iniciaC(C);
 else
 if (*C).pri == 49)
 (*C).pri = 0;
 else
 (*C).pri += 1;
 }
}



