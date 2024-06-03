#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct structNodo
{
    struct structNodo proximo;
    char nombre;
}Materia;

typedef struct structNodo { 
    struct structNodo proximo;
    char alumno;
    int edad;
    Materia bool estado;
} Alumno;