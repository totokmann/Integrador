#include <stdio.h>
#include <stdbool.h>
#include "Estructuras.h"
#include "SelectionSort.h"

void intercambioSelection(Registro *registro, int indice1, int indice2)
{
    if (indice1 < 0 || indice2 < 0 ||
        indice1 > registro->cantidadDeNumeros || indice2 > registro->cantidadDeNumeros)
    {
        return;
    }

    int contador = 1;
    Nodo *nodo1 = registro->primero;
    Nodo *nodo2 = registro->primero;

    while (contador < indice2) // Adjusted condition
    {
        nodo2 = nodo2->siguiente;
        contador++;
    }

    contador = 1;
    while (contador < indice1)
    {
        nodo1 = nodo1->siguiente;
        contador++;
    }

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

    if (nodo1 == previo2)
    {
        nodo2->siguiente = nodo1;
        nodo1->siguiente = siguiente2;
    }
    else
    {
        nodo1->siguiente = siguiente2;
        previo2->siguiente = nodo1;
        nodo2->siguiente = siguiente1;
    }

    // Actualizar el puntero al último nodo si es necesario
    if (siguiente1 == NULL)
    {
        registro->ultimo = nodo2;
    }
    if (siguiente2 == NULL)
    {
        registro->ultimo = nodo1;
    }
}

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
    int indiceMenor;
    Nodo *menorNodo;
    Nodo *temporal;
    Nodo *nodoEnIteracion = registro->primero;
    for (int i = 1; i < registro->cantidadDeNumeros; i++) // Corrección en el límite del bucle interno
    {
        nodoEnIteracion = registro->primero;
        for (int k = 1; k < i; k++)
        {
            nodoEnIteracion = nodoEnIteracion->siguiente;
        }
        indiceMenor = i;
        menorNodo = nodoEnIteracion;
        temporal = nodoEnIteracion->siguiente;
        for (int j = i + 1; j <= registro->cantidadDeNumeros; j++)
        {
            if (temporal == NULL)
            {
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
            intercambioSelection(registro, i, indiceMenor);
        }
    }
}