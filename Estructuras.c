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

//Lee el archivo y crea una lista enlazada con los datos
Registro* CreacionDeLista() {
    Registro* registro = (Registro*)malloc(sizeof(Registro));
    registro->primero = NULL;
    registro->ultimo = NULL;
    registro->cantidadDeNumeros = 0;

    char nombreArchivo[] = "numeros.txt"; // Nombre del archivo a leer
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return registro;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Eliminar el salto de línea si existe
        int longitud = strlen(linea);
        if (linea[longitud - 1] == '\n') {
            linea[longitud - 1] = '\0';
        }

        // Crear un nuevo nodo con la línea actual
        Nodo* nuevoNodo = crearNodo(linea);
        insertarNodo(registro, nuevoNodo);
    }
    fclose(archivo);

    return registro;
}

Registro* duplicarRegistro(Registro* original)
{
    Registro *duplicado = (Registro *)malloc(sizeof(Registro));
    duplicado->primero = NULL;
    duplicado->ultimo = NULL;
    duplicado->cantidadDeNumeros = 0;

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

//Elimina todos los elementos de un registro
void eliminarRegistro(Registro* registro) {
    Nodo* actual = registro->primero;
    Nodo* temp;

    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    registro->primero = NULL;
    registro->ultimo = NULL;
    registro->cantidadDeNumeros = 0;
    free(registro);
}
