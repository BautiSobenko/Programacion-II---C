#include <stdio.h>

int main(){
    int variable = 0;

    for(variable=0; variable<=20 ;variable+=2)
        continue; // Termina con el ciclo
    printf("\nVariable = %d",variable);


    /*printf("%d",i);
    esto dara error ya que
    la variable i se encuentra
    declarada dentro del bucle for*/

    return 0;

}
