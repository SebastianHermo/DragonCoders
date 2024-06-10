#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"

Materia *obtenerMateriasNoInscriptas(Alumno *alumno);
Materia *buscarMateria(Materia *materias, char *nombreMateria);
int buscarAlumno(Alumno *listaAlumnos, char *nombre);

// Dar de alta un Alumno
void altaAlumno(Alumno *lista, char *alumno, int edad)
{
    Alumno *nuevo = (Alumno *)malloc(sizeof(Alumno));
    nuevo->nombre = (char *)malloc(strlen(alumno) + 1);
    strcpy(nuevo->nombre, alumno);
    nuevo->edad = edad;
    nuevo->materias = NULL;
    nuevo->proximo = NULL;

    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        Alumno *actual = lista;
        while (actual->proximo != NULL)
        {
            actual = actual->proximo;
        }
        actual->proximo = nuevo;
    }
}

// Dar de alta una materia
void altaMateria(Materia *lista, char *materia)
{
    Materia *nuevo = (Materia *)malloc(sizeof(Materia));
    nuevo->nombre = (char *)malloc(strlen(materia) + 1);
    strcpy(nuevo->nombre, materia);
    nuevo->proximo = NULL;
    nuevo->estado = 0;
    nuevo->nota = 0;
    nuevo->regularidad = 0;

    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        Materia *actual = lista;
        while (actual->proximo != NULL)
        {
            actual = actual->proximo;
        }
        actual->proximo = nuevo;
    }
}

