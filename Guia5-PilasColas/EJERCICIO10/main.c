#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void Muestra(tcola *c);
void Carga(tcola *c);

int main(){
    Cola c;
    int cont;
    IniciaC(&c);
    Carga(&c);
    Muestra(&c);
    return 0;
}

void Carga(tcola *c){

    TelementoC x;
    FILE* arch = fopen("g5eje10.txt","r");
    if(!arch)
        printf("no se lee");
    fscanf(arch,"%d",&(x.id));
    fscanf(arch,"%d",&(x.ts));
    fscanf(arch,"%d",&(x.td));
    Ponec(c,x);           //ENCOLA LA ESTRUCTURA X COMPLETA
    fscanf(arch,"\n");
    while (feof(arch)==0){
        fscanf(arch,"%d",&(x.id));
        fscanf(arch,"%d",&(x.ts));
        fscanf(arch,"%d",&(x.td));
        Ponec(c,x);
        fscanf(arch,"\n");
    }
    fclose(arch);
    }

void Muestra(tcola*c){

    telementoc x;
    int suma=0,cont=0;
    while(!Vaciac(*c)){
        Sacac(c,&x);
        cont=cont+1;
        suma=suma+x.td;
        printf("%d ",x.id);
        printf("%d ",x.ts);
        printf("%d ",x.td);
        printf("\n");
    }
    printf("%d",suma/cont);
 }
