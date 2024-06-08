#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

void menu(){

    printf("Seleccione a continuación la opción que desee utilizar\n");
    printf("1. Dar de alta un alumno\n"
           "2. Dar de baja un alumno\n"
           "3. Dar de alta una materia\n"
           "4. Dar de baja una materia\n"
           "5. Modificar datos de alumno\n"
           "6. Modificar datos de una materia\n"
           "7. Salir\n");

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
        case 7:
           void despedida();
    }
}

    void despedida(){
    time_t now = time(NULL);        
    struct tm *tm = localtime(&now);
    int hour = tm->tm_hour;
    char *greeting;
    if (hour < 12) {
        greeting = "Buenos días";
    } else if (hour < 18) {
        greeting = "Buenas tardes";
    } else {
        greeting = "Buenas noches";
    }
    printf("%s, gracias por utilizar nuestra aplicación.\n", greeting);
    printf("Esperamos que hayas disfrutado de nuestra aplicación. ¡Hasta luego!\n");

    // Cerrar la consola
    #ifdef _WIN32
        system("exit"); // Para Windows
    #else
        system("clear"); // Para Linux y macOS
    #endif
}