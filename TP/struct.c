#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct NodoMateria {
    struct NodoMateria *proximo;
    char* nombre;
    bool estado;
} Materia;

typedef struct NodoAlumno {
    struct NodoAlumno *proximo;
    char* nombre;
    int edad;
} Alumno;
