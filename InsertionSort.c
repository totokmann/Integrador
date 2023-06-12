#include "InsertionSort.h"

void insertionSort(Registro* registro) {
    Nodo* ordenado = NULL;
    Nodo* actual = registro->primero;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;

        // Insert actual in ordenado linked list
        if (ordenado == NULL || atoi(ordenado->linea) > atoi(actual->linea)) {
            actual->siguiente = ordenado;
            ordenado = actual;
        } else {
            Nodo* ordenado_node = ordenado;
            while(ordenado_node->siguiente != NULL && atoi(ordenado_node->siguiente->linea) < atoi(actual->linea)) {
                ordenado_node = ordenado_node->siguiente;
            }
            // Insert the actual node
            actual->siguiente = ordenado_node->siguiente;
            ordenado_node->siguiente = actual;
        }

        // Move onto the next iteration
        actual = siguiente;
    }
    registro->primero = ordenado;
}