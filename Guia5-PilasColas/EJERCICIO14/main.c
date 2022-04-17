#include "IntPilla.h"
#include "IntCola.h"

void CargaCompetidores(Cola *c1);

void CargaPila(Cola *c1,p_nodo *p1);

int main(){

    Cola c1;
    p_nodo p1;

    CargaCompetidores(&c1);

    MostrarC(c1);

    //CargaPila(&c1,&p1);

    return 0;
}

void CargaCompetidores(Cola *c1){

    TelementoC Comp;

    FILE* arch = fopen("Competidores.txt","rt");
    if(!arch)
        printf("Error en la apertura del archivo\n");

    IniciaC(c1);

    fscanf(arch,"%s %s",Comp.Apellido,Comp.Nombre);
    while(!feof(arch)){
        AgregaC(c1,Comp);
        fscanf(arch,"%s %s",Comp.Apellido,Comp.Nombre);
    }
}


void CargaPila(Cola *c1,p_nodo *p1){

    TelementoC aux;
    p_nodo Paux = *p1;
    while(!VaciaP(Paux)){
        Paux->dato.Qcomp=0;
        Paux = Paux->sig;
    }
}


    /*while(!VaciaC(*c1)){
        Desapila(c1,&aux);
        BusquedaEnPila(p1,aux);



    }

}

void BusquedaEnPila(p_nodo *p1,TelementoC aux){

    p_nodo Paux = *p1;
    TelementoP data;
    while(!VaciaP(Paux) && aux.Apellido[0]!=Paux->dato.inicial){
        Paux = Paux->sig;
    }
    if(VaciaP(Paux)){
        data.inicial = aux.Apellido[0];
        data.ids[++data.Qcomp] = aux.Nombre;
    }

}*/
