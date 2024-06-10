#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include "funciones.c"

void despedida();
void menuGestionAlumnos(Alumno **listaAlumno, Materia **listaMateria);
void menuGestionMaterias(Alumno **listaAlumno, Materia **listaMateria);
struct Alumno;
struct Materia;
char *alumno;
char *materia;
char *nuevoNombre;
int edad;
int nuevaEdad;
float nota;

void menu(Alumno **listaAlumno, Materia **listaMateria)
{
    int opcion;
    printf("Seleccione a continuación la opción que desee utilizar\n");
    printf("1. Menu para la gestion de Alumnos\n"
           "2. Menu para la gestion de Materias\n"
           "3. Salir\n");
    scanf("%1d", &opcion);

    if (opcion < 1 || opcion > 3)
    {
        printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise.");
        menu(listaAlumno, listaMateria);
    }
    else
        switch (opcion)
        {
        case 1:
            menuGestionAlumnos(&listaAlumno, &listaMateria);
            break;
        case 2:
            menuGestionMateria(&listaAlumno, &listaMateria);
            break;
        case 3:
            despedida();
            break;
        }
}
void menuGestionAlumnos(Alumno **listaAlumno, Materia **listaMateria)
{

    printf("Seleccione a continuación la opción que desee utilizar\n");

    printf("1. Dar de alta un alumno\n"
           "2. Dar de baja un alumno \n"
           "3. Modificar datos de alumno\n"
           "4. Enlistar Alumnos\n"
           "5. Buscar Alumnos\n"
           "6. Volver al menú principal\n");

    int opcion;
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 6)
    {
        printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise.");
        menuGestionAlumnos(&listaAlumno, &listaMateria);
    }
    else
    {
        switch (opcion)
        {
        case 1:
            printf("Ingrese el nombre del alumno y su edad\n");
            scanf("%s %d", alumno, &edad);
            altaAlumno(&listaAlumno, alumno, edad);
            printf("El alumno fue ingresado con exito\n");
            menuGestionAlumnos(&listaAlumno, &listaMateria);
            break;

        case 2:
            printf("Ingrese el nombre del alumno\n");
            scanf("%s", alumno);
            bajaAlumno(&listaAlumno, alumno);
            printf("El alumno fue eliminado con exito\n");
            menuGestionAlumnos(&listaAlumno, &listaMateria);
            break;

        case 3:
            printf("Seleccione a continuación la opción que desee utilizar\n");
            printf("1. Modificar edad o nombre\n"
                   "2. Modificar La nota de una materia\n"
                   "3. Agregar una materia al Alumno\n"
                   "4. Volver al Gestor de Alumnos\n");
            printf("Ingrese que tipo de modificacion desee hacer\n");
            scanf("%1d", &opcion);

            if (opcion < 1 || opcion > 4)
            {
                printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise una vez que vuelva a esta opcion.");
                menuGestionAlumnos(&listaAlumno, &listaMateria);
            }
            else
                switch (opcion)
                {
                case 1:
                    printf("Ingrese el nombre actual del alumno, su nuevo nombre y su nueva edad\n");
                    scanf("%s %s %d", alumno, nuevoNombre, &nuevaEdad);
                    modificarAlumno(&listaAlumno, alumno, nuevoNombre, nuevaEdad);
                    printf("El nombre fue cambiado con exito\n");
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 2:
                    printf("Segun las materias de a continuacion:\n");
                    imprimirMaterias(&listaMateria);
                    printf("Ingrese el alumno, la materia y la nota\n");
                    scanf("%s %s %d", alumno, materia, nota);
                    editarNotaDelAlumno(&listaAlumno, alumno, materia, nota);
                    printf("La nota ya fue modificada");
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 3:
                    printf("Segun las materias de a continuacion:\n");
                    imprimirMaterias(&listaMateria);
                    printf("Ingrese el alumno que quiere agregar su materia\n");
                    scanf("%s", alumno);
                    agregarMateriaAlumno(&listaAlumno, alumno);
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 4:
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                }
            break;
        case 4:
            printf("Seleccione a continuacion la opcion que desee utilizar\n");
            printf("1. Enlistar Alumnos Regulares de una materia\n"
                   "2. Enlistar a todos los alumnos activos\n"
                   "3. Enlistar las materias de un alumno\n"
                   "4. Volver al menu de Gestiones de Alumnos\n");
            scanf("%1d", opcion);
            if (opcion < 1 || opcion > 4)
            {
                printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise una vez que vuelva a esta opcion.");
                menuGestionAlumnos(&listaAlumno, &listaMateria);
            }
            else
                switch (opcion)
                {
                case 1:
                    printf("Ingrese la materia que quiere enlistar de las que se muestran a continuacion");
                    imprimirMaterias(&listaMateria);
                    scanf("%s", materia);
                    enlistarAlumnosRegulares(&listaAlumno, materia);
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 2:
                    printf("A continuacion se enlistaran todos los alumnos activos\n");
                    enlistarAlumnos(&listaAlumno);
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 3:
                    printf("Ingrese el alumno a quien quiere ver sus materias");
                    scanf("%s", alumno);
                    imprimirMateriasDelAlumno(&listaAlumno, alumno);
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 4:
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                }
            break;
        case 5:
            printf("Seleccione a continuacion la opcion que desee utilizar\n");
            printf("1. Buscar alumno en especifico\n"
                   "2. Buscar alumno por edad\n"
                   "3. Volver al menu de Gestiones de Alumnos\n");
            scanf("%1d", opcion);
            if (opcion < 1 || opcion > 3)
            {
                printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise una vez que vuelva a esta opcion.");
                menuGestionAlumnos(&listaAlumno, &listaMateria);
            }
            else
            {
                switch (opcion)
                {
                case 1:
                    printf("Ingrese a continuacion el alumno que quiere buscar:\n");
                    scanf("%s", alumno);
                    buscarAlumno(&listaAlumno, alumno);
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 2:
                    printf("Ingrese a continuacion la edad que esta buscando");
                    scanf("%d", edad);
                    buscarAlumnoEdad(&listaAlumno, edad);
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                case 3:
                    menuGestionAlumnos(&listaAlumno, &listaMateria);
                    break;
                }
            }
            break;
        case 6:
            menu(&listaAlumno, &listaMateria);
            break;
        }
    }
}
void menuGestionMaterias(Alumno **listaAlumno, Materia **listaMateria)
{

    printf("Seleccione a continuación la opción que desee utilizar\n");

    printf("1. Dar de alta una materia\n"
           "2. Dar de baja una materia \n"
           "3. Modificar datos de una materia\n"
           "4. Volver al menú principal\n");

    int opcion;
    scanf("%d", &opcion);

    if (opcion < 1 || opcion > 4)
    {
        printf("La opción ingresada no es valida, porfavor vuelva a ingresar la opción que precise.");
        menuGestionMaterias(&listaAlumno, &listaMateria);
    }
    else
    {

        switch (opcion)
        {
        case 1:
            printf("Ingrese el nombre de la materia que va a dar de alta.\n");
            scanf("%s", materia);
            altaMateria(&listaMateria, materia);
            printf("La materia fue ingresada con exito.\n");
            menuGestionMaterias(&listaAlumno, &listaMateria);
            break;
        case 2:
            printf("Ingrese el nombre de la materia que va a dar de baja.\n");
            scanf("%s", materia);
            bajaMateria(&listaMateria, materia);
            printf("La materia fue dada de baja con exito.\n");
            menuGestionMaterias(&listaAlumno, &listaMateria);
            break;
        case 3:
            printf("Ingrese el nombre de la materia que quiere cambiar de las que hay a continuacion:.\n");
            imprimirMaterias(&listaMateria);
            scanf("%s", materia);
            if (buscarMateria(&listaMateria, materia) == materia)
            {
                printf("Ahora ingrese su nuevo nombre");
                scanf("%s", nuevoNombre);
                modificarMateria(&listaMateria, materia, nuevoNombre);
                printf("La materia a cambiado su nombre exitosamente.\n");
                menuGestionMaterias(&listaAlumno, &listaMateria);
                break;
            }
            printf("La materia que quisiste cambiar no existe, vuelva a intentarlo cuando vuelva a este lugar.\n");
            menuGestionMaterias(&listaAlumno, &listaMateria);
            break;
        case 4:
            menu(&listaAlumno, &listaMateria);
            break;
        }
    }
}

void despedida()
{
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    int hour = tm->tm_hour;
    char *greeting;

    if (hour < 12)
    {
        greeting = "Buenos días";
    }
    else if (hour < 18)
    {
        greeting = "Buenas tardes";
    }
    else
    {
        greeting = "Buenas noches";
    }

    printf("%s, gracias por utilizar nuestra aplicación.\n", greeting);
    printf("Esperamos que hayas disfrutado de nuestra aplicación. ¡Hasta luego!\n");
    printf("Presione enter para salir...\n");
    getchar(); // Esperar a que el usuario presione una tecla

    int c;
    if ((c = getchar()) != EOF)
    {
// Cerrar la consola
#ifdef _WIN32
        system("exit"); // Para Windows
#else
        system("clear"); // Para Linux y macOS
#endif
    }
}
