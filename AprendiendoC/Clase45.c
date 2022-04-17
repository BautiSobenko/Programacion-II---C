//!Diferencias entre calloc / malloc / realloc

#include <stdio.h>
#include <stdlib.h>

int main(){

    //(int*) es el cast
    //sin este cast malloc/calloc  devuelve
    //un pointer tipo VOID, sin esp. el tipo

    //!MALLOC
    int *hola = (int *)malloc(10*sizeof(int));
    /*Reserva en el heap 10 posiciones
    el espacio en memoria que reserva esta
    sin limpiar, tiene basura
    */

    //!CALLOC
    int *hola = (int*)calloc(10,sizeof(int));
    /*El espacio en memoria que reserva
    lo limpia completamente inicializandolo
    en cero
    */

    //!REALLOC
    int *hola = (int*)realloc(hola,20*sizeof(int));
    //Expande la memoria dinamica asignada

    free(hola);

    return 0;
}
