#include "InterfaceColas.h"

int main()
{
    int N,i=0;
    Cola Cola1;
    TelementoC string1[MAX];

    IniciaC(&Cola1);
    FILE* arch = fopen("DNI.txt","rt");
    if(!arch){
        printf("Error al intentar abrir el archivo\n");
        return 1;
    }
    do{
        fscanf(arch,"%s",string1);
        Encolar(&Cola1,string1);
    }while(!feof(arch));

    printf("Ingrese N: ");
    scanf("%d",&N);

    while(i<N && !VaciaC(Cola1)){
        Desencolar(&Cola1,string1);
        puts(string1);
        i++;
    }

    return 0;
}
