#include <stdio.h>

int main(){
    char nombre [100];
    int edad;
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Su nombre es %s y su edad %d \n", nombre, edad);
    printf("El primer caracter es %c \n", nombre[0]);

    return 0;
}