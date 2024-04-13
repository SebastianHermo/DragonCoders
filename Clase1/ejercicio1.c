

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

/*
#include <stdio.h>

int main(){
    
    int lista[3];
    int suma = 0;

    printf("Ingresar 3 numeros enteros: ");
    scanf("%d %d %d", &lista[0], &lista[1], &lista[3]);

    for (int i = 0; i < sizeof(lista) / sizeof(int); i++){
        suma = suma + lista[i];
    }
    float promedio = (float) suma / sizeof(lista) * sizeof(int);
    
    printf("Promedio: %f", promedio);

    return 0;
}
*/