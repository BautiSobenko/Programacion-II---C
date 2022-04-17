#include <stdio.h>
#include <string.h>

//strcpy(Destino,Fuente);

int main(){

    char Origen[] = "Programacion";

    char Destino[12];

    strcpy(Destino,Origen);
    printf("%s",Destino);



    return 0;
}
