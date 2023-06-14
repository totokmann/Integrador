#include "InsertionSort.h"

// Metodo de ordenamiento por insercion
//Crea una nueva lista enlazada ordenada
void insertionSort(Registro* registro) {
    Nodo* ordenado = NULL;
    Nodo* actual = registro->primero;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;

        // insertar actual en la nueva lista enlazada
        if (ordenado == NULL || atoi(ordenado->linea) > atoi(actual->linea)) {
            actual->siguiente = ordenado;
            ordenado = actual;
        } else {
            Nodo* ordenado_node = ordenado;
            while(ordenado_node->siguiente != NULL && atoi(ordenado_node->siguiente->linea) < atoi(actual->linea)) {
                ordenado_node = ordenado_node->siguiente;
            }
            actual->siguiente = ordenado_node->siguiente;
            ordenado_node->siguiente = actual;
        }

        // mover a la siguiente iteracion
        actual = siguiente;
    }
    registro->primero = ordenado;
    actual = registro->primero;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    registro->ultimo = actual;
}