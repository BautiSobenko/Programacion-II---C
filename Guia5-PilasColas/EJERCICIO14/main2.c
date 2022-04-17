#include <stdio.h>
#include <stdlib.h>

typedef id TelementoC;
typedef id TelementoP;

typedef struct id{
    char nombre[];
    char apellido[];
}id;

void GeneraCola(TCola *comp);


int main(){

    TCola comp;
    TPila ident;
    TelementoC competidor;
    IniciaP(&ident);
    GeneraCola(&comp);

    competidor.apellido="000"; //Control
    PoneC(&comp,competdidor);

    SacaC(&comp,competidor);
    PoneP(&ident,competidor);
    inicial = competidor.apellido[0];

    while(!VaciaC(comp)){
        if(comp.(datos.apellido[0]) != 0){
           if(inicial != comp.(datos.apellido[0])){
                SacaC(&comp,competidor);
                PoneC(&comp,competidor);
           }else{
                SacaC(&comp,competdor);
                PoneP(&ident,competidor);
           }
        }else{
             SacaC(&comp,competidor);
             PoneC(&comp,competidor);

             SacaC(&comp,competidor);
             PoneP(&ident,competidor);
             inicial = competidor.apellido[0];
        }
        if(!comp->sig)
            SacaC(&comp,competidor);
    }

    return 0;
}

void GeneraCola(TCola *comp){

    TelementoC competidor;
    FILE* arch = fopen("comp.txt","rt");
    if(!arch)
        printf("Error en la apertura del archivo");

    IniciaC(comp);
    fscanf(arch,"%s %s",&competidor.nombre,&competidor.apellido);
    while(!feof(arch)){
        PoneC(comp,competidor);
        fscanf(arch,"%s %s",&competidor.nombre,&competidor.apellido);
    }
    fclose(arch);
}
