#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "struct.c"

//Dar de alta un Alumno
void altaAlumno(Alumno **lista, char* alumno, int edad) {
    Alumno *nuevoNodo = malloc(sizeof(Alumno));
    if (nuevoNodo == NULL) {
        printf("Error: no se pudo asignar el estudiant  e\n");
        return;
    }

    nuevoNodo->nombre = malloc(strlen(alumno) + 1);
    if (nuevoNodo->nombre == NULL) {
        printf("Error: no se pudo asignar memoria para el nombre del estudiante\n");
        free(nuevoNodo);
        return;
    }
    strcpy(nuevoNodo->nombre, alumno);

    nuevoNodo->edad = edad;
    nuevoNodo->proximo = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
    Alumno *cursor = *lista;
    Alumno *ultimo = NULL;
    while (cursor != NULL) {
        ultimo = cursor;
        cursor = cursor->proximo;
    }
    if (ultimo != NULL) {
        ultimo->proximo = nuevoNodo;
    } else {
        *lista = nuevoNodo;
    }
    }
}

//Dar de alta una materia
void altaMateria(Materia **lista, char* materia) {
    Materia *nuevoNodo = malloc(sizeof(Materia));
    if (nuevoNodo == NULL) {
        printf("Error: no se pudo asignar la materia\n");
        return;
    }

    nuevoNodo->nombre = malloc(strlen(materia) + 1);
    if (nuevoNodo->nombre == NULL) {
        printf("Error: no se pudo asignar memoria para el nombre de la materia\n");
        free(nuevoNodo);
        return;
    }
    strcpy(nuevoNodo->nombre, materia);

    nuevoNodo->estado = 0;
    nuevoNodo->proximo = NULL;
    nuevoNodo->nota = 0;
    nuevoNodo->regularidad = 0;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
    Materia *cursor = *lista;
    Materia *ultimo = NULL;
    while (cursor != NULL) {
        ultimo = cursor;
        cursor = cursor->proximo;
    }
    if (ultimo != NULL) {
        ultimo->proximo = nuevoNodo;
    } else {
        *lista = nuevoNodo;
    }
    }
}

//Dar de baja a un Alumno
void bajaAlumno(Alumno **lista, char* alumno) {
            Alumno *cursor = *lista;

            // Verificar si el alumno a eliminar es el primero de la lista
            if (cursor != NULL && strcmp(cursor->nombre, alumno) == 0) {
                Alumno *temp = cursor;
                (*lista) = cursor->proximo;
                free(temp->nombre); // Liberar memoria del nombre del alumno
                free(temp);
                return;
            }

    // Buscar el alumno a eliminar en la lista
    while (cursor!= NULL && cursor->proximo!= NULL) {
    if (cursor->proximo!= NULL && strcmp(cursor->proximo->nombre, alumno) == 0) {
        if (cursor->proximo!= NULL) {
            Alumno *temp = cursor->proximo;
            cursor->proximo = cursor->proximo->proximo;
            free(temp->nombre); // Liberar memoria del nombre del alumno
            free(temp);
            return;
        }
    }
    cursor = cursor->proximo;
}
}

//dar de baja una Materia
void bajaMateria(Materia **lista, char* materia) {
    Materia *cursor = *lista;
    Materia *temp;

    // Verificar si la materia a eliminar es la primera de la lista
    if (cursor != NULL && strcmp(cursor->nombre, materia) == 0) {
        temp = cursor;
        *lista = cursor->proximo;
        free(temp);
        return;
    }

    // Buscar la materia a eliminar en la lista
    while (cursor != NULL) {
    if (strcmp(cursor->nombre, materia) == 0) {
        temp = cursor;
        cursor = cursor->proximo;
        free(temp->nombre); // Liberar memoria del nombre de la materia
        free(temp); // Liberar memoria de la estructura Materia
        return;
    } else {
        cursor = cursor->proximo;
    }
}
}       

//Modificar una materia en cuestion ya existente
void modificarMateria(Materia **lista, char *materia) {
Materia *cursor = *lista;

while (cursor!= NULL && strcmp(cursor->nombre, materia)!= 0) {
     cursor = cursor->proximo;
}

if (cursor!= NULL) {
    printf("Ingrese el nuevo nombre de la materia: ");
    char nuevoNombre[50];
    scanf("%49s", nuevoNombre);
    strcpy(cursor->nombre, nuevoNombre);
    } else {
        printf("La materia no existe.\n");
    }
}

