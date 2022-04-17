#include <stdio.h>

int main(){

    char nombre[20], signo[20];

    puts("Ingrese su nombre");
    gets(nombre);
    puts("\nIngrese su signo");
    gets(signo);

    if(strcmp(signo,("Aries"))==0 || strcmp(signo,("aries"))==0 )
        printf("\nSu nombre es: %s",nombre);
    else
        printf("\nNo es signo Aries");

    return 0;
}
