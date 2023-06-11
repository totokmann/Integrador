#include <stdio.h>
#include <stdlib.h>
#include "CreacionDeLista.h"
#include "Estructuras.h"

// Función para imprimir la matriz
void imprimirMatriz(Registro* registro) {
    Nodo* actual = registro->primero;
    int columna = 0;
    while (actual != NULL) {
        printf("%s", actual->linea);
        columna++;
        if (columna % 10 == 0) {
            printf("\n");
            if (actual->siguiente != NULL) {
                for (int i = 0; i < 10; i++) {
                    if (i == 0) {
                        printf("----|");
                    } else {
                        printf("-----|");
                    }
                }
                printf("\n");
            }
        } else {
            printf(" | ");
        }
        actual = actual->siguiente;
    }
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
        return 1;
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