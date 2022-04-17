#include "IntPilasD.h"

int main(){

    TelementoP string1[MAX]; //char[9] string1
    p_nodo pila1;

    IniciaP(&pila1);
    FILE* arch = fopen("DNI.txt","r");
    if(!arch){
        printf("Error en la apertura del archivo\n");
        return 1;
    }

    do{
        if(fgets(string1,MAX,arch)){
            Apila(&pila1,string1);
        }
    }while(!feof(arch));

    fclose(arch);

    return 0;
}
