#include <stdio.h>
#include <string.h>

/*strcmp(Cadena1,Cadena2);
Compara 2 cadenas de texto caracter a caracter.
Igual que cadena 2 --> n=0
Mayor que cadena 2 --> n>0
Menor que cadena 2 --> n<0
*/

int main(){
    char claveSecreta[] = "clave";
    char claveUsuario[128];
    int intentosRestantes = 3;

    do{
        printf("Ingrese su clave: ");
        fflush(stdin);
        scanf("%s",&claveUsuario);

        if(strcmp(claveUsuario,claveSecreta)==0){
            printf("\nBienvenido/a!");
            break;
        }else{
            intentosRestantes--;
            printf("\nClave ingresada incorrecta, le quedan %d intentos\n\n",intentosRestantes);
        }

    }while(intentosRestantes>0);

    (intentosRestantes==0)? puts("#ACCESO BLOQUEADO#"):printf(" :) \n");

    return 0;
}
