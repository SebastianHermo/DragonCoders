#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.c"

//Dar de alta un Alumno
altaAlumno(Alumno **lista) {
    Alumno *nuevoNodo = malloc(sizeof(Alumno));
    nuevoNodo->proximo = NULL;
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Alumno *cursor = *lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
}

//Dar de alta una Materia
altaMateria(Materia **lista) {
    Materia *nuevoNodo = malloc(sizeof(Materia));
    nuevoNodo->proximo = NULL;
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Materia *cursor = *lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
}

//Dar de baja a un Alumno
bajaAlumno(Alumno **Lista, alumno char){}

//dar de baja una Materia
bajaMateria(Materia **Lista, materia char)

//Modificar una materia en cuestion
modificarMateria(Materia **Lista, materia char){}

//Modificar algun alumno en particular
modificarAlumno(Alumno **Lista, materia char){}

//Hacer una lista de los alumnos de la materia
enlistarAlumnos(Alumno **Lista){}

//Buscar si el alumno esta dado de Alta
buscarAlumno(Alumno **Lista, alumno char){}

//Buscar el alumno por la edad
buscarAlumnoEdad(Alumno **Lista, edad int){}

//Anotar un alumno que esta dado de alta en la materia
anotarseEnLaMateria(Alumno **alumnos, Materia **materias,  alumno char, materia char){}

rendirMateria(Alumno **alumnos, Materia **materias, alumno char){}