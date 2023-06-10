#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    char linea[4];  // Cambio en el tipo de datos a cadena de caracteres
    struct Nodo* siguiente;
} Nodo;

typedef struct Registro {
    int cantidadDeNumeros;
    Nodo* primero;
    Nodo* ultimo;
} Registro;

// Función para crear un nuevo nodo
Nodo* crearNodo(char linea[4]) {  // Cambio en el tipo de parámetro
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nodo->linea, linea);  // Uso de strcpy para copiar la cadena
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un nodo al final de la lista enlazada
void insertarNodo(Registro* registro, Nodo* nuevoNodo) {
    if (registro->primero == NULL) {
        registro->primero = nuevoNodo;
        registro->ultimo = nuevoNodo;
        registro->cantidadDeNumeros++;
    } else {
        registro->ultimo->siguiente = nuevoNodo;
        registro->ultimo = nuevoNodo;
        registro->cantidadDeNumeros++;
    }
}

void imprimirMatriz(Registro* registro) {
    Nodo* actual = registro->primero;
    int columna = 0;
    while (actual != NULL) {
        printf("%3s", actual->linea);
        columna++;
        if (columna % 10 == 0) {
            printf("\n");
            if (actual->siguiente != NULL) {
                for (int i = 0; i < 10; i++) {
                    if (i == 0) {printf("----|");}
                    else {printf("-----|");}
                }
                printf("\n");
            }
        } else {
            printf(" | ");
        }
        actual = actual->siguiente;
    }
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

    fclose(archivo);
    imprimirMatriz(registro);

    // Liberar la memoria de la lista enlazada
    Nodo* actual = registro->primero;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(registro);

    return 0;
}