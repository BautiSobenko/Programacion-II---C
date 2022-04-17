#include <stdio.h>

int main(){

    FILE *Archivo = fopen("prueba.txt","a");
    //"a" Escritura al final del doc. "append" = "añadir"

    if(Archivo == NULL){ // NULL == Memoria nula
        printf("Error al intentar crear/acceder al archivo\n");
    }else{
        char texto[] = "Soy bauti";
        fprintf(Archivo,"%s",texto);
    }
    fclose(Archivo);

    return 0;
}
