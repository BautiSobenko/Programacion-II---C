//Dados 2 enteros
//Sumarlos, restarlos, multiplicarlos y dividirlos

#include <stdio.h>

int main(){

    float n1,n2,suma,resta,mult,div;

    printf("Ingrese 2 numeros (n1) y (n2): ");
    scanf("%f %f",&n1,&n2);

    suma = n1+n2;
    resta= n1-n2;
    mult = n1*n2;
    div  = n1/n2;

    printf("\nResultados:\nSuma = %.2f\nResta = %.2f\nMultiplicacion = %.2f\nDivision = %.2f\n",suma,resta,mult,div);
    printf("\nGracias por usar el programa! \n");

    return 0;
}
