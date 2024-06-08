#include <stdio.h>
#include <unistd.h>
#include "funciones.c"

void loadingBar();
void menu();
void menuBasico();

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

void menu() {
    printf("Bienvenido/s al Gestor de Alumnos por DragonCoders.\n\n"
           "Para comenzar a utilizar el sistema, deberas cargar la informacion del primer alumno:\n\n");

    char nombre [20];
    int edad;
    printf("Ingrese el nombre y la edad del Alumno que desea cargar (solo nombre y edad): \n");
    scanf("%s %d", nombre, &edad);

    /*AltaAlumno(nombre,edad);*/

    printf("\nMuy bien hecho! A partir de esto podemos comenzar a operar.\n\n");

    menuBasico();

}

void menuBasico(){

    printf("Seleccione a continuacion la opcion que desee utilizar\n");
    printf("1. Dar de alta un alumno\n"
           "2. Dar de baja un alumno\n"
           "3. Dar de alta una materia\n"
           "4. Dar de baja una materia\n"
           "5. Modificar datos de alumno\n"
           "6. Modificar datos de una materia\n");

    int opcion;
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("\nFausto no hizo el codigo todavia");
            break;
        case 2:
            printf("\nFausto no hizo el codigo todavia");
            break;
        case 3:
            printf("\nFausto no hizo el codigo todavia");
            break;
        case 4:
            printf("\nFausto no hizo el codigo todavia");
            break;
        case 5:
            printf("\nFausto no hizo el codigo todavia");
            break;
        case 6:
            printf("\nFausto no hizo el código todavía");
            break;
    }
