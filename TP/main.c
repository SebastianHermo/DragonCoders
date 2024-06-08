#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "menu.c"

void loadingBar();
void menu();

int main(){
    loadingBar();
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