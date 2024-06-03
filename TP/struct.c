#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct structNodo{
    struct structNodo proximo;
    char nombre [100];
    bool estado;
} Materia;

typedef struct structNodo { 
    struct structNodo proximo;
    char nombre [100];
    int edad;
} Alumno;
