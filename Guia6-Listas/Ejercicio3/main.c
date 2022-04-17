#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CONSTANTES
#define MAX 20

///DEFINICION DE TIPO LISTA
typedef struct Nodo{
    char nombre[MAX];
    int cont;
    struct Nodo* sig;
}Nodo;

typedef struct Nodo* TLista;

///PROTOTIPOS

void GeneraLista(TLista *L);

void MuestraLista(TLista L);

int main(){

    TLista L = NULL;

    GeneraLista(&L);

    MuestraLista(L);

    return 0;
}

void GeneraLista(TLista *L){

    TLista nuevo, ant, act;
    char nomb[MAX];
    FILE* arch = fopen("ejercicio3.txt","rt");
    if(!arch){
        printf("Error al abrir el archivo\n");
    }
    fscanf(arch,"%s",nomb);
    while(!feof(arch)){
        ant = NULL;
        act = *L;
        if(*L == NULL || strcmp(nomb,act->nombre)<0){ /// INSERCION EN CABEZA
            nuevo = (TLista)malloc(sizeof(Nodo));
            nuevo->cont = 0;
            (nuevo->cont)++;
            strcpy(nuevo->nombre,nomb);
            nuevo->sig =*L; //Vinculo nodos
            *L = nuevo;
            }else{
                while(act != NULL && strcmp(nomb,act->nombre)>0){ // Alg. Busqueda
                    ant = act;
                    act = act->sig;
                }
                if(act == NULL || strcmp(nomb,act->nombre)<0){ ///INSERCION FIN/CUERPO DE LISTA
                    nuevo = (TLista)malloc(sizeof(Nodo));
                    strcpy(nuevo->nombre,nomb);
                    nuevo->cont = 0;
                    (nuevo->cont)++;
                    nuevo->sig = act;
                    ant->sig = nuevo;
                }else if(strcmp(nomb,act->nombre)==0){ ///NOMBRE IGUAL A ALGUNO DE LA LISTA
                    (act->cont)++;
                }
            }
        fscanf(arch,"%s",nomb);
    }
    close(arch);
}



void MuestraLista(TLista L){

    TLista aux = L;
    while(aux != NULL){
        printf("Nombre: %s // Apariciones: %d\n",aux->nombre,aux->cont);
        aux = aux->sig;
    }
}

