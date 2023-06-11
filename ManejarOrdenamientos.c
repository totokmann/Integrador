#include "ManejarOrdenamientos.h"
void metodoBurbuja(Registro *registro){
    Registro* NuevoRegistro = duplicarRegistro(registro); //duplicamos registro

    clock_t inicio = clock(); // Guardar el tiempo inicial
    bubbleSort(NuevoRegistro);
    clock_t fin = clock(); // Guardar el tiempo final

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC; // Calcular la diferencia de tiempo en segundos
    system("cls");
    printf("\n Se ordenaron los numeros en un tiempo de %f segundos con el metodo burbuja\nResultante:\n", tiempo);
    imprimirMatriz(NuevoRegistro);
    return;
};

void metodoInsercion(Registro *registro){
    printf("Esta función todavia no está terminada!");
    return;
};

void metodoSeleccion(Registro *registro){
    printf("Esta función todavia no está terminada!");
    return;
};

void metodoOrdenacionRapida(Registro *registro){
    printf("Esta función todavia no está terminada!");
    return;
};