#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.c"

//Dar de alta un Alumno
altaAlumno(Alumno **lista,char alumno ,int edad ) {
    Alumno *nuevoNodo = malloc(sizeof(Alumno));
    nuevoNodo->proximo = NULL;
    if (*lista == NULL) {
        *lista = nuevoNodo;
        nuevoNodo ->alumno = alumno;
        nuevoNodo ->edad = edad;
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
altaMateria(Materia **lista, char materia ) {
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
bajaAlumno(Alumno **lista, char alumno){
    Alumno *cursor = *lista;
    Alumno *cursor2 = cursor;

    while (cursor->proximo->alumno != alumno && cursor->proximo != NULL) {
        cursor = cursor->proximo;
    }
    if (cursor->proximo->alumno == alumno && cursor->proximo->proximo != NULL){
        cursor2 = cursor->proximo;
        cursor->proximo = cursor->proximo->proximo;

    } else if (cursor->proximo->proximo == NULL && cursor->proximo->alumno == alumno){
        cursor = cursor->proximo;
        cursor2 = cursor;       
        cursor = NULL;
    }
        
        free(cursor2);
    }

//dar de baja una Materia
bajaMateria(Materia **lista, char materia){
Materia *cursor = *lista;
Materia *cursor2 = cursor;
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
        
        free(cursor2);
    }

//Modificar una materia en cuestion
modificarMateria(Materia **lista, char materia){
    
}

//Modificar algun alumno en particular
modificarAlumno(Alumno **lista, char materia){

}

//Hacer una lista de los alumnos de la materia
enlistarAlumnos(Alumno **lista){
    
}

//Buscar si el alumno esta dado de Alta
buscarAlumno(Alumno **lista, char alumno){

}

//Buscar el alumno por la edad
buscarAlumnoEdad(Alumno **lista, int edad){

}

//Anotar un alumno que esta dado de alta en la materia
anotarseEnLaMateria(Alumno **alumnos, Materia **materias,char alumno ,char materia){

}

rendirMateria(Alumno **alumnos, Materia **materias, char alumno, char materia){

}