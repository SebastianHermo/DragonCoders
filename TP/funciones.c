#include <stdio.h>
#include <string.h>
#include "struct.h"


// Función para dar de alta a un alumno
void altaAlumno(ListaDeAlumnos *lista, char *nombreAlumno, int edad) {
    if (lista == NULL) {
        printf("Error: la lista no está inicializada\n");
        return;
    }

    Alumno *nuevoAlumno = NewAlumno(nombreAlumno, edad);
    if (nuevoAlumno == NULL) {
        printf("Error: no se pudo asignar memoria para el alumno\n");
        return;
    }

    NodoAlumno *node = NewNodoAlumno(nuevoAlumno);
    if (node == NULL) {
        printf("Error: no se pudo asignar memoria para el nodo\n");
        free(nuevoAlumno->nombre);  // Liberar cadena duplicada
        free(nuevoAlumno);  // Liberar estructura Alumno
        return;
    }

    if (SizeofLista(lista) == 0) {
        lista->head = node;
        lista->tail = node;
    } else {
        lista->tail->prox = node;
        lista->tail = node;
    }
    lista->size++;
}

// Dar de baja a un Alumno
void bajaAlumno(ListaDeAlumnos *lista, char *alumno) {
    if (lista == NULL || lista->head == NULL) {
        printf("Error: La lista está vacía\n");
        return;
    }

    NodoAlumno *actual = lista->head;
    NodoAlumno *anterior = NULL;

    while (actual != NULL && (actual->datos == NULL || strcmp(actual->datos->nombre, alumno) != 0)) {
        anterior = actual;
        actual = actual->prox;
    }

    if (actual == NULL) {
        printf("Error: Alumno no encontrado\n");
        return;
    }

    if (anterior == NULL) {
        // El nodo a eliminar es el primero de la lista
        lista->head = actual->prox;
    } else {
        // El nodo a eliminar no es el primero
        anterior->prox = actual->prox;
    }
}

// Modificar algun alumno en particular ya existente
void modificarAlumno(ListaDeAlumnos *lista, char *nombre, char *nuevoNombre, int nuevaEdad) {

    if (!lista || !nombre || !nuevoNombre) {
        printf("Error: Alguno de los parámetros es inválido\n");
        return;
    }

    NodoAlumno *actual = lista->head;

    while (actual) {
        if (strcmp(actual->datos->nombre, nombre) == 0) {
            strncpy(actual->datos->nombre, nuevoNombre, sizeof(actual->datos->nombre) - 1);
            actual->datos->nombre[sizeof(actual->datos->nombre) - 1] = '\0';
            actual->datos->edad = nuevaEdad;
            return;
        }
        actual = actual->prox;
    }
    printf("Error: no se encontró el alumno con el nombre %s\n", nombre);

}

//Imprime un listado de los alumnos inscriptos
void enlistarAlumnos(ListaDeAlumnos *lista) {

    if (lista == NULL){
        printf("Error: La lista está vacía\n");
    }
    NodoAlumno *actual = lista->head;

    while (actual != NULL){
        printf("Alumno: %s\n", actual->datos->nombre);
        actual = actual->prox;
    }

    printf("\n");

}

// Buscar si el alumno esta dado de Alta
// Buscar si el alumno esta dado de Alta
Alumno buscarAlumno(ListaDeAlumnos *lista, char *nombre) {

    Alumno *alumnoNoEncontrado = NULL;
    
    while (lista == NULL) {
        printf("Error: La lista está vacía\n");
        break;
    }

    NodoAlumno *actual = lista->head;

    while (actual != NULL) {
        if (actual->datos != NULL && strcmp(actual->datos->nombre, nombre) == 0) {
            return *actual->datos;
        }
        actual = actual->prox;
    }

    return *alumnoNoEncontrado;
}


// Buscar el alumnos por edad y devolverlos
void buscarAlumnosPorEdad(ListaDeAlumnos *lista, int edad) {

    if (lista == NULL){
        printf("Error: La lista está vacía\n");
        return;
    }

    int encontrados = 0;
    int i = 0;
    NodoAlumno *actual = lista->head;

    printf("Alumnos de %d años son:\n", edad);

    while (i < (lista->size)){
        if (actual->datos->edad == edad){
            printf("%s (%d años)\n", actual->datos->nombre, actual->datos->edad);
        }
        actual = actual->prox;
        encontrados++;
        i++;
    }

}



