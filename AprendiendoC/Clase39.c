#include <stdio.h>

struct{
char nombre[20];
char apellido[20];
char carrera[30];
}datos;

int main(){

    char rpt;

    FILE *Archivo = fopen("Arch1.txt","at"); //--> Lee y crea arch

    if(Archivo==NULL){
        printf("Error al intentar crear el archivo");
        return 1; //Termino MAL
    }

    printf("COMIENCE A AGENDAR!\n");

    do{
        fflush(stdin);
        printf("\nNombre: "); gets(datos.nombre);
        printf("\nApellido: "); gets(datos.apellido);
        printf("\nCarrera: "); gets(datos.carrera);

        fprintf(Archivo,"\n\nNombre: ");
        fwrite(datos.nombre,sizeof(char),strlen(datos.nombre),Archivo);
        fprintf(Archivo,"\nApellido: ");
        fwrite(datos.apellido,sizeof(char),strlen(datos.apellido),Archivo);
        fprintf(Archivo,"\nCarrera: ");
        fwrite(datos.carrera,sizeof(char),strlen(datos.carrera),Archivo);

        printf("Desea seguir agregando alumnos: Si (s) // No (n) ");
        scanf("%c",&rpt);

    }while(rpt=='s'); //'si'

    fclose(Archivo);


    return 0;
}
