#include <stdio.h>
#include "BusquedaSecuencial.h"

// Función para buscar un número en la lista enlazada utilizando la búsqueda secuencial
int busquedaSecuencial(Nodo* cabeza, char numero[4]) {
    Nodo* actual = cabeza;
    int posicion = 1;

    while (actual != NULL) {
        if (strcmp(actual->linea, numero) == 0) {
            return posicion;
        }
        actual = actual->siguiente;
        posicion++;
    }

    return -1;
}
