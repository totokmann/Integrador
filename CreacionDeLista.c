#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char linea[4];
    struct Nodo* siguiente;
} Nodo;

typedef struct Registro {
    int cantidadDeNumeros;
    Nodo* primero;
    Nodo* ultimo;
} Registro;

// Función para crear un nuevo nodo
Nodo* crearNodo(char linea[4]) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nodo->linea, linea);
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un nodo al final de la lista enlazada
void insertarNodo(Registro* registro, Nodo* nuevoNodo) {
    if (registro->primero == NULL) {
        registro->primero = nuevoNodo;
        registro->ultimo = nuevoNodo;
    } else {
        registro->ultimo->siguiente = nuevoNodo;
        registro->ultimo = nuevoNodo;
    }
    registro->cantidadDeNumeros += 1;
}

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

//Mueve actual a su derecha
void intercambioBubbleSort(Registro* registro, int locacion) {
    if (locacion < 0 || locacion > registro->cantidadDeNumeros) {
        return;
    }
    int contador = 1;
    
    //Definimos un previo para poder enlazar con el nodo previo
    Nodo *previo = NULL;
    Nodo *actual = registro->primero;
    Nodo *adelante = NULL;
    while (contador < locacion) {
        previo = actual;
        actual = actual->siguiente;
        contador++;
    }

    //Si queremos intercambiar el primer elemento con el segundo
    if (contador == 1) {
        adelante = actual->siguiente;
        //Marcamos como primero
        registro->primero = adelante;
        //Actual pasa de señalar a adelante como siguiente, a al que adelante tiene como siguiente
        actual->siguiente = adelante->siguiente;
        //Adelante pasa de señalar a su siguiente anterior a señalar a actual, que se movió un lugar para atras
        adelante->siguiente = actual;
        return;
    }

    //Error, ultimo intercambiado con vacío
    if (actual->siguiente == NULL) { return; }

    adelante = actual->siguiente;
    previo->siguiente = adelante;
    actual->siguiente = adelante->siguiente;
    adelante->siguiente = actual;

    if (actual->siguiente == NULL) {
        registro->ultimo = actual;
    }

    return;
}

// Algoritmo de ordenamiento Bubble Sort para la lista enlazada
void bubbleSort(Registro* registro) {
    int i, j = 0;
    Nodo* actual = registro->primero;
    Nodo* siguiente;

    //Por qué arrancan en 1? porque medimos la lista enlazada con 1 como primer elemento, no con 0
    for (i = 1; i <= registro->cantidadDeNumeros; i++) {
        for (j = 1; j <= registro->cantidadDeNumeros - i; j++) {
            if (actual->siguiente == NULL) {break;};
            if (atoi(actual->linea) > atoi(actual->siguiente->linea)) {
                intercambioBubbleSort(registro, j);
            }
            else {
                actual = actual->siguiente;
            }
        }
        actual = registro->primero;
    }
    printf("\nMatriz ordenada:\n");
    imprimirMatriz(registro);
}

int main() {
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

    printf("Cantidad de elementos: %d\n", registro->cantidadDeNumeros);

    fclose(archivo);

    printf("\nMatriz original:\n");
    imprimirMatriz(registro);

    bubbleSort(registro);

    return 0;
}