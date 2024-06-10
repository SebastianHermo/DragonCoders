#include <stdio.h>
#include <unistd.h>
#include "funciones.c"

void loadingBar();
void menu();
void menuBasico();
void menuBasico2(int);
void menuGestionAlumnos();
void menuGestionMaterias();

Alumno *listaAlumnos = NULL;
Materia *listaMaterias = NULL;

int main() {
    //loadingBar();

    printf("\n\n");

    menu();
    return 0;
}

void loadingBar() {

    int i;
    //    printf("\n\n\n\n");
    printf("\n\n\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t["); // Corchete de apertura
    for (i = 0; i < 26; i++) {
        printf("%c", 177);
        fflush(stdout);
        usleep(100000); // 100ms delay
    }
    printf("]"); // Corchete de cierre para la primera barra
    printf("\r");
    printf("\t\t\t\t\t["); // Corchete de apertura
    for (i = 0; i < 26; i++) {
        printf("%c", 219);
        fflush(stdout);
        usleep(100000); // 100ms delay
    }
    printf("]"); // Corchete de cierre para la segunda barra

}


void menu() {
    printf("Bienvenido/s al Gestor de Alumnos por DragonCoders.\n\n"
           "Para comenzar a utilizar el sistema, deberás cargar la información del primer alumno:\n\n");

   
    char nombre [20];
    int edad;
    printf("Ingrese el nombre de pila del Alumno que desea cargar: \n");
    scanf("%s", nombre);
    printf("Perfecto, a continuación ingrese la edad de dicho alumno : \n");
    scanf("%d", &edad);

    altaAlumno(&listaAlumnos, nombre, edad);

    printf("\nMuy bien hecho! A partir de esto podemos comenzar a operar, a partir de distintas funciones para los alumnos y sus respectivas materias cursadas o en curso.\n\n");

    menuBasico();

}

void menuBasico(){

    int opcion;

    printf("1. Alumnos\n");
    printf("2. Materias\n");
    printf("3. Cerrar el sistema\n");

    scanf("%d", &opcion);
    menuBasico2(opcion);
}

void menuBasico2(int opcion) {

    if (opcion < 1 || opcion > 3) {
        printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise.");
        menuBasico();
    } else {
        switch (opcion) {
            case 1:
                menuGestionAlumnos();
                break;
            case 2:
                menuGestionMaterias();
                break;
            case 3:
               break;
        }
    }
}

void menuGestionAlumnos(){

    printf("Seleccione a continuación la opción que desee utilizar\n");

    printf("1. Dar de alta un alumno\n"
           "2. Dar de baja un alumno \n"
           "3. Modificar datos de alumno\n"
           "4. Volver al menú principal\n");


    int opcion;
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 4){
        printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise.");
        menuGestionAlumnos();
    } else {
        char alumno[20];
        int edad;
        switch (opcion) {
            case 1:

                printf("Ingrese el nombre del alumno y su edad\n");
                scanf("%s %d", alumno, &edad);

                altaAlumno(&listaAlumnos, alumno, edad);

                printf("El alumno fue ingresado con exito\n");

                menuBasico();
                
                break;

                case 2:
                    
                    printf("Ingrese el nombre del alumno\n");
                    scanf("%s", alumno);

                    bajaAlumno(&listaAlumnos, alumno);

                    printf("El alumno fue eliminado con exito\n");

                    menuBasico();
                    break;

                    case 3:
                        
                        printf("Ingrese el nombre del alumno\n");
                        scanf("%s", alumno);

                        modificarAlumno(&listaAlumnos, alumno);

                        printf("El nombre fue cambiado con exito\n");

                        menuBasico();
                        break;

                        case 4:
                            menuBasico();
                            break;
        }
    }
}

void menuGestionMaterias(){

    printf("Seleccione a continuación la opción que desee utilizar\n");

    printf("1. Dar de alta una materia\n"
           "2. Dar de baja una materia \n"
           "3. Modificar datos de una materia\n"
           "4. Volver al menú principal\n");

    int opcion;
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 4){
        printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise.");
        menuGestionMaterias();

    } else {

        switch (opcion) {
            case 1:
                printf("\nFausto no hizo el código todavía.\n");
                break;
            case 2:
                printf("\nFausto no hizo el código todavía.\n");
                break;
            case 3:
                printf("\nFausto no hizo el código todavía.\n");
                break;
            case 4:

                break;

        }
    }
}