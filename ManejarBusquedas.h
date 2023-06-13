#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Estructuras.h"
#include "InsertionSort.h"

int busquedaBinaria(Nodo* cabeza, int elemento);
int busquedaSecuencial(Nodo* cabeza, int numero);

void ManejarBusquedas(Registro *registro, int numABuscar);