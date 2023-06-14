#include "ArbolBinario.h"

// Función para crear un nuevo nodo del árbol
NodoArbol* crearNodoArbol(int valor) {
    NodoArbol* nodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nodo->valor = valor;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

// Función para insertar un valor en el árbol binario
NodoArbol* insertarNodoArbol(NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodoArbol(valor);
    }

    if (valor < raiz->valor) {
        raiz->izquierdo = insertarNodoArbol(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = insertarNodoArbol(raiz->derecho, valor);
    }

    return raiz;
}

// Función para construir el árbol binario a partir de un archivo
NodoArbol* construirArbol(const char* numeros) {
    FILE* archivo = fopen(numeros, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return NULL;
    }

    NodoArbol* raiz = NULL;
    int valor;

    // Leer los valores del archivo y construir el árbol
    while (fscanf(archivo, "%d", &valor) == 1) {
        raiz = insertarNodoArbol(raiz, valor);
    }

    fclose(archivo);
    return raiz;
}

// Función auxiliar para imprimir el árbol en orden (in-order traversal)
void imprimirArbol(NodoArbol *raiz, int nivel)
{
    if (raiz == NULL) {
        return;
    }

    imprimirArbol(raiz->derecho, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("    |    ");
    }

    printf("%d\n\n", raiz->valor);

    imprimirArbol(raiz->izquierdo, nivel + 1);
}