//                 Funciones de materias                 



// Dar de alta una materia
void altaMateria(ListaDeMaterias *lista, char *nombre) {
    NodoMateria *node = NewNodoMateria(NewMateria(nombre));
    if (node == NULL) {
        printf("Error: No se pudo crear el nodo\n");
        return;
    }

    if (lista->size == 0) {
        lista->head = node;
        lista->tail = node;
    } else {
        lista->tail->prox = node;
        lista->tail = node;
    }
    lista->size++;
}

Materia *buscarMateria(ListaDeMaterias *lista, char *nombreMateria) {

    NodoMateria *materia = lista->head;
    while (materia != NULL) {
        if (strcmp(materia->datos->nombre, nombreMateria) == 0) {
            return materia->datos;
        }
        materia = materia->prox;
    }
    return NULL;
}

// Dar de baja una Materia
void bajaMateria(ListaDeMaterias *lista, char *nombreMateria) {

    if (lista == NULL || lista->head == NULL) {
        printf("Error: La lista está vacía\n");
        return;
    }

    Materia *actualM = buscarMateria(lista, nombreMateria);

    if (actualM == NULL) {
        printf("Error: No se encontró la materia en la lista\n");
        return;
    }

    NodoMateria *actual = lista->head;
    NodoMateria *anterior = NULL;

    while (actual != NULL && (actual->datos == NULL || strcmp(actual->datos->nombre, actualM->nombre) != 0)) {
        anterior = actual;
        actual = actual->prox;
    }

    if (lista->head == actual) {
        lista->head = actual->prox;
    } else {
        anterior->prox = actual->prox;
    }
}

// Modificar el nombre de una materia en cuestion ya existente
void modificarNombreMateria(ListaDeMaterias *lista, char *nombre, char *nuevoNombre) {
    if (lista == NULL || nombre == NULL || nuevoNombre == NULL) {
        printf("Error: Parámetros inválidos\n");
        return;
    }
    Materia *nodo = buscarMateria(lista, nombre);

    if (nodo == NULL) {
        printf("Error: No se encontró la materia con el nombre %s\n", nombre);
        return;
    }

    Materia *materiaAModificar = nodo;
    free(materiaAModificar->nombre);
    materiaAModificar->nombre = (char *) malloc((strlen(nuevoNombre) + 1) * sizeof(char));
    strcpy(materiaAModificar->nombre, nuevoNombre);
}

// Modificar el estado de aprobacio de una materia 1 = aprobado, 0 = desaprobado
void modificarEstadoMateria(ListaDeMaterias *lista, char *nombreAlumno, char *nombreMateria, int estado) {
    if (lista == NULL || nombreAlumno == NULL || nombreMateria == NULL || (estado < 0 || estado > 1)) {
        printf("Error: Parámetros inválidos\n");
        return;
    }
    Alumno alumnoAModificar = buscarAlumno(lista, nombreAlumno);
    NodoMateria *actual = alumnoAModificar.materias->head;

    while (actual->datos->nombre != NULL){
        if (actual->datos->nombre == nombreMateria){
            actual->datos->estado = estado;
            printf("El estado de la materia %s del alumno %s actualizada.\n",
                   nombreMateria, actual->datos->nombre);
            break;
        }
        *actual = *actual->prox;
    }

    printf("No se encontró la materia %s del alumno %s\n", nombreMateria, nombreAlumno);
}

