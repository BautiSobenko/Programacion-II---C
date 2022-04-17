#include "IntCola.h"
#include "IntPila.h"

int main(){

    p_nodo Pila1;
    Cola Cola1;

    IniciaC(&Cola1);
    IniciaP(&Pila1);

    FILE* Arch = fopen("EJ13.txt","r");

    char c=fgetc(Arch);

    //fscanf(Arch,"%c",&c);

    while(c!=EOF){
        if(c>='a' && c<='z')
            AgregaC(&Cola1,c);
        c=fgetc(Arch);
    }

    Nodo* aux = Cola1.primero;
    while(aux){
        Apila(&Pila1,aux->dato);
        aux = aux->sig;
    }

    MuestraP(Pila1);

    MostrarC(Cola1);


    Nodo* AuxCola = Cola1.primero;
    p_nodo AuxPila = Pila1;


    int cont=0;

    for(int i=0;i<LargoP(Pila1);i++){
        if(AuxPila)
            if(AuxPila->dato==AuxCola->dato){
                cont++;
                AuxPila = AuxPila->sig;
                AuxCola = AuxCola->sig;
            }
    }
    if(cont==LargoP(Pila1)){
        printf("\nLa palabra es palindroma\n");
    }else
        printf("\nLa palabra NO es palindroma\n");

    fclose(Arch);
    free(&Pila1);
    LiberarC(&Cola1);

    return 0;
}
