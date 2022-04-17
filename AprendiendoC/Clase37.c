#include <stdio.h>

int main(){

    FILE *fd; //--> Pointer que det. si el file existe

    fd = fopen("prueba.txt","r"); //Modo "r" --> read

    if(fd==NULL){
        printf("El archivo no existe\n");
    }else{
        printf("El archivo existe\n");
    }



    return 0;
}
