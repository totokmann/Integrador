#include "BubbleSort.h"
//Mueve actual a su derecha
//Evalua casos de error
void intercambioBubbleSort(Registro* registro, int locacion) {
    if (locacion < 0 || locacion > registro->cantidadDeNumeros) {
        return;
    }
    int contador = 1;
    
    //Definimos un previo para poder enlazar con el nodo previo
    Nodo *previo = NULL;
    Nodo *actual = registro->primero;
    Nodo *adelante = NULL;
    while (contador < locacion) {
        previo = actual;
        actual = actual->siguiente;
        contador++;
    }

    //Si queremos intercambiar el primer elemento con el segundo
    if (contador == 1) {
        adelante = actual->siguiente;
        //Marcamos como primero
        registro->primero = adelante;
        //Actual pasa de señalar a adelante como siguiente, a al que adelante tiene como siguiente
        actual->siguiente = adelante->siguiente;
        //Adelante pasa de señalar a su siguiente anterior a señalar a actual, que se movió un lugar para atras
        adelante->siguiente = actual;
        return;
    }

    //Error, ultimo intercambiado con vacío
    if (actual->siguiente == NULL) { return; }

    adelante = actual->siguiente;
    previo->siguiente = adelante;
    actual->siguiente = adelante->siguiente;
    adelante->siguiente = actual;

    if (actual->siguiente == NULL) {
        registro->ultimo = actual;
    }

    return;
}

// Algoritmo de ordenamiento Bubble Sort para la lista enlazada
void bubbleSort(Registro* registro) {
    int i, j = 0;
    Nodo* actual = registro->primero;
    Nodo* siguiente;

    //Por qué arrancan en 1? porque medimos la lista enlazada con 1 como primer elemento, no con 0
    for (i = 1; i <= registro->cantidadDeNumeros; i++) {
        for (j = 1; j <= registro->cantidadDeNumeros - i; j++) {
            if (actual->siguiente == NULL) {break;};
            if (atoi(actual->linea) > atoi(actual->siguiente->linea)) {
                intercambioBubbleSort(registro, j);
            }
            else {
                actual = actual->siguiente;
            }
        }
        actual = registro->primero;
    }
}