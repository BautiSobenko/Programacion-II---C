#include "InterfaceCola.h"

void Pares(Cola *Cola1);

int main(){

    Cola Cola1;

    IniciaC(&Cola1);

    FILE* Arch = fopen("EJCOLA.txt","r");
    if(!Arch){
        printf("Error en la apertura del archivo\n");
        return 1;
    }

    int d;//d->dato

    fscanf(Arch,"%d",&d);

    while(!feof(Arch)){
        AgregaC(&Cola1,d);
        fscanf(Arch,"%d",&d);
    }
    MostrarC(Cola1);

    printf("\n%d\n",LargoC(Cola1));

    Pares(&Cola1);

    printf("\n\n");
    MostrarC(Cola1);
    printf("\n\n");

    fclose(Arch);
    LiberarC(&Cola1);

    return 0;
}

void Pares(Cola *Cola1){

    int x,cont=1,largoCola=LargoC(*Cola1);
    QuitarC(Cola1,&x);
    while(cont<=largoCola){
        if(x%2==0 && x!=0)
            AgregaC(Cola1,x);
        QuitarC(Cola1,&x);
        cont++;
    }
}

