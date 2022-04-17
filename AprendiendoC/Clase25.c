//APUNTADORES II

#include <stdio.h>

int main(){

    int numero = 50;
    int *pNumero; //Creamos apuntado al numero

    //Mostramos dato por pantalla
    printf("Dato: %i\n",numero);

    //Mostramos posicion en memoria del dato
    //Obs. que se utiliza %p --> (posicion)
    printf("Dato: %p\n\n",&numero);

    pNumero = &numero;

    //Mostramos dato por pantalla
    printf("Dato: %i\n",numero);

    //Mostramos dato por pantalla
    //Hacemos uso del puntero
    //El puntero "apunta" a la posicion en memoria del dato
    printf("Dato: %i\n\n",*pNumero);


    return 0;
}
