#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct NodoMateria {
    struct NodoMateria *proximo;
    char nombre[100];
    bool estado;
} Materia;

typedef struct NodoAlumno {
    struct NodoAlumno *proximo;
    char nombre[100];
    int edad;
} Alumno;
