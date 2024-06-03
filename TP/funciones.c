#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.c"

//Dar de alta un Alumno
void altaAlumno(Alumno **lista, char alumno, int edad) {
    Alumno *nuevoNodo = malloc(sizeof(Alumno));
    if (nuevoNodo == NULL) {
        // Manejar error: no se pudo asignar memoria
        printf("Error: no se pudo asignar memoria\n");
        return;
    }

    nuevoNodo->nombre = alumno;
    nuevoNodo->edad = edad;
    nuevoNodo->proximo = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Alumno *cursor = *lista;
        while (cursor->proximo!= NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
}

void altaMateria(Materia **lista, char materia) {
    Materia *nuevoNodo = malloc(sizeof(Materia));
    if (nuevoNodo == NULL) {
        // Manejar error: no se pudo asignar memoria
        printf("Error: no se pudo asignar memoria\n");
        return;
    }

    nuevoNodo->nombre = materia;
    nuevoNodo->estado = false;
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
void bajaAlumno(Alumno **lista, char alumno) {
    Alumno *cursor = *lista;

    // Verificar si el alumno a eliminar es el primero de la lista
    if (cursor != NULL && cursor->nombre == alumno) {
        Alumno *temp = cursor;
        *lista = cursor->proximo;
        free(temp);
        return;
    }

    // Buscar el alumno a eliminar en la lista
    while (cursor != NULL && cursor->proximo != NULL) {
        if (cursor->proximo->nombre == alumno) {
            Alumno *temp = cursor->proximo;
            cursor->proximo = cursor->proximo->proximo;
            free(temp);
            return;
        }
        cursor = cursor->proximo;
    }
}

//dar de baja una Materia
void bajaMateria(Materia **lista, char materia) {
    Materia *cursor = *lista;
    Materia *temp;

    // Verificar si la materia a eliminar es la primera de la lista
    if (cursor != NULL && cursor->nombre == materia) {
        temp = cursor;
        *lista = cursor->proximo;
        free(temp);
        return;
    }


    // Buscar la materia a eliminar en la lista
    while (cursor != NULL && cursor->proximo != NULL) {
        if (cursor->proximo->nombre == materia) {
            temp = cursor->proximo;
            cursor->proximo = cursor->proximo->proximo;
            free(temp);
            return;

        }
        cursor = cursor->proximo;
    }

}

//Modificar una materia en cuestion
void modificarMateria(Materia **lista, char materia){
Materia *cursor = *lista;

    while (cursor!= NULL && strcmp(cursor->nombre, materia)!= 0) {
        cursor = cursor->proximo;
    }   

    if (cursor!= NULL) {
        strcpy(cursor->nombre, materia);
    } else {
        printf("Materia no encontrada\n");
    }
    if (strcpy(cursor->nombre,materia) == 0)
    {
        char temp;
        printf("Ingrese su nombre: ");
        scanf("%s", temp);
        cursor->nombre = temp;
    }
    
}

//Modificar algun alumno en particular
void modificarAlumno(Alumno **lista, char materia){}

//Hacer una lista de los alumnos de la materia
void enlistarAlumnos(Alumno **lista){}

//Buscar si el alumno esta dado de Alta
void buscarAlumno(Alumno **lista, char alumno){}

//Buscar el alumno por la edad
void buscarAlumnoEdad(Alumno **lista, int edad){}

//Anotar un alumno que esta dado de alta en la materia
void anotarseEnLaMateria(Alumno **alumnos, Materia **materias, char alumno, char materia){}

void rendirMateria(Alumno **alumnos, Materia **materias, char alumno, char materia){}