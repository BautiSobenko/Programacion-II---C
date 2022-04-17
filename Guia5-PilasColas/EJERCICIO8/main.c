#include "IntPila.h"
#define MAX 20

void CargaPilas(p_nodo *p1,p_nodo *p2,TelementoP *n1,TelementoP *n2);

void Pila3Suma(p_nodo *p1,p_nodo *p2,p_nodo *p3);

void MostrarP3(p_nodo p3);

void VaciaPilas(p_nodo *p1,p_nodo *p2,p_nodo *p3);

int main(){

    p_nodo p1,p2,p3;
    TelementoP n1[MAX],n2[MAX];

    CargaPilas(&p1,&p2,n1,n2);

    MuestraP(p1);  printf("\n");
    MuestraP(p2);  printf("\n");

    Pila3Suma(&p1,&p2,&p3);

    MostrarP3(p3);

    //Vacia pila
    VaciaPilas(&p1,&p2,&p3);

    printf("|%d| - |%d| - |%d|",VaciaP(p1),VaciaP(p2),VaciaP(p3));

    return 0;
}

void CargaPilas(p_nodo *p1,p_nodo *p2,TelementoP *n1,TelementoP *n2){

    int i;

    IniciaP(p1);
    IniciaP(p2);

    printf("Ingrese los valores de: \n");
    printf("Numero 1: ");scanf("%s",n1);
    printf("Numero 2: ");scanf("%s",n2);


    for(i=0; i<strlen(n1); i++){
        Apila(p1,n1[i]);
    }
    for(i=0; i<strlen(n2); i++){
        Apila(p2,n2[i]);
    }
}

void Pila3Suma(p_nodo *p1,p_nodo *p2,p_nodo *p3){

    int x=0,y=0,suma=0,carry=0;
    char a,b;
    IniciaP(p3);

    while(!VaciaP(*p1) || !VaciaP(*p2)){
        if(!VaciaP(*p1)){
            Desapila(p1,&a);
            x = a - '0'; //Conv char to int
        }else
            x = 0;

        if(!VaciaP(*p2)){
            Desapila(p2,&b);
            y = b - '0';
        }else
            y = 0;

        suma = x + y + carry;
        carry = suma/10;
        //carry = 1 || 0

        if(suma>=10){
            Apila(p3,suma-10);
            if(!*p1)
                Apila(p3,carry);
        }else
            Apila(p3,suma);

        }
    }

void MostrarP3(p_nodo p3){

    if(p3){
        printf("%d\n",p3->dato);
        MostrarP3(p3->sig);
    }else
        printf("NULL");
    return 0;
}

void VaciaPilas(p_nodo *p1,p_nodo *p2,p_nodo *p3){

    p_nodo aux;

    while(!VaciaP(*p1)){
        aux = *p1;
        *p1 = (*p1)->sig;
        free(aux);
    }

    while(!VaciaP(*p2)){
        aux = *p2;
        *p2 = (*p2)->sig;
        free(aux);
    }

    while(!VaciaP(*p3)){
        aux = *p3;
        *p3 = (*p3)->sig;
        free(aux);
    }

    *p1 = NULL;
    *p2 = NULL;
    *p3 = NULL;
}
