#include <stdio.h>

int main(){

    int lista[] = {1, 25, 36, 46, 20, 0};
    int maxLista = lista[0];
   
    for (int i = 0; i < sizeof(lista) / sizeof(int); i++){
      if (lista[i] > maxLista) {
        maxLista = lista[i];
      } 
    } 

   printf("Maximo: %d", maxLista);
   
    return 0;
}
