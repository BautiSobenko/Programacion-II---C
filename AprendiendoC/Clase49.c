//! Estructuras dinamicas

#include <stdio.h>
#include <stdlib.h>

struct rectangle{
int base;
int altura;
};

int main(){

    struct rectangle *p;

    p = (struct renctangle *)malloc(sizeof(struct rectangle));

    p -> base = 10;
    (*p).base = 10;
    p -> altura = 15;
    (p*).altura = 15;

    return 0;
}
