#include <stdio.h>

#include "ManejarOrdenamientos.h"
#include "BubbleSort.h"
#include "Estructuras.h"

void metodoBurbuja(Registro *registro){
    Registro* NuevoRegistro = duplicarRegistro(registro);
    bubbleSort(NuevoRegistro);
    printf("El resultado de la ordenación es:\n");
    imprimirMatriz(NuevoRegistro);
    return;
};

void metodoInsercion(Registro *registro){
    printf("Esta función todavía no está terminada!");
    return;
};

void metodoSeleccion(Registro *registro){
    printf("Esta función todavía no está terminada!");
    return;
};

void metodoOrdenacionRapida(Registro *registro){
    printf("Esta función todavía no está terminada!");
    return;
};