// Dar de baja a un Alumno
void bajaAlumno(Alumno *lista, char *alumno)
{
    if (lista == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    Alumno *actual = lista;
    Alumno *anterior = NULL;

    while (actual != NULL && strcmp(actual->nombre, alumno) != 0)
    {
        anterior = actual;
        actual = actual->proximo;
    }

    if (actual == NULL)
    {
        printf("No se encontró el alumno %s\n", alumno);
        return;
    }

    if (anterior == NULL)
    {
        lista = actual->proximo;
    }
    else
    {
        anterior->proximo = actual->proximo;
    }

    free(actual->nombre);
    free(actual);
}

// dar de baja una Materia
void bajaMateria(Materia *lista, char *materia)
{
    if (lista == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    Materia *actual = lista;
    Materia *anterior = NULL;

    while (actual != NULL && strcmp(actual->nombre, materia) != 0)
    {
        anterior = actual;
        actual = actual->proximo;
    }

    if (actual == NULL)
    {
        printf("No se encontró el alumno %s\n", materia);
        return;
    }

    if (anterior == NULL)
    {
        lista = actual->proximo;
    }
    else
    {
        anterior->proximo = actual->proximo;
    }

    free(actual->nombre);
    free(actual);
}

/*Modificar una materia en cuestion ya existente
 */
void modificarMateria(Materia *lista, char *nombre, char *nuevoNombre)
{
    if (lista == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    Materia *actual = lista;

    while (actual != NULL && strcmp(actual->nombre, nombre) != 0)
    {
        actual = actual->proximo;
    }

    if (actual == NULL)
    {
        printf("No se encontró la materia %s\n", nombre);
        return;
    }

    // Actualizar nombre de la materia
    if (nuevoNombre != NULL)
    {
        free(actual->nombre);
        actual->nombre = (char *)malloc(strlen(nuevoNombre) + 1);
        strcpy(actual->nombre, nuevoNombre);
    }
}

/*Modifica la materia del Alumno para que sea regular en dicha materia,
1 para ser regular, 0 para no serlo.
*/
void modificarMateriaAlumno(Alumno *listaAlumnos, char *nombreAlumno, char *nombreMateria, int regularidad)
{
    int indiceAlumno = buscarAlumno(listaAlumnos, nombreAlumno);

    if (indiceAlumno == -1)
    {
        printf("No se encontró el alumno %s\n", nombreAlumno);
        return;
    }

    Alumno *alumno = &listaAlumnos[indiceAlumno];

    Materia *materiaActual = alumno->materias;

    while (materiaActual != NULL && strcmp(materiaActual->nombre, nombreMateria) != 0)
    {
        materiaActual = materiaActual->proximo;
    }

    if (materiaActual == NULL)
    {
        printf("No se encontró la materia %s del alumno %s\n", nombreMateria, alumno->nombre);
        return;
    }

    // Actualizar regularidad de la materia
    if (regularidad == 0 || regularidad == 1)
    {
        materiaActual->regularidad = regularidad;
    }
    else
    {
        printf("La regularidad debe ser 0 (irregular) o 1 (regular)\n");
        return;
    }

    printf("Regularidad de la materia %s del alumno %s actualizada a %d (%s)\n",
           nombreMateria, alumno->nombre, regularidad,
           regularidad == 0 ? "irregular" : "regular");
}

/*Modificar algun alumno en particular ya existente,
  si no quieres editar los nuevos puedes dejarlos vacios
*/
void modificarAlumno(Alumno *lista, char *nombre, char *nuevoNombre, int nuevaEdad)
{
    if (lista == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    Alumno *actual = lista;

    while (actual != NULL && strcmp(actual->nombre, nombre) != 0)
    {
        actual = actual->proximo;
    }

    if (actual == NULL)
    {
        printf("No se encontró el alumno %s\n", nombre);
        return;
    }

    // Actualizar nombre del alumno
    if (nuevoNombre != NULL)
    {
        free(actual->nombre);
        actual->nombre = (char *)malloc(strlen(nuevoNombre) + 1);
        strcpy(actual->nombre, nuevoNombre);
    }

    // Actualizar edad del alumno
    if (nuevaEdad != -1)
    {
        actual->edad = nuevaEdad;
    }
}

// Lista de los alumnos de una materia especifica
void enlistarAlumnosRegulares(Alumno *listaAlumnos, char *nombreMateria)
{
    Alumno *actual = listaAlumnos;

    while (actual != NULL)
    {
        Materia *materiaActual = actual->materias;

        while (materiaActual != NULL)
        {
            if (strcmp(materiaActual->nombre, nombreMateria) == 0 && materiaActual->regularidad == 1)
            {
                printf("Alumno: %s\n", actual->nombre);
                break;
            }
            materiaActual = materiaActual->proximo;
        }
        actual = actual->proximo;
    }
}

// lista de alumnos anotados en la universidad
void enlistarAlumnos(Alumno *listaAlumnos)
{
    Alumno *actual = listaAlumnos;
    printf("Lista de alumnos:\n");
    while (actual != NULL)
    {
        printf("Alumno: %s\n", actual->nombre);
        actual = actual->proximo;
    }
}

// Buscar si el alumno esta dado de Alta
int buscarAlumno(Alumno *listaAlumnos, char *nombre)
{
    int indice = 0;
    Alumno *actual = listaAlumnos;

    while (actual != NULL)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            printf("El alumno %s está dado de alta.\n", nombre);
            return indice;
        }
        actual = actual->proximo;
        indice++;
    }
    printf("El alumno %s no está dado de alta.\n", nombre);
    return -1;
}

// Buscar el alumno por la edad y devolver los alumnos de dicha edad
void buscarAlumnoEdad(Alumno **lista, int edad)
{
    int encontrado = 0;
    printf("Alumnos de %d años:\n", edad);
    for (int i = 0; lista[i] != NULL; i++)
    {
        if (lista[i]->edad == edad)
        {
            printf("%s (%d años)\n", lista[i]->nombre, lista[i]->edad);
            encontrado = 1;
        }
    }
    if (!encontrado)
    {
        printf("No se encontraron alumnos de %d años.\n", edad);
    }
}

// Anotar un alumno que esta dado de alta en la materia
void agregarMateriaAlumno(Alumno *listaAlumnos, char *nombreAlumno)
{
    int indiceAlumno = buscarAlumno(listaAlumnos, nombreAlumno);

    if (indiceAlumno == -1)
    {
        printf("No se encontró el alumno %s\n", nombreAlumno);
        return;
    }
    Alumno *alumno = &listaAlumnos[indiceAlumno];

    Materia *materiasNoInscriptas = obtenerMateriasNoInscriptas(alumno);
    if (materiasNoInscriptas == NULL)
    {
        printf("El alumno %s ya está inscripto en todas las materias\n", nombreAlumno);
        return;
    }

    printf("Materias en las que no está inscripto el alumno %s:\n", nombreAlumno);
    for (Materia *materia = materiasNoInscriptas; materia != NULL; materia = materia->proximo)
    {
        printf("  %s\n", materia->nombre);
    }

    char nombreMateria[50];
    printf("Ingrese la materia que desea inscribirse: ");
    scanf("%49s", nombreMateria);

    Materia *materia = buscarMateria(materiasNoInscriptas, nombreMateria);
    if (materia == NULL)
    {
        printf("La materia %s no existe\n", nombreMateria);
        return;
    }

    // Agregar la materia al alumno
    if (alumno->materias == NULL)
    {
        // El alumno no tiene materias inscriptas
        alumno->materias = materia;
    }
    else
    {
        // El alumno tiene al menos una materia inscripta
        Materia *ultimaMateria = alumno->materias;
        while (ultimaMateria->proximo != NULL)
        {
            ultimaMateria = ultimaMateria->proximo;
        }
        ultimaMateria->proximo = materia;
    }

    modificarMateriaAlumno(listaAlumnos, nombreAlumno, nombreMateria, 1);
    printf("Alumno %s inscripto en la materia %s con regularidad\n", nombreAlumno, nombreMateria);
}

Materia *obtenerMateriasNoInscriptas(Alumno *alumno)
{
    Materia *materiasNoInscriptas = NULL;
    Materia *materiaActual = alumno->materias;

    while (materiaActual != NULL)
    {
        Materia *materiaSiguiente = materiaActual->proximo;
        materiaActual->proximo = materiasNoInscriptas;
        materiasNoInscriptas = materiaActual;
        materiaActual = materiaSiguiente;
    }

    return materiasNoInscriptas;
}

Materia *buscarMateria(Materia *materias, char *nombreMateria)
{
    for (Materia *materia = materias; materia != NULL; materia = materia->proximo)
    {
        if (strcmp(materia->nombre, nombreMateria) == 0)
        {
            return materia;
        }
    }
    return NULL;
}

// Edita la materia del alumno con respecto a sus notas.
void editarNotaDelAlumno(Alumno *listaAlumnos, char *nombreAlumno, char *nombreMateria, float nota)
{
    int indiceAlumno = buscarAlumno(listaAlumnos, nombreAlumno);

    if (indiceAlumno == -1)
    {
        printf("No se encontró el alumno %s\n", nombreAlumno);
        return;
    }

    Alumno *alumno = &listaAlumnos[indiceAlumno];
    Materia *cursor = alumno->materias;
    while (cursor != NULL && strcmp(cursor->nombre, nombreMateria) != 0)
    {
        cursor = cursor->proximo;
    }

    if (cursor != NULL)
    {
        cursor->nota = nota;
        if (cursor->regularidad == 1)
        {
            if (nota > 4)
            {
                cursor->estado = 1; // Aprobado
            }
            else
            {
                cursor->estado = 0; // No aprobado
            }
        }
    }
    else
    {
        printf("La materia no existe.\n");
    }
}

// Imprime las materias que tiene un alumno junto a sus detalles
void imprimirMateriasDelAlumno(Alumno *listaAlumnos, char *nombreAlumno)
{
    int indiceAlumno = buscarAlumno(listaAlumnos, nombreAlumno);

    if (indiceAlumno == -1)
    {
        printf("No se encontró el alumno %s\n", nombreAlumno);
        return;
    }

    Alumno *alumno = &listaAlumnos[indiceAlumno];

    printf("Materias del alumno %s:\n", alumno->nombre);

    Materia *cursor = alumno->materias;
    while (cursor != NULL)
    {
        printf("  %s - Nota: %.2f - Regularidad: %s - Estado: %s\n",
               cursor->nombre, cursor->nota,
               cursor->regularidad == 0 ? "Irregular" : "Regular",
               cursor->estado == 0 ? "No aprobado" : "Aprobado");
        cursor = cursor->proximo;
    }
}

void imprimirMaterias(Materia *lista)
{
    while (lista != NULL)
    {
        printf("%s", lista->nombre);
        lista = lista->proximo;
        if (lista != NULL)
        {
            printf(", ");
        }
    }
    printf("\n");
}