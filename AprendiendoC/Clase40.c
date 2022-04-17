#include <stdio.h>

int main(){

    int c;

    FILE *Arch;

    Arch = fopen("Arch1.txt","rt");

    if(Arch==NULL){
        printf("Error en el acceso al archivo");
        return 1;
    }

    while((c=fgetc(Arch))!=EOF){
        if(c=='\n'){
            printf("\n");
        }else{
            putchar(c);
        }
    }

    fclose(Arch);

    return 0;
}
