#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

typedef struct Nodo {
    char linea[4];
    struct Nodo* siguiente;
} Nodo;

typedef struct Registro {
    int cantidadDeNumeros;
    Nodo* primero;
    Nodo* ultimo;
} Registro;

// Función para crear un nuevo nodo
Nodo* crearNodo(char linea[4]) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nodo->linea, linea);
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un nodo al final de la lista enlazada
void insertarNodo(Registro* registro, Nodo* nuevoNodo) {
    if (registro->primero == NULL) {
        registro->primero = nuevoNodo;
        registro->ultimo = nuevoNodo;
    } else {
        registro->ultimo->siguiente = nuevoNodo;
        registro->ultimo = nuevoNodo;
    }
    registro->cantidadDeNumeros += 1;
}