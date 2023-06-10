#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numeroRepetido(int numeros[], int indice, int numero) {
    int i;
    for (i = 0; i < indice; i++) {
        if (numeros[i] == numero) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int numeros[100];
    FILE* archivo;
    int i, numero;

    // Semilla para generar números aleatorios
    srand(time(NULL));

    // Generar 100 números aleatorios sin repeticiones
    for (i = 0; i < 100; i++) {
        do {
            numero = rand() % 1000 + 1;
        } while (numeroRepetido(numeros, i, numero));

        numeros[i] = numero;
    }

    // Crear el archivo y escribir los números
    archivo = fopen("C:\\TDM-GCC-64\\numeros.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }

    for (i = 0; i < 100; i++) {
        fprintf(archivo, "%d\n", numeros[i]);
    }

    fclose(archivo);

    printf("Archivo 'numeros.txt' creado con éxito.\n");

    return 0;
}
