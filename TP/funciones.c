#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.c"

//Dar de alta un Alumno
altaAlumno(Alumno **lista, alumno char, edad int) {
    Alumno *nuevoNodo = malloc(sizeof(Alumno));
    nuevoNodo->proximo = NULL;
    if (*lista == NULL) {
        *lista = nuevoNodo;
        nuevoNodo ->alumno = alumno;
        nuevoNodo ->edad = edad;
    } else {
        Alumno *cursor = *lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
}

//Dar de alta una Materia
altaMateria(Materia **lista, materia char) {
    Materia *nuevoNodo = malloc(sizeof(Materia));
    nuevoNodo->proximo = NULL;
    nuevoNodo->nombre = materia;
    nuevoNodo->estado = false;
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
bajaAlumno(Alumno **Lista, alumno char){
Alumno *cursor = *lista;
Alumno *cursor2 = *cursor;
        while (cursor->proximo->nombre != alumno && cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        if (cursor->proximo->nombre == alumno && cursor->proximo->proximo != NULL){
            cursor2 = cursor->proximo;
            cursor->proximo = cursor->proximo->proximo;

        } else if (cursor->proximo->proximo == NULL && cursor->proximo->nombre == alumno)
        {
            cursor = cursor->proximo;
            cursor2 = cursor;       
            cursor = NULL;
        }
        
        free(cursor2)
    }

//dar de baja una Materia
bajaMateria(Materia **Lista, materia char){
Materia *cursor = *lista;
Materia *cursor2 = *cursor;
        while (cursor->proximo->nombre != materia && cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        if (cursor->proximo->nombre == materia && cursor->proximo->proximo != NULL){
            cursor2 = cursor->proximo;
            cursor->proximo = cursor->proximo->proximo;

        } else if (cursor->proximo->proximo == NULL && cursor->proximo->nombre == materia)
        {
            cursor = cursor->proximo;
            cursor2 = cursor;
            cursor = NULL;
        }
        
        free(cursor2)
    }

//Modificar una materia en cuestion
modificarMateria(Materia **Lista, materia char){
    
}

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

rendirMateria(Alumno **alumnos, Materia **materias, alumno char, materia char){}