#ifndef STRUCT_H
#define STRUCT_H

#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// Estructura de nodo para el alumno
typedef struct structMateria Materia;
typedef struct structAlumno Alumno;
typedef struct structListaDeMaterias ListaDeMaterias;

typedef struct structAlumno
{
    char *nombre;
    int edad;
    ListaDeMaterias *materias; // lista de materias individuales
} Alumno;

Alumno *NewAlumno(char *nombre, int edad)
{
    Alumno *alumno = (Alumno *)malloc(sizeof(Alumno));
    alumno->nombre = (char *)malloc((strlen(nombre) + 1) * sizeof(char));
    strcpy(alumno->nombre, nombre);
    alumno->edad = edad;
    alumno->materias = NULL;
    return alumno;
}

typedef struct structNodoAlumno
{
    Alumno *datos;
    struct structNodoAlumno *prox;
} NodoAlumno;

NodoAlumno *NewNodoAlumno(Alumno *alumno)
{
    NodoAlumno *node;
    node = (NodoAlumno *)malloc(sizeof(NodoAlumno));
    node->datos = alumno;
    node->prox = NULL;
    return node;
}

//                  Struct de Materias

// Estructura de nodo para la materia
typedef struct structMateria
{
    char *nombre;
    int estado; // 0 = no aprobado, 1 = aprobado
    float nota;
    int regularidad; // 0 = irregular, 1 = regular
} Materia;

Materia *NewMateria(char *nombre)
{
    Materia *materia = (Materia *)malloc(sizeof(Materia));
    materia->nombre = (char *)malloc((strlen(nombre) + 1) * sizeof(char));
    strcpy(materia->nombre, nombre);
    materia->estado = 0;
    materia->nota = 0;
    materia->regularidad = 0;
    return materia;
}

typedef struct structNodoMateria
{
    Materia *datos;
    struct structNodoMateria *prox;
} NodoMateria;

NodoMateria *NewNodoMateria(Materia *materia)
{
    NodoMateria *node = (NodoMateria *)malloc(sizeof(NodoMateria));
    node->datos = materia;
    node->prox = NULL;
    return node;
}

typedef struct structListaDeAlumnos
{
    NodoAlumno *head;
    NodoAlumno *tail;
    int size;
} ListaDeAlumnos;

ListaDeAlumnos *NewListaDeAlumnos()
{
    ListaDeAlumnos *lista = (ListaDeAlumnos *)malloc(sizeof(ListaDeAlumnos));

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int SizeofLista(ListaDeAlumnos *lista)
{
    return lista->size;
}

// Lista de Materias

typedef struct structListaDeMaterias
{
    NodoMateria *head;
    NodoMateria *tail;
    int size;
} ListaDeMaterias;

ListaDeMaterias *NewListaDeMaterias()
{
    ListaDeMaterias *list = (ListaDeMaterias *)malloc(sizeof(ListaDeMaterias));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int SizeOfMaterias(ListaDeMaterias *list)
{
    return list->size;
}

#endif // STRUCT_H