#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un nodo al final de la lista enlazada
void insertarNodo(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista enlazada
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para realizar la búsqueda binaria en la lista enlazada
Nodo* busquedaBinaria(Nodo* cabeza, int elemento) {
    Nodo* inicio = cabeza;
    Nodo* fin = NULL;
    
    while (inicio != fin) {
        Nodo* medio = inicio;
        int longitud = 0;
        
        // Calcular la longitud de la sublista
        while (medio != fin) {
            longitud++;
            medio = medio->siguiente;
        }
        
        // Obtener el elemento medio
        medio = inicio;
        for (int i = 0; i < longitud / 2; i++) {
            medio = medio->siguiente;
        }
        
        // Realizar la comparación con el elemento medio
        if (medio->dato == elemento) {
            return medio;  // Elemento encontrado
        } else if (medio->dato > elemento) {
            fin = medio;
        } else {
            inicio = medio->siguiente;
        }
    }
    
    return NULL;  // Elemento no encontrado
}

int main() {
    Nodo* cabeza = NULL;

    // Abrir el archivo de números
    FILE* numeros = fopen("numeros.txt", "r");
    if (numeros == NULL) {
        printf("No se pudo abrir el numeros.\n");
        return 1;
    }

    // Leer los números del numeros y crear la lista enlazada
    int numero;
    while (fscanf(numeros, "%d", &numero) != EOF) {
        insertarNodo(&cabeza, numero);
    }

    // Cerrar el numeros
    fclose(numeros);

    // Imprimir la lista enlazada
    printf("Lista enlazada: ");
    imprimirLista(cabeza);

    // Realizar la búsqueda binaria
    int elemento;
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &elemento);

    Nodo* resultado = busquedaBinaria(cabeza, elemento);
    if (resultado != NULL) {
        printf("Elemento encontrado: %d\n", resultado->dato);
    } else {
        printf("Elemento no encontrado.\n");
    }

    return 0;
}
