#include <stdio.h>
#include <malloc.h>

typedef struct structNodo {
    int valor;
    struct structNodo *proximo;
} Nodo;


Alta(Nodo *lista, int valor) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;
    if (lista == NULL) {
        lista = nuevoNodo;
    } else {
        Nodo *cursor = lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
    return lista;
}

Baja(){

}

modificar(){

}

eliminar(){

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









/*
int main(void) {
    Nodo *lista = NULL;

    lista = agregar(lista, 1);
    lista = agregar(lista, 2);
    lista = agregar(lista, 3);
    lista = agregar(lista, 4);

    printf("%d\n", lista->valor);
    printf("%d\n", lista->proximo->valor);
    printf("%d\n", lista->proximo->proximo->valor);
    printf("%d\n", lista->proximo->proximo->proximo->valor);
}*/