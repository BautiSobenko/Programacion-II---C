//Apuntadores o punteros

/*

Cuando una variable se declara se asocian 3 tipos de atributo:
1)Tipo de dato
2)Nombre
3)Direccion en memoria

Para conocer la direccion en memoria de una variable:
int numero = 3;

printf("%d",&numero);

El & me permite dirigirme hacia la direccion en memoria

APUNTADOR: Variable que contiene la posicion en memoria de una variable

El puntero apunta al espacio fisico de una variable

*/

int hola = 100;

int *phola; --> Declaramos el puntero, pero no lo estamos dirigiendo
                hacia ningun lugar

int *phola = &hola; --> Almacena la posicion en memoria de la variable hola

