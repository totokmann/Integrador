#include "ManejarBusquedas.h"

int busquedaBinaria(Nodo *cabeza, int elemento)
{
    Nodo *inicio = cabeza;
    Nodo *fin = NULL;
    int indice = 0;

    while (inicio != fin)
    {
        Nodo *medio = inicio;
        int longitud = 0;

        // Calcular la longitud de la sublista
        while (medio != fin)
        {
            longitud++;
            medio = medio->siguiente;
        }

        // Obtener el elemento medio
        medio = inicio;
        for (int i = 0; i < longitud / 2; i++)
        {
            medio = medio->siguiente;
        }

        // Realizar la comparación con el elemento medio
        if (atoi(medio->linea) == elemento)
        {
            return indice + longitud / 2; // Elemento encontrado, return the indice
        }
        else if (atoi(medio->linea) > elemento)
        {
            fin = medio;
        }
        else
        {
            inicio = medio->siguiente;
            indice += longitud / 2 + 1;
        }
    }

    return -1; // Elemento no encontrado
} 

// Función para buscar un número en la lista enlazada utilizando la búsqueda secuencial
int busquedaSecuencial(Nodo *cabeza, int numero)
{
    Nodo *actual = cabeza;
    int posicion = 1;

    while (actual != NULL)
    {
        if (atoi(actual->linea) == numero)
        {
            return posicion;
        }
        actual = actual->siguiente;
        posicion++;
    }

    return -1;
}

void ManejarBusquedas(Registro *registro, int numABuscar)
{
    Registro *registroOrdenado = duplicarRegistro(registro);
    insertionSort(registroOrdenado);

    system("cls");
    printf("\nMatriz desordenada:\n");
    imprimirMatriz(registro);

    printf("\nMatriz ordenada:\n");
    imprimirMatriz(registroOrdenado);

    //Secuencial en lista ordenada
    clock_t inicio = clock();
    int Secuencial = busquedaSecuencial(registroOrdenado->primero, numABuscar);
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    if (Secuencial != -1)
    {
        printf("\nBusqueda secuencial en la matriz ordenada encontro el elemento: %d", Secuencial);
    }
    else {
        printf("\nBusqueda secuencial en la matriz ordenada no encontro el elemento");
    }
    printf("\nTiempo de ejecucion: %f segundos\n\n", tiempo);

    //Secuencial en lista desordenada
    inicio = clock();
    Secuencial = busquedaSecuencial(registro->primero, numABuscar);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    if (Secuencial != -1)
    {
        printf("\nBusqueda secuencial en la matriz desordenada encontro el elemento: %d", Secuencial);
    }
    else {
        printf("\nBusqueda secuencial en la matriz desordeanada no encontro el elemento");
    }
    printf("\nTiempo de ejecucion: %f segundos\n\n", tiempo);


    //Binaria en lista ordenada
    inicio = clock();
    int binaria = busquedaBinaria(registro->primero, numABuscar);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    if (binaria != -1)
    {
        printf("\nBusqueda binaria en la matriz ordenada encontro el elemento: %d", binaria);
    }
    else {
        printf("\nBusqueda binaria en la matriz ordenada no encontro el elemento");
    }
    printf("\nTiempo de ejecucion: %f segundos\n\n", tiempo);
}

void encontrarMaximoMinimo(Registro* registro) {

    if (registro->primero == NULL) {
        return;
    }
    int maximo, minimo;

    //Inicio mediciones para desordenado
    clock_t inicio = clock();
    maximo = atoi(registro->primero->linea);
    minimo = atoi(registro->primero->linea);
    Nodo* actual = registro->primero->siguiente;

    while (actual != NULL) {
        int dato = atoi(actual->linea);
        if (dato > maximo) {
            maximo = dato;
        }
        else if (dato < minimo) {
            minimo = dato;
        }
        actual = actual->siguiente;
    }
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Analizando la lista desordenada:\n");
    printf("El maximo es: %d\n", maximo);
    printf("El minimo es: %d\n", minimo);
    printf("Tiempo de ejecucion: %f segundos\n\n", tiempo);

    Registro* registroOrdenado = duplicarRegistro(registro);
    //Inicio de mediciones para ordenado
    inicio = clock();
    insertionSort(registroOrdenado);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Analizando la lista ordenada:\n");
    printf("El maximo es: %d\n", atoi(registroOrdenado->ultimo->linea));
    printf("El minimo es: %d\n", atoi(registroOrdenado->primero->linea));
    printf("Tiempo de ejecucion: %f segundos\n\n", tiempo);
    eliminarRegistro(registroOrdenado);
    return;
}