#include "Estructuras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para crear un nuevo nodo
Nodo *crearNodo(char linea[4])
{
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->linea, linea);
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un nodo al final de la lista enlazada
void insertarNodo(Registro *registro, Nodo *nuevoNodo)
{
    if (registro->primero == NULL)
    {
        registro->primero = nuevoNodo;
        registro->ultimo = nuevoNodo;
    }
    else
    {
        registro->ultimo->siguiente = nuevoNodo;
        registro->ultimo = nuevoNodo;
    }
    registro->cantidadDeNumeros += 1;
}

Registro* duplicarRegistro(Registro* original)
{
    Registro *duplicado = (Registro *)malloc(sizeof(Registro));
    duplicado->cantidadDeNumeros = original->cantidadDeNumeros;
    duplicado->primero = NULL;
    duplicado->ultimo = NULL;

    // Recorrer la lista enlazada original y copiar los nodos
    Nodo *actual = original->primero;
    while (actual != NULL)
    {
        // Crear un nuevo nodo con el mismo valor de línea
        Nodo *nuevoNodo = crearNodo(actual->linea);

        // Insertar el nuevo nodo en el registro duplicado
        insertarNodo(duplicado, nuevoNodo);

        // Avanzar al siguiente nodo en la lista original
        actual = actual->siguiente;
    }

    return duplicado;
}

// Función para imprimir la matriz
void imprimirMatriz(Registro *registro)
{
    Nodo *actual = registro->primero;
    int columna = 0;
    while (actual != NULL)
    {
        // Agregar ceros adicionales a los números
        int numero = atoi(actual->linea);
        if (numero < 10)
        {
            printf("00%d", numero);
        }
        else if (numero < 100)
        {
            printf("0%d", numero);
        }
        else
        {
            printf("%d", numero);
        }

        columna++;
        if (columna % 10 == 0)
        {
            printf("\n");
            if (actual->siguiente != NULL)
            {
                for (int i = 0; i < 10; i++)
                {
                    if (i == 0)
                    {
                        printf("----|");
                    }
                    else
                    {
                        printf("-----|");
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf(" | ");
        }
        actual = actual->siguiente;
    }
}