// Modifica la materia del Alumno para que sea regular en dicha materia, 1 para ser regular, 0 para no serlo.
void modificarRegularidadAlumno(ListaDeAlumnos *lista, char *nombreAlumno, char *nombreMateria, int regularidad) {

    if (lista == NULL || nombreAlumno == NULL || nombreMateria == NULL || (regularidad < 0 || regularidad > 1)){
        printf("Error: Alguno de los parametros es incorrecto");
    }

    Alumno alumnoAModificar = buscarAlumno(lista, nombreAlumno);
    NodoMateria *actual = alumnoAModificar.materias->head;

    while (actual->datos->nombre != NULL){
        if (actual->datos->nombre == nombreMateria){
            actual->datos->regularidad = regularidad;
            printf("La regularidad de la materia %s del alumno %s actualizada.\n",
                   nombreMateria, actual->datos->nombre);
            break;
        }
        *actual = *actual->prox;
    }

    printf("No se encontró la materia %s del alumno %s\n", nombreMateria, nombreAlumno);
}

// Agrega una materia a la lista de materias de un alumno
void agregarMateriaAlumno(ListaDeAlumnos *lista, ListaDeMaterias *listaM, char *nombreAlumno, char *nombreMateria){

    if (listaM == NULL || lista == NULL || nombreAlumno == NULL || nombreMateria == NULL){
        printf("Error: Alguno de los parametros es invalido");
        return;
    }

    Alumno actual = buscarAlumno(lista, nombreAlumno);
    Materia *mActual = buscarMateria(listaM, nombreMateria);
    altaMateria(actual.materias, mActual);
}

// Lista de los alumnos de una materia especifica.
void enlistarAlumnosRegulares(ListaDeAlumnos *lista, char *nombreMateria) {

    if (lista == NULL) {
        printf("Error: La lista se encuentra vacia");
        return;
    }

    NodoAlumno *actual = lista->head;

    while (actual != NULL) {
        NodoMateria *actualM = actual->datos->materias->head;
        while (actualM != NULL) {
            if (actualM->datos->nombre == nombreMateria && actualM->datos->regularidad == 1) {
                printf("Los alumnos que poseen la materia %s regularizada son:\n", nombreMateria);
                printf("%s", actual->datos->nombre);
            }
            actualM = actualM->prox;
        }
        actual = actual->prox;
    }
}

// Edita la nota de un alumno en una de sus materias.
void editarNotaDelAlumno(ListaDeAlumnos *lista, char *nombreAlumno, char *nombreMateria, float nota) {

    if (lista == NULL) {
        printf("Error: La lista se encuentra vacía");
        return;
    }

    NodoAlumno *actual = lista->head;

    while (actual != NULL) {
        NodoMateria *actualM = actual->datos->materias->head;
        while (actualM != NULL) {
            if (actual->datos->nombre == nombreAlumno && actualM->datos->nombre == nombreMateria) {
                actualM->datos->nota = nota;
                printf("Se ha actualizado la nota de la materia %s.", nombreMateria);
                if (nota > 3) {
                    actualM->datos->regularidad = 1;
                    actualM->datos->estado = 1; // Aprobado
                } else {
                    actualM->datos->regularidad = 0;
                    actualM->datos->estado = 0;
                }
                return;
            }
            actualM = actualM->prox;
        }
        actual = actual->prox;
    }
}


// Imprime las materias que tiene un alumno junto a sus detalles.
void imprimirMateriasDelAlumno(ListaDeAlumnos *lista,char *nombreAlumno) {

    Alumno actual = buscarAlumno(lista, nombreAlumno);
    NodoMateria *actualM = actual.materias->head;

    while (actualM != NULL){
        printf("  %s - Nota: %.2f - Regularidad: %s - Estado: %s\n",
               actualM->datos->nombre, actualM->datos->nota, actualM->datos->regularidad == 0 ? "Irregular" : "Regular",
               actualM->datos->estado == 0 ? "No aprobado" : "Aprobado");
        actualM = actualM->prox;
    }
}
// Imprime el listado de las materias ingresadas.
void imprimirMaterias(ListaDeMaterias *lista) {
    if (lista == NULL || lista->head == NULL) {
        printf("Error: La lista se encuentra vacía.\n");
        return;
    }

    NodoMateria *actualM = lista->head;

    while (actualM != NULL) {
        if (actualM->datos != NULL && actualM->datos->nombre != NULL) {
            printf("%s\n", actualM->datos->nombre);
        }
        actualM = actualM->prox;
    }
}


//----------------------------------
