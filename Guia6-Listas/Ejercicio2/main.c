#include <stdio.h>
#include <stdlib.h>

///DEFINICION TIPO LISTA

typedef struct Nodo{
  char dato;
  struct Nodo* sig;
}Nodo;

typedef struct Nodo* Tlista;

///PROTOTIPOS

void MuestraLista(Tlista L);

void CantVocales(Tlista L,int *q);

void ListaOrdenada(Tlista *L, int *f);

void EliminaEnP(Tlista *L, int p);

void IngresoPorCabeza(Tlista *L,char n);

///PROGRAMA PRINCIPAL

int main(){

    Tlista L = NULL;
    int q=0; //cont. vocales
    int f;  //flag
    int p;  //ubicacion
    char c; //caracter para lectura

    FILE* arch = fopen("ejercicio2.txt","rt");
    if(!arch){
        printf("error al abrir el archivo");
        return 1;
    }

    fscanf(arch,"%c",&c);
    while(!feof(arch)){
        IngresoPorCabeza(&L,c);
        fscanf(arch," %c",&c);
    }

    MuestraLista(L);

    CantVocales(L,&q);
    printf("\nCantidad de vocales: %d\n",q);

    ListaOrdenada(&L,&f);
    (f==1)?printf("\nLista ordenada!\n"):printf("\nLista desordenada!\n");

    printf("\nIngrese ubicacion P: ");
    scanf("%d",&p);
    printf("\n\n");
    EliminaEnP(&L,p);

    MuestraLista(L);

    close(arch);


    return 0;
}

///FUNCIONES

void MuestraLista(Tlista L){

    Tlista aux=L;

    while(aux != NULL){
        printf("%c\n",aux->dato);
        aux=aux->sig;
    }
}

void CantVocales(Tlista L, int *q){

    Tlista aux=L;
    while(aux != NULL){
        if(aux->dato=='a' ||
           aux->dato=='e' ||
           aux->dato=='i' ||
           aux->dato=='o' ||
           aux->dato=='u')
            (*q)++;
		aux = aux->sig;
	}
}

void ListaOrdenada(Tlista *L, int *f){

    Tlista aux = *L;
    while( aux->sig != NULL && aux->dato < aux->sig->dato)
        aux = aux->sig;
    if(aux->sig==NULL)
        *f = 1;
    else
        *f = 0;
}

void EliminaEnP(Tlista *L, int p){

    Tlista act=*L;
    Tlista ant=NULL;
    int cont=1;
    if(p==1){ //Modifico la cabeza
        *L = (*L)->sig;
        free(act);
    }else{
        while(act != NULL){
            if(cont != p){
                ant = act;
                act = act->sig;
                cont++;
            }else{
                ant->sig = act->sig;
                free(act);
                act = NULL;
            }
        }
    }
}

void IngresoPorCabeza(Tlista *L,char c){

    Tlista nuevo;
    nuevo = (Tlista)malloc(sizeof(Nodo));
    nuevo->dato = c;
    nuevo->sig = *L;
    *L = nuevo;
}
