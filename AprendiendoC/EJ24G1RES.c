#include <stdio.h>

#define PERIODO 60
#define INTERVALO 5

void LeeBinario();

void Maximo(float T,float* max);

void Minimo(float T,float* min);

int main(){

    LeeBinario();



    return 0;
}

void LeeBinario(){

    int mediciones = PERIODO/INTERVALO;
    int i;
    float T,SumaT=0,max,min;

    FILE* Arch = fopen("EJ24.DAT","rb");

    if(!Arch){
        printf("Error en la apertura del archivo");
        return 1;
    }

    fread(&T,sizeof(float),1,Arch);

    /*while(!feof(Arch)){
        printf("Temperatura %d: %f\n",i,T);
        fread(&T,sizeof(float),1,Arch);
    }*/

    max = 0;
    min = 100;

    for(i=1; i<=mediciones ;i++){
        fread(&T,sizeof(float),1,Arch);
        SumaT += T;
        Maximo(T,&max);
        Minimo(T,&min);
        printf("Temperatura %d: %f\n",i,T);
    }
    printf("\n.:INFORMACION ANALISIS DE TEMPERATURA:.\n");
    printf("\nMaximo:%f \n",max);
    printf("\nMinimo:%f \n",min);
    printf("\nPromedio: %f\n",SumaT/mediciones);

    fclose(Arch);
}

void Maximo(float T,float* max){
    if(T>*max)
        *max = T;
}

void Minimo(float T,float* min){
    if(T<*min){
        *min = T;
    }
}

