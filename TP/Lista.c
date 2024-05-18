#include <stdio.h>
#include <malloc.h>

typedef struct structNodo {
    struct structNodo proximo;
} Nodo;

Alta(Nodo **lista) {

    //if esAlumno || esMateria{
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Nodo *cursor = *lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
    }

   
//}

Baja(){
   // if esAlumno || esMateria{

   // }

}

modificar(){
    //if esAlumno || esMateria{
        
    //}

}

enlistarAlumnos(){

}

buscarAlumno(){

}

buscarAlumnoEdad(){

}

anotarseEnLaMateria(alumno, materia){

}

rendirMateria(){

}