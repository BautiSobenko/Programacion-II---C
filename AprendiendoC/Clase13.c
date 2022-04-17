#include <stdio.h>
#include <string.h>

/*strcat(Destino,Fuente);
Concatena la cadena fuente en el destino.
*/

int main(){

    char Cadena1[] = "Jorge", Cadena2[] = "Ricardo";
    char Final[50] = ""; // Inicializo con string nula ""

    //Concatenamos

    strcat(Final,Cadena1);
    strcat(Final,"-");
    strcat(Final,Cadena2);
    printf("%s",Final);

    return 0;
}
