#include "SelectionSort.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdbool.h>
#include "Estructuras.h"

void intercambioSelection(Registro *registro, int indice1, int indice2)
{
    if ( indice1 < 0 || indice2 < 0 ||
        indice1 >= registro->cantidadDeNumeros || indice2 >= registro->cantidadDeNumeros)
    {
        printf("Error: Índices inválidos para intercambio.\n");
        return;
    }

    int contador = 1;
    Nodo *nodo1 = registro->primero;
    Nodo *nodo2 = registro->primero;

    while (contador < indice2)
    { // Menor o igual para considerar que arranca de la posicion 1
        if (contador < indice1)
        {
            nodo1 = nodo1->siguiente;
        }
        nodo2 = nodo2->siguiente;
        contador++;
    }
    printf("Nodo 1: %s\n", nodo1->linea);
    printf("Nodo 2: %s\n", nodo2->linea);

    // Intercambiar los nodos
    Nodo *siguiente1 = nodo1->siguiente;
    Nodo *siguiente2 = nodo2->siguiente;
    Nodo *previo1 = nodoAnterior(registro, nodo1);
    Nodo *previo2 = nodoAnterior(registro, nodo2);

    // Actualizar los punteros de los nodos
    if (previo1 != NULL)
    {
        previo1->siguiente = nodo2;
    }
    else
    {
        registro->primero = nodo2;
    }

    if (previo2 != NULL)
    {
        previo2->siguiente = nodo1;
    }
    else
    {
        registro->primero = nodo1;
    }

    // Actualizar el puntero al último nodo si es necesario
    if (siguiente1 == NULL)
    {
        registro->ultimo = nodo2;
    }
    else {
        nodo2->siguiente = siguiente1;
    }
    if (siguiente2 == NULL)
    {
        registro->ultimo = nodo1;
    }
    else {
        nodo1->siguiente = siguiente2;
    }
    imprimirMatriz(registro);
}

// Función auxiliar para obtener el nodo anterior al nodo dado en una lista enlazada
Nodo *nodoAnterior(Registro *registro, Nodo *nodo)
{
    Nodo *anterior = NULL;
    Nodo *actual = registro->primero;

    while (actual != nodo && actual != NULL)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    return anterior;
}

void selectionSort(Registro *registro)
{
    int indiceMenor = 1;
    Nodo *menorNodo;
    Nodo *temporal;
    Nodo *nodoEnIteracion = registro->primero;
    for (int i = 1; i < registro->cantidadDeNumeros; i++)
    {
        indiceMenor = i;
        Nodo *menorNodo = nodoEnIteracion;
        Nodo *temporal = nodoEnIteracion->siguiente;
        for (int j = 1 + i; j < registro->cantidadDeNumeros; j++)
        {
            if (temporal == NULL)
            {
                printf("Error: No hay mas elementos en la lista. se llego hasta %i\n", j);
                break;
            }
            if (atoi(temporal->linea) < atoi(menorNodo->linea))
            {
                menorNodo = temporal;
                indiceMenor = j;
            }
            temporal = temporal->siguiente;
        }
        if (indiceMenor != i)
        {
            printf("Se intercambian %s y %s; en la posicion %i y %i\n", nodoEnIteracion->linea, menorNodo->linea, i, indiceMenor);
            intercambioSelection(registro, i, indiceMenor);
        }
        nodoEnIteracion = nodoEnIteracion->siguiente;
    }
}