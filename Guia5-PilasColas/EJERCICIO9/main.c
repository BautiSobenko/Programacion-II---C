#include "IntPila.h"
#define MaxE 20

void DatosPila(p_nodo *p1,p_nodo *p2);

void Comprobacion(p_nodo p1,p_nodo p2);

void LiberaHeap(p_nodo *p1,p_nodo *p2);

int main(){

    p_nodo p1,p2;

    DatosPila(&p1,&p2);

    MuestraP(p1);
    printf("\n");
    MuestraP(p2);
    printf("\n\n");

    Comprobacion(p1,p2);

    LiberaHeap(&p1,&p2);

    return 0;
}

void DatosPila(p_nodo *p1,p_nodo *p2){

    TelementoP exp[MaxE];
    int i;
    IniciaP(p1);
    IniciaP(p2);

    printf("Ingrese una expresion matematica que posea parentesis\n");
    scanf("%s",exp);

    for(i=0; i<strlen(exp); i++){
        if(exp[i]=='(')
            Apila(p1,exp[i]);
        if(exp[i]==')')
            Apila(p2,exp[i]);
    }
}

void Comprobacion(p_nodo p1,p_nodo p2){

     if(LargoP(p1)>LargoP(p2))
        printf("Falta de parentesis derecho\n");
    else
        if(LargoP(p1)<LargoP(p2))
            printf("Falta de parentesis izquierdo\n");
        else
            printf("Parentesis balanceados\n");
}

void LiberaHeap(p_nodo *p1,p_nodo *p2){

    p_nodo pAux;

    while(!VaciaP(*p1)){
        pAux = *p1;
        *p1 = (*p1)->sig;
        free(pAux);
    }

    while(!VaciaP(*p2)){
        pAux = *p2;
        *p2 = (*p2)->sig;
        free(pAux);
    }


}
