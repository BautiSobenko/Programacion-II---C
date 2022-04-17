#include "InterfazPila.h"

int main(){

    char c;
    TPila pila1;
    //Creo una estructura de pila estatica
    //Pila1.datos[x]
    //Pila.tope
    IniciaP(&pila1);

    FILE* arch = fopen("CaracteresEj2.txt","r");
    if(!arch){
        printf("Error en la apertura del archivo\n");
        return 1;
    }

    fscanf(arch,"%c",&c);

    while(!feof(arch)){
        if(c>='a' && c<='z')
            poneP(&pila1,c);
        fscanf(arch,"%c",&c);
    }

    //Mostrar contenido de la pila
    printf("\n");

    //MuestraP(pila1);

    MuestraPRec(pila1);

    fclose(arch);

return 0;
}
