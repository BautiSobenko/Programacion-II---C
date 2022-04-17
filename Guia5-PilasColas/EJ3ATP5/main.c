#include "Interface.h"

int main()
{

    char s[20];

   Cola Colita;//Creo estructura cola

   IniciaC(&Colita); //Paso Colita por referencia

   printf("Ingrese DNI: ");
   gets(s);
   AgregaC(&Colita,s);

   MuestraC(Colita);

   free(&Colita);



   return 0;
}
