
Nombre                   Función

fopen()                   Abre un archivo.
fclose()                  Cierra un archivo.
fgets()                   Lee una cadena de un archivo.
fputs()                   Escribe una cadena en un archivo
fseek()                   Busca un byte especifico de un archivo.
fprintf()                 Escribe una salida con formato en el archivo.
fscanf()                  una entrada con formato desde el archivo.
feof()                    Devuelve cierto si se llega al final del archivo.
ferror()                  Devuelve cierto si se produce un error.
rewind()                  Coloca el localizador de posición del archivo al principio del mismo.
remove()                  Borra un archivo.
fflush()                  Vacía un archivo.



//! Hay dos tipos de archivos, archivos de texto y archivos binarios.

//? Un archivo de texto es una secuencia de caracteres  organizadas  en  líneas
//? terminadas  por  un  carácter  de  nueva  línea.    En  estos  archivos  se pueden almacenar canciones,
//? fuentes de programas, base de datos simples, etc.
//? Los archivos de texto se caracterizan por ser  planos,  es  decir,  todas  las  letras  tienen
//? el  mismo  formato  y  no  hay  palabras  subrayadas,  en  negrita,  o  letras  de distinto tamaño o ancho.

//* Un archivo binario es una secuencia de bytes que tienen una correspondencia uno a uno con un dispositivo externo.
//* Así  que  no  tendrá  lugar  ninguna  traducción  de  caracteres.
//* Además,  el  número  de  bytes  escritos  (leídos) será el mismo que los encontrados en el dispositivo externo.
//* Ejemplos de estos archivos son Fotografías, imágenes, texto con formatos, archivos ejecutables (aplicaciones), etc.


