#include <stdio.h>
#include <unistd.h>

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
   
    int option;

    
    printf("Gestor de alumnos");
    printf("\n\n");
    
    printf("0. Salir \n");
    printf("1. Alumnos \n");
    printf("2. Materias \n\n");
    printf("Ingrese su opcion: \n");

    scanf("\n%d", &option);


    switch (option){
    
    case 0:
        printf("==========");
        printf("\n");
        printf("Hasta luego");
        printf("\n");
        printf("==========");
        return;
    case 1:
        //opcionAlumnos();
        break;
    
    default:
        printf("Opcion invalida");
        }
    
    }

void opcionAlumnos(){
    printf("======");
    
}


int main() {
    
    loadingBar();
    menu();
    return 0;
}
