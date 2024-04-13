#include <stdio.h>

int main(){

    int lista[] = {1, 25, 36, 46, 20, 1};
    int minLista = lista[0];
   
    for (int i = 0; i < sizeof(lista) / sizeof(int); i++){
      if (lista[i] < minLista) {
        minLista = lista[i];
      } 
    } 

   printf("Minimo: %d", minLista);
   
    return 0;
}
