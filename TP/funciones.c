#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.c"

Alta(Alumno **lista) {

    //if esAlumno || esMateria{
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