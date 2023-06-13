#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Estructuras.h"
#include "InsertionSort.h"
#include "CreacionDeLista.h"
#include "InsertionSort.h"

void insercionDeNumero(Registro *registro, char caracter[4]);

int busquedaBinaria(Nodo* cabeza, int elemento);
int busquedaSecuencial(Nodo* cabeza, int numero);

void encontrarMaximoMinimo(Registro* registro);

void ManejarBusquedas(Registro *registro, int numABuscar);