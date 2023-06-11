#include "CreacionDeLista.h"    

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