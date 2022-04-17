/*!3. Implementar un programa que cree dinámicamente 3 variables enteras,
 muestre su suma y su producto.
Asegurarse de administrar correctamente la memoria e implementar funciones para
evitar duplicaciones de código.
*/

#include <stdio.h>
#include <stdlib.h>

void ingresoDatos(int *v1,int *v2,int *v3);
int suma(int *v1,int *v2,int *v3);
int producto(int *v1,int *v2,int *v3);

int main(){

    int *v1,*v2,*v3;

    v1 = (int*)malloc(sizeof(int));
    v2 = (int*)malloc(sizeof(int));
    v3 = (int*)malloc(sizeof(int));

    ingresoDatos(v1,v2,v3); //v1,v2,v3 contiene pos. de memoria HEAP

    printf("\nLa suma total de las 3 variables es: %d\n",suma(v1,v2,v3));

    printf("\nEl producto entre las 3 variables es: %d\n\n",producto(v1,v2,v3));

    free(v1);
    free(v2);
    free(v3);


    return 0;
}

void ingresoDatos(int *v1,int *v2,int *v3){

printf("Ingrese datos: ");
printf("\nVariable 1: "); scanf("%d",v1);
printf("\nVariable 2: "); scanf("%d",v2);
printf("\nVariable 3: "); scanf("%d",v3);

}

int suma(int *v1,int *v2,int *v3){

    int sum=0;

    sum = *v1+*v2+*v3;

    return sum;
}

int producto(int *v1,int *v2,int *v3){

    int prod;

    prod = *v1**v2**v3;

    return prod;

}
