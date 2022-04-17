#include <stdio.h>
#include <stdlib.h>

///CONSTANTES

#define MAX 9

///TIPO LISTA

typedef struct Nodito{
    char fecha[MAX];
    float importe;
    struct Nodito* sig;
}Nodito;

typedef struct Nodito* SubLista;

typedef struct Nodo{
    int num;
    float totCred;
    float deuda;
    SubLista sub;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TListaC;

///PROTOTIPOS

void NuevoPago(TListaC*,int,char*,float);

void CancelaPago(TListaC*,int,char*);

void ElimnarCliente(TListaC *Lc,int cliente);

int main(){

    TListaC Lc;
    int cliente;
    char fecha[MAX];
    float imp;

    NuevoPago(&Lc,cliente,fecha,imp);
    CancelaPago(&Lc,cliente,fecha);
    EliminarCliente(&Lc,cliente);




    return 0;
}

void NuevoPago(TListaC *Lc,int cliente, char* fecha,float imp){

    //Se que el cliente existe


    TListaC actC = *Lc;
    SubLista actS = Lc->sub;
    SubLista antS = NULL;
    SubLista nuevoS;

    while(actC->num != cliente){ //Se que el cliente esta en mi lista
        actC = actC->sig;        //Recorro lista
    }
    if((actC->deuda)-imp <= 0){ ///DEUDA SALDADA
        *Lc = *Lc->sig;
        free(actC);
    }else{                      ///DEUDA NO SALDADA
        if(actS == NULL || strcmp(fecha,actS->fecha)>0){ ///INSERCION EN CABEZA     ///NO HAY PAGO REGISTRADO
            nuevoS = (SubLista)malloc(sizeof(Nodito));
            nuevoS->importe = 0;
            nuevoS->importe += imp;
            strcpy(nuevoS->fecha, fecha);
            nuevoS->sig = actS;
            actC->sub = nuevoS;      //Desplazo la cabeza
            actC->deuda -= imp;      //Actualizo deuda
        }else{
             if(strcmp(fecha,actS->fecha)==0){ ///FECHA COINCIDENTE
                actS->importe += imp;
                actC->deuda -= imp;
            }
        }
    }
}

void CancelaPago(TListaC *Lc,int cliente,char *fecha){

    TListaC actC = *Lc;
    TListaC antC = NULL;
    SubLista actS = *Lc->sub;
    SubLista antS = NULL;

    while( actC != NULL && cliente > actC->num ){
        antC = actC;
        actC = actC->sig;
    }
    if(actC->num = cliente){
        if(strcmp(fecha,actS->fecha)==0){
            *Lc->sub = *Lc->sub->sig;
            *Lc->deuda += actS->importe;
            free(actS);
        }else{
            while( actS != NULL && strcmp(fecha,actS->fecha)<0){
                antS = actS;
                actS = actS->sig;
            }
            if(actS != NULL){
                antS = actS->sig;
                *Lc->deuda += actS->importe;
                free(actS);
            }
        }
    }
}

void EliminarCliente(TListaC *Lc,int cliente){

    TListaC antC = NULL;
    TListaC actC = *Lc;
    if(*Lc != NULL)
        if( actC->num == cliente){
            *Lc = *Lc->sig;
            free(actC);
        }
        else{
            while( actC != NULL && actC->num<cliente){
                antC = actC;
                actC = actC->sig;
        }
            if(act != NULL && actC->num == cliente ){
                antC->sig = actC->sig;
                free(actC);
            }
        }

}
