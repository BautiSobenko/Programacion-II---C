#include <stdio.h>

int main(){

    int i;

    puts("Ingrese un dia de la semana: ");
    scanf("%d",&i);

    switch(i){
    case 1: printf("Lunes!");
    break;
    case 2: printf("Martes!");
    break;
    case 3: printf("Miercoles!");
    break;
    case 4: printf("Jueves!");
    break;
    case 5: printf("Viernes!");
    break;
    case 6: printf("Sabado!");
    break;
    case 7: printf("Domingo!");
    break;
    default: printf("WHATTTS");
    }


    return 0;
}
