#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoArbol {
    int valor;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
} NodoArbol;

NodoArbol* construirArbol(const char* nombreArchivo);
void imprimirArbol(NodoArbol* raiz, int nivel);

#endif  // ARBOLBINARIO_H
