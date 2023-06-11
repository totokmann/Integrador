#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

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
Nodo* crearNodo(char linea[4]) {}

// Función para insertar un nodo al final de la lista enlazada
void insertarNodo(Registro* registro, Nodo* nuevoNodo) {}

#endif