#include <stdio.h>
#include <math.h>

#define Tarifa1 "Basica" //100 - 499
#define Tarifa2 "Intermedia" //500 - 999
#define Tarifa3 "Premium" //1000 - 1500


int main(){
    float monto;
    int montoF;

    puts("Ingrese el monto que desea pagar");
    scanf("%f",&monto);
    printf("\nGracias!");

    montoF = round(monto);


    switch(montoF){
    case 100 ... 499:printf("\nTarifa: %s\n",Tarifa1);
    break;
    case 500 ... 999:printf("\nTarifa: %s\n",Tarifa2);
    break;
    case 1000 ... 1500:printf("\nTarifa: %s\n",Tarifa3);
    break;
    }


    return 0;
}
