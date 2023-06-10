#include <stdio.h>

int busqueda_secuencial(FILE *archivo, int elemento_buscado) {
    int numero;
    int posicion = 1;

    // Leer cada número del archivo
    while (fscanf(archivo, "%d", &numero) != EOF) {
        // Comparar el número con el elemento buscado
        if (numero == elemento_buscado) {
            return posicion;  // Devuelve la posición (número de elemento) donde se encontró el número
        }
        posicion++;
    }

    return -1;  // Devuelve -1 si el número no se encuentra en el archivo
}

int main() {
    FILE *archivo;
    const char *nombre_archivo = "numeros.txt";
    int elemento;

    // Pedir al usuario que ingrese el número a buscar
    printf("Ingrese el número que desea buscar: ");
    scanf("%d", &elemento);

    // Abrir el archivo en modo lectura
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Realizar la búsqueda secuencial en el archivo
    int posicion = busqueda_secuencial(archivo, elemento);
    if (posicion != -1) {
        printf("El número se encuentra en la posición %d.\n", posicion);
    } else {
        printf("El número no se encuentra en el archivo.\n");
    }

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}
