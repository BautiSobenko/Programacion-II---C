#include <stdio.h>

int main () {

    char e[40];
    //String (arreglo de chars)

    printf("Digite su nombre: ");
    gets(e);

    printf("Bienvenido/a %s\n",e);

    /*El scanf solo tomara hasta el
    primer espacio en blanco
      El gets tomara hasta el primer
    Enter*/

    return 0;
}
