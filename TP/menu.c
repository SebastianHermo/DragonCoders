#include <stdio.h>
#include <malloc.h>
#include "funciones.c"

void menu() {
    printf("Bienvenido/s al Gestor de Alumnos por DragonCoders.\n\n"
           "Para comenzar a utilizar el sistema, deberás cargar la información del primer alumno:\n\n");

    char nombre [20];
    int edad;
    printf("Ingrese el nombre y la edad del Alumno que desea cargar (solo nombre y edad): \n");
    scanf("%s %d", nombre, &edad);

    /*AltaAlumno(nombre,edad);*/

    printf("\nMuy bien hecho! A partir de esto podemos comenzar a operar.\n\n");

    menuBasico();

}

void menuBasico(){

    printf("Seleccione a continuación la opción que desee utilizar\n");
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
            printf("\nFausto no hizo el código todavía");
            break;
        case 2:
            printf("\nFausto no hizo el código todavía");
            break;
        case 3:
            printf("\nFausto no hizo el código todavía");
            break;
        case 4:
            printf("\nFausto no hizo el código todavía");
            break;
        case 5:
            printf("\nFausto no hizo el código todavía");
            break;
        case 6:
            printf("\nFausto no hizo el código todavía");
            break;
    }

}