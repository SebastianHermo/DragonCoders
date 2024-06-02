#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct structNodo{
    ///@brief
    struct structNodo proximo;
    char nombre;
    bool estado;
}Materia;

typedef struct structNodo {
    /// @brief 
    struct structNodo proximo;
    char alumno;
    int edad;
} Alumno;
