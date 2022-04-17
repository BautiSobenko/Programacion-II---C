#include <stdio.h>

void menu();
void suma();
void resta();
void mult();
void div();
void mod();

int main(){

    menu();

    return 0;
}

void menu(){

    int opcion;

    do{
        printf("Ingresa una opcion\n");
        puts("1. Suma");
        puts("2. Resta");
        puts("3. Multiplicacion");
        puts("4. Division");
        puts("5. Modulo");
        puts("0. SALIR");
        printf("--> ");
        scanf("%d",&opcion);

        switch(opcion){
        case 1: suma();
        break;
        case 2: resta();
        break;
        case 3: mult();
        break;
        case 4: div();
        break;
        case 5: mod();
        break;
        default: puts("Opcion seleccionada invalida\n");
        }

    }while(opcion!=0);
}

void suma(){


    int a,b;

    printf("Ingresa 2 numeros enteros: ");
    fflush(stdin);
    scanf("%d %d",&a,&b);

    printf("%d + %d = %d\n\n",a,b,a+b);
}
void resta(){

    int a,b;

    printf("Ingresa 2 numeros enteros: ");
    fflush(stdin);
    scanf("%d %d",&a,&b);


    printf("%d - %d = %d\n\n",a,b,a-b);
}
void mult(){

    int a,b;

    printf("Ingresa 2 numeros enteros: ");
    fflush(stdin);
    scanf("%d %d",&a,&b);


    printf("%d * %d = %d\n\n",a,b,a*b);
}
void div(){

    int a,b;
    float div;

    printf("Ingresa 2 numeros enteros: ");
    fflush(stdin);
    scanf("%d %d",&a,&b);

    div = (float)a/b;

    printf("%d / %d = %.2f\n\n",a,b,div);
}
void mod(){

    int a,b;

    printf("Ingresa 2 numeros enteros: ");
    fflush(stdin);
    scanf("%d %d",&a,&b);


    printf("%d mod %d = %d\n\n",a,b,a%b);
}
