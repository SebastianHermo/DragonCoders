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
