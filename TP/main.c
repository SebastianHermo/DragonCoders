#include <stdio.h>
#include <unistd.h>
#include "menu.c"
#include "funciones.c"

void loadingBar();
void menu();
void altaAlumno(Alumno **lista, char* alumno, int edad);
void altaMateria(Materia **lista, char* materia);
void bajaAlumno(Alumno ** lista, char* alumno);
void bajaMateria(Materia **lista, char* materia);
void modificarMateria(Materia **lista, char *materia);
void modificarAlumno(Alumno **lista, char* alumno);
void enlistarAlumnosSegunLaMateria(Alumno **lista, char* materia);
void enlistarAlumnos(Alumno *lista);
void buscarAlumno(Alumno **lista, char* alumno);
void buscarAlumnoEdad(Alumno **lista, int edad);
void editarMateriaDelAlumno(Alumno* alumno, char* nombreMateria, float nota, int regularidad);
void imprimirMateriasDelAlumno(Alumno* alumno);


int main() {
    loadingBar();

    printf("\n\n");

    menu();
    return 0;
}

void loadingBar() {
    // Carácter para la barra de carga
    char a = '#';

    printf("\n\n\n\n");
    printf("Inicializando el GestorDeALumnos, por favor aguarde un momento...\n\n");
    printf("[");

    // Tamaño de la barra de carga
    int barLength = 30;

    // Imprimir barra de carga vacía
    for (int i = 0; i < barLength; i++) {
        printf("-");
    }

    printf("]");

    // Volver al inicio de la barra de carga
    printf("\r");
    printf("\t\t\t\t[");

    // Imprimir barra de carga con progreso
    for (int i = 0; i < barLength; i++) {
        printf("%c", a);
        fflush(stdout); // Asegurarse de que se imprime inmediatamente
        usleep(100000); // Pausa de 100 ms
    }

    printf("]\n");
}