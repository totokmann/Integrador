#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    int linea[3];
    struct Nodo* siguiente;
} Nodo;

typedef struct Registro {
    int cantidadDeNumeros;
    Nodo *primero;
    Nodo *ultimo;
} Registro;

// Función para crear un nuevo nodo
Nodo* crearNodo(char* linea) {
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
        registro->cantidadDeNumeros ++;
    } else {
        registro->ultimo->siguiente = nuevoNodo;
        registro->ultimo = nuevoNodo;
        registro->cantidadDeNumeros ++;
    }
}

// Función para imprimir la lista enlazada
void imprimirLista(Registro* registro) {
    Nodo* actual = registro->primero;
    while (actual != NULL) {
        printf("%s\n", actual->linea);
        actual = actual->siguiente;
    }
    return;
}

int main() {

    Registro* registro = (Registro*)malloc(sizeof(Registro));
    registro->primero = NULL;
    registro->ultimo = NULL;
    registro->cantidadDeNumeros = 0;

    char nombreArchivo[] = "numero.txt"; // Nombre del archivo a leer
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    Nodo* inicio = NULL; // Cabeza de la lista enlazada
    int linea[3];
    
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Crear un nuevo nodo con la línea actual
        Nodo* nuevoNodo = crearNodo(linea);
        insertarNodo(registro, nuevoNodo);
    }

    fclose(archivo);
    imprimirLista(registro);

    return 0;
}
