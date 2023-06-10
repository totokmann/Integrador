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
    } else {
        registro->ultimo->siguiente = nuevoNodo;
        registro->ultimo = nuevoNodo;
    }
    registro->cantidadDeNumeros+=1;
    return;
}

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

// Función para ordenar el registro utilizando el método burbuja
void ordenarRegistro(Registro* registro) {
    int n = registro->cantidadDeNumeros;
    printf("\nCantidad de numeros: %d\n", n);
    Nodo* actual;
    Nodo* siguiente;
    int cambioRealizado;

    //Iteramos sobre i, hasta la cantidad de numeros - 1
    for (int i = 0; i < n - 1; i++) {
        printf("\nIteración en i: %d\n", i);
        printf("Iteracion %i: %i\n", i, n);
        actual = registro->primero;
        siguiente = actual->siguiente;
        cambioRealizado = 0;

        //iteramos sobre j hasta la cantidad de numeros - el i previo - 1
        //O sea, recorremos j veces hasta el número de elementos menos el i iterado.
        //Esto nos permite ir desde el nodo actual hasta todos los que quedan "hacia la derecha"
        for (int j = 0; j < n - i - 1; j++) {
            printf("Iteracion %i: %i\n", j, n);
            int numeroActual = atoi(actual->linea);
            int numeroSiguiente = atoi(siguiente->linea);

            // Si el numero "a la izquierda" es mayor al de la derecha lo movemos a la derecha
            if (numeroActual > numeroSiguiente) {
                // Realizar intercambio de nodos
                Nodo* temp = actual;
                actual = siguiente;
                siguiente = temp;
                //Si era el primero lo inserta como primero en el registro
                if (j == 0) {
                    registro->primero = actual;
                } else {
                    Nodo* nodoAnterior = registro->primero;
                    for (int k = 0; k < j - 1; k++) {
                        nodoAnterior = nodoAnterior->siguiente;
                    }
                    nodoAnterior->siguiente = actual;
                }
                //En cualquier caso se registra como siguiente al previo
                actual->siguiente = siguiente;
                temp->siguiente = siguiente->siguiente;
                siguiente->siguiente = temp;

                cambioRealizado = 1;
            }

            actual = actual->siguiente;
            siguiente = siguiente->siguiente;
        }

        if (!cambioRealizado) {
            // Si no se realizó ningún intercambio en la primera iteración, el registro ya está ordenado
            break;
        }
    }
    printf("Matriz ordenada:\n");
    return;
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
    printf("cantidad de elementos: %d\n", registro->cantidadDeNumeros);

    fclose(archivo);
    imprimirMatriz(registro);
    ordenarRegistro(registro);
    imprimirMatriz(registro);
    return 0;
}