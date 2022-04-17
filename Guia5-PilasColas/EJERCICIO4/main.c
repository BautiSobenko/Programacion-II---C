#include "InterfaceCola.h"

int main(){

    Cola Cola1;
    IniciaC(&Cola1);
    FILE* Arch = fopen("EJ4.txt","rt");
    if(!Arch){
        printf("\nError en la apertura del archivo\n");
        return 1;
    }else
        printf("\nArchivo encontrado con exito\n");

    int x;
    fscanf(Arch,"%d",&x);

    while(!feof(Arch)){
        AgregaC(&Cola1,x);
        fscanf(Arch,"%d",&x);
    }
    MostrarC(Cola1);

    QuitarC(&Cola1,&x);
    QuitarC(&Cola1,&x);
    QuitarC(&Cola1,&x);
    QuitarC(&Cola1,&x);
    QuitarC(&Cola1,&x);

    MostrarC(Cola1);

    printf("Ultimo elemento de la cola %d",ConsultaC(Cola1));

    if(VaciaC(Cola1)){
        printf("\nLa cola se encuentra vacia.\n");
    }else
        printf("\nLa cola NO se encuentra vacia.\n");

    LiberarC(&Cola1);

    if(VaciaC(Cola1)){
        printf("\nLa cola se encuentra vacia.\n");
    }else
        printf("\nLa cola NO se encuentra vacia.\n");



    return 0;
}
