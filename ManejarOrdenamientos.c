#include "ManejarOrdenamientos.h"

//Maneja el metodo de burbuja y mide el tiempo
void metodoBurbuja(Registro *registro)
{
    Registro *NuevoRegistro = duplicarRegistro(registro); // duplicamos registro

    clock_t inicio = clock(); // Guardar el tiempo inicial
    bubbleSort(NuevoRegistro);
    clock_t fin = clock(); // Guardar el tiempo final

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC; // Calcular la diferencia de tiempo en segundos
    //system("cls");
    printf("\n Se ordenaron los numeros en un tiempo de %f segundos con el metodo burbuja\nResultante:\n", tiempo);
    imprimirMatriz(NuevoRegistro);
    eliminarRegistro(NuevoRegistro);
    return;
};

//Maneja el metodo de insercion y mide el tiempo
void metodoInsercion(Registro *registro)
{
    Registro *NuevoRegistro = duplicarRegistro(registro); // duplicamos registro

    clock_t inicio = clock(); // Guardar el tiempo inicial
    insertionSort(NuevoRegistro);
    clock_t fin = clock(); // Guardar el tiempo final

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC; // Calcular la diferencia de tiempo en segundos
    //system("cls");
    printf("\n Se ordenaron los numeros en un tiempo de %f segundos con el metodo de Insercion\nResultante:\n", tiempo);
    imprimirMatriz(NuevoRegistro);
    eliminarRegistro(NuevoRegistro);
    return;
};

//Mide el metodo de seleccion y mide el tiempo
void metodoSeleccion(Registro *registro)
{
    Registro *NuevoRegistro = duplicarRegistro(registro); // duplicamos registro

    clock_t inicio = clock(); // Guardar el tiempo inicial
    selectionSort(NuevoRegistro);
    clock_t fin = clock(); // Guardar el tiempo final

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC; // Calcular la diferencia de tiempo en segundos
    //system("cls");
    printf("\n Se ordenaron los numeros en un tiempo de %f segundos con el metodo de Seleccion\nResultante:\n", tiempo);
    imprimirMatriz(NuevoRegistro);
    eliminarRegistro(NuevoRegistro);
    return;
};

//Maneja el metodo de quicksort y mide el tiempo
void metodoOrdenacionRapida(Registro *registro)
{
    printf("Esta función todavia no está terminada!");
    return;
};