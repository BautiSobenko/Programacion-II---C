#include "InterfacePila.h"

void ParImpar(p_nodo aux,p_nodo* par,p_nodo* impar);

int main(){

    FILE* arch = fopen("EJ4.txt","r");
    if(!arch){
        printf("\nError en la apertura del archivo\n");
        return 1;
    }else
        printf("\nApertura del archivos exitosa\n");

    p_nodo Pila1;
    IniciaP(&Pila1);

    int x;
    fscanf(arch,"%d",&x);

    while(!feof(arch)){
        Apila(&Pila1,x);
        fscanf(arch,"%d",&x);
    }

    MuestraP(Pila1);

    p_nodo aux = Pila1;
    p_nodo par,impar,TopePar,TopeImpar;

    IniciaP(&par);
    IniciaP(&impar);
    IniciaP(&TopeImpar);
    IniciaP(&TopePar);

    ParImpar(aux,&par,&impar);

    printf("------\n");
    MuestraP(par);
    printf("------\n");
    MuestraP(impar);
    printf("------\n");

    x = PilaParImpar(aux);
    printf("\nSuma total de elementos de la pila = %d\n\n",x);
    if(x%2==0){
        Apila(&TopePar,Pila1->dato);
        printf("PILA PAR\n");
        MuestraP(TopePar);
    }
    else{
        Apila(&TopeImpar,Pila1->dato);
        printf("PILA IMPAR\n");
        MuestraP(TopeImpar);
    }

    free(Pila1);
    free(par);
    free(impar);
    free(TopePar);
    free(TopeImpar);
    fclose(arch);

    return 0;
}

void ParImpar(p_nodo aux,p_nodo* par,p_nodo* impar){

    while(!VaciaP(aux)){
        if((aux->dato)%2==0){
            Apila(par,aux->dato);
        }else
            Apila(impar,aux->dato);
        aux = aux->sig;
    }
}

int PilaParImpar(p_nodo aux){

    int sumaPila=0;
    while(!VaciaP(aux)){
        sumaPila += aux->dato;
        aux = aux->sig;
    }
    return sumaPila;

}




