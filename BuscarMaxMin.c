#include "BuscarMaxMin.h"

void encontrar_max_min(Registro* registro, int* maximo, int* minimo) {
    if (registro->primero == NULL) {
        *maximo = *minimo = 0;
        return;
    }

    *maximo = atoi(registro->primero->linea);
    *minimo = atoi(registro->primero->linea);
    Nodo* actual = registro->primero->siguiente;

    while (actual != NULL) {
        int dato = atoi(actual->linea);
        if (dato > *maximo) {
            *maximo = dato;
        }
        else if (dato < *minimo) {
            *minimo = dato;
        }
        actual = actual->siguiente;
    }
}