#include <stdio.h>
#include <string.h>

int main(){

    FILE* Archivo = fopen("Prueba.txt","r"); //"r" da privilegios de lectura
    int apariciones = 0;
    if (Archivo == NULL) //Si el archivo no existe
        printf("\nError al intentar acceder al archivo");
    else {
        char textoRecibido[1000];
        char palabraBuscada[] = "Buenos";
        while(fscanf(Archivo,"%s",textoRecibido)!= EOF){
            if(strcmp(textoRecibido,palabraBuscada)==0)
                apariciones++;
        }
    }
    fclose(Archivo);
    printf("Apariciones de la palabra: %d",apariciones);

    return 0;

}
