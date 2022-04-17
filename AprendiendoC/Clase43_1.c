//! Free() en C

#include <stdio.h>
#include <stdlib.h>

int main(){

   int *p1;
   p1 = malloc(sizeof(int));

   if(p1 == NULL){
        printf("No hay espacio en memoria");
        return 1;
   }else{
        printf("Hay espacio disponible");
        *p1 = 15;
        printf("\n\n%d",*p1);
   }
    free(p1);
    printf("\n\n%d\n",*p1);
    //Observamos que arroja valores, completamente
    //randoms, lo que nos da a entender
    //que el procesador no esta encontrando nada
    //en la direccion de memoria indicada


    return 0;
}
