#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Estructuras.h"
#include "./Sorts/InsertionSort.h"

void insercionDeNumero(Registro *registro, char caracter[4]);

int busquedaBinaria(Nodo *cabeza, int elemento);
int busquedaSecuencial(Nodo* cabeza, int numero);

void encontrarMaximoMinimo(Registro* registro);

void ManejarBusquedas(Registro *registro, int numABuscar);