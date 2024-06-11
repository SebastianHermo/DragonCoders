#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef STRUCT_H
#define STRUCT_H

// Estructura de nodo para el alumno
typedef struct Alumno
{
    char *nombre;
    int edad;
    struct Materia *materias; // lista de materias individuales
    struct Alumno *proximo;
} Alumno;

// Estructura de nodo para la materia
typedef struct Materia
{
    char *nombre;
    int estado; // 0 = no aprobado, 1 = aprobado
    float nota;
    int regularidad; // 0 = irregular, 1 = regular
    struct Materia *proximo;
} Materia;

#endif