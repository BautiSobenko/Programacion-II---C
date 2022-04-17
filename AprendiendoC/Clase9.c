#include <stdio.h>

int main(){

    int desap;

    puts("Cuantas materias desaprobaste?");
    scanf("%d",&desap);

    (desap<=3)? printf("Pasaste de anio!\nAdeudas %i\n",desap): puts("Debes Recursar");

    return 0;
}
