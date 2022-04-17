#include <stdio.h>

int main()
{
   int a,i,j;
   printf("Ingrese valor de A: ");
   scanf("%i", &a);
   printf("\n");

   for (i = 1; i <= a; i++)
   {
       printf("*");
   }
   printf("\n");


   for (i=1; i<=(a-2);i++)
   {
       printf("*");
       for (j=1; j<=(a-2);j++)
       {
       printf(" ");

       }
       printf("*\n");
   }

   for (i = 1; i <= a; i++)
   {
       printf("*");
   }

    return 0;
}
