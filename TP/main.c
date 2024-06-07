#include <stdio.h>
#include <unistd.h>
#include "funciones.c"
#include "menu.c"
#include "struct.c"

void loadingBar();
void menu();
void altaAlumno();
void altaMateria();
void bajaAlumno();
void bajaMateria();
void modificarMateria();
void modificarAlumno();
void enlistarAlumnosSegunLaMateria();
void enlistarAlumnos();
void buscarAlumno();
void buscarAlumnoEdad();
void editarMateriaDelAlumno();
void imprimerMateriasDelAlumno();


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