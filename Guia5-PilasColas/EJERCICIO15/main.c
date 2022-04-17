#include <stdio.h>
#include <stdlib.h>

/*
El mazo representa a la pila.
Cada jugador tomara la carta
del tope del mazo
*/

typedef Carta TelementoP;

typedef struct Carta{
    int numero;
    char palo;
}Carta;

void LlenaMazo(TPila *mazo);

void BorraPilas(TPila *p1,TPila *p2);

int main(){

    TPila mazo,p1,p2;
    TelementoP carta;
    int turno=0; //contador de turno
    int puntos1=0,puntos2=0;

    LlenaMazo(&mazo);

    //Reparto cartas
    SacaP(&mazo,&carta);
    while(!VaciaP(mazo)){
        turno++;
        if(turno%2 != 0){ //Turnos impares
            PoneP(&p1,carta);
            if(carta.palo == p1->sig->dato.palo){
                puntos1 += 2*carta.numero;
            }else
                puntos1 += carta.numero;
        }else
            PoneP(&p2,carta);
            if(carta.palo == p2->sig->dato.palo){
                puntos2 += 2*carta.numero;
            }else
                puntos2 += carta.numero;

        SacaP(&mazo,&carta);
    }
    printf("\nJuego finalizado,mazo vacio.\n");

    BorraPilas(&p1,&p2);
    return 0;
}

void LlenaMazo(TPila *mazo){

    TelementoP carta;
    FILE* arch = fopen("mazo.txt","rt");
    if(arch)
        printf("Error en la apertura del archivo\n");

    fscanf(arch,"%d %c",&carta.numero,&carta.palo);
    while(!feof(arch)){
        Apila(mazo,carta); //Almaceno el struct completo
        fscanf(arch,"%d %c",&carta.numero,&carta.palo);
    }
    fclose(arch);
}

void BorraPilas(TPila *p1,TPila *p2){

    TelementoP aux;
    while(!Vacia(*p1)){
        SacaP(p1,&aux);
    }
    while(!Vacia(*p2)){
        SacaP(p2,&aux);
    }

}
