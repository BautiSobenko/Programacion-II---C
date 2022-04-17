#include <stdio.h>

#define PERIODO 60
#define INTERVALO 5

void GeneraBinario();

int main(){

    GeneraBinario();

    return 0;
}

void GeneraBinario(){

    int mediciones = PERIODO/INTERVALO;
    float T;

    FILE* Arch = fopen("EJ24.DAT","wb+");

    //Analisis de mediciones de temperaturas en 1 min
    //Medicion cada 5 segundos

    if(!Arch){
        printf("Error en la apertura del archivo");
        return 1;
        //El return fuerza una salida inmediata a la funcion
        //1 es signo de un error dentro de la ejecucion
    }

    for(int i=1; i<=mediciones ;i++){
        printf("Temperatura %d: ",i);
        scanf("%f",&T);         //Debo forzar el float con la parte decimal 44.0!!!
        fwrite(&T,sizeof(float),1,Arch);
    }
}