//Modificar algun alumno en particular ya existente
void modificarAlumno(Alumno **lista, char *alumno) {
Alumno *cursor = *lista;

while (cursor != NULL && strcmp(cursor->nombre, alumno) != 0) {
    cursor = cursor->proximo;
}

if (cursor != NULL) {
    printf("Ingrese el nuevo nombre: ");
    char nuevoNombre[50];
    scanf("%49s", nuevoNombre);
    strcpy(cursor->nombre, nuevoNombre);
} else {
    printf("El estudiante no existe.\n");
}
}

//Lista de los alumnos de una materia especifica
void enlistarAlumnosSegunLaMateria(Alumno **lista, char* materia) {
    Alumno* cursor = *lista;
    printf("Alumnos de la materia %s:\n", materia);
    while (cursor!= NULL) {
        Materia* materiaCursor = cursor->materias;
        while (materiaCursor!= NULL) {
            if (strcmp(materiaCursor->nombre, materia) == 0) {
                printf("Nombre: %s\n", cursor->nombre);
                break;
            }
            materiaCursor = materiaCursor->proximo;
        }
        cursor = cursor->proximo;
    }
}

//lista de alumnos anotados en la universidad
void enlistarAlumnos(Alumno *lista) {
    Alumno *cursor = lista;
    printf("Lista de alumnos:\n");
    while (cursor!= NULL) {
        printf("Nombre: %s\n", cursor->nombre);
        cursor = cursor->proximo;
    }
}

//Buscar si el alumno esta dado de Alta
void buscarAlumno(Alumno **lista, char* alumno) {
for (int i = 0; lista[i]!= NULL; i++) {
    if (strcmp(lista[i]->nombre, alumno) == 0) {
        printf("El alumno %s está dado de alta.\n", alumno);
        return;
    }
}
printf("El alumno %s no está dado de alta.\n", alumno);
}

//Buscar el alumno por la edad y devolver los alumnos de dicha edad
void buscarAlumnoEdad(Alumno **lista, int edad) {
    int encontrado = 0;
    printf("Alumnos de %d años:\n", edad);
    for (int i = 0; lista[i]!= NULL; i++) {
        if (lista[i]->edad == edad) {
            printf("%s (%d años)\n", lista[i]->nombre, lista[i]->edad);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron alumnos de %d años.\n", edad);
    }
}

//Anotar un alumno que esta dado de alta en la materia
void agregarMateriaAlAlumno(Alumno* alumno, char* nombreMateria) {
    Materia* nuevaMateria = (Materia*) malloc(sizeof(Materia));
    strcpy(nuevaMateria->nombre, nombreMateria);
    nuevaMateria->estado = 0;
    nuevaMateria->nota = 0.0;
    nuevaMateria->regularidad = 0;
    nuevaMateria->proximo = NULL;

    if (alumno->materias == NULL) {
        alumno->materias = nuevaMateria;
    } else {
        Materia* cursor = alumno->materias;
        while (cursor->proximo!= NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevaMateria;
    }
}

/*Edita la materia del alumno con respecto a sus notas y la regularidad, 
Siendo que la regularidad es 1 y la irregularidad es 0,
*/
void editarMateriaDelAlumno(Alumno* alumno, char* nombreMateria, float nota, int regularidad) {
    Materia* cursor = alumno->materias;
    while (cursor!= NULL && strcmp(cursor->nombre, nombreMateria)!= 0) {
        cursor = cursor->proximo;
    }
    if (cursor!= NULL) {
        cursor->nota = nota;
        cursor->regularidad = regularidad;
        if (nota > 4 && regularidad == 1) {
            cursor->estado = 1; // Aprobado
        } else {
            cursor->estado = 0; // No aprobado
        }
    } else {
        printf("La materia no existe.\n");
    }
}

//Imprime las materias que tiene un alumno junto a sus detalles
void imprimirMateriasDelAlumno(Alumno* alumno) {
    Materia* cursor = alumno->materias;
    while (cursor!= NULL) {
        char* regularidadStr;
        int regularidad = cursor->regularidad;
        if (regularidad == 0) {
            regularidadStr = "irregular";
        } else {
            regularidadStr = "regular";
        }
        char* estadoStr;
        int estado = cursor->estado;
        if (estado == 1) {
            estadoStr = "aprobado";
        } else {
            estadoStr = "desaprobado";
        }
        printf("Materia: %s, Estado: %s, Nota: %.2f, Regularidad: %s\n",
            cursor->nombre, estadoStr, cursor->nota, regularidadStr);
        cursor = cursor->proximo;
    }
}