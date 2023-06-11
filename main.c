#include <stdio.h>
#include "Estructuras.h"
#include "CreacionDeLista.h"
#include "ManejarOrdenamientos.h"

void printOpciones()
{
    system("cls");
    printf("\nMenú:\n");
    printf("a) Imprimir lista enlazada\n");
    printf("b) Aplicar los diferentes métodos de ordenamiento y mostrar el resultado\n");
    printf("c) Aplicar la búsqueda secuencial y binaria de un número en la lista\n");
    printf("d) Insertar un número nuevo en la lista original y en la lista ordenada\n");
    printf("e) Mostrar el menor y mayor valor de la lista original y la lista ordenada\n");
    printf("f) Armar un árbol con la lista original y mostrar el resultado\n");
    printf("g) Salir\n");
    printf("Ingrese una opción: ");
}

void printOpcionesOrdenamiento()
{
    printf("\nMétodos de ordenamiento disponibles:\n");
    printf("1) Burbuja\n");
    printf("2) Inserción\n");
    printf("3) Selección\n");
    printf("4) Ordenación Rápida\n");
    printf("5) Volver al menú principal\n");
    printf("Ingrese una opción de ordenamiento: ");
}

int main()
{
    int opcion;
    int opcionOrdenamiento;
    Registro* registro = CreacionDeLista;

    do
    {
        printOpciones();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 'a':
            printf("Opción a seleccionada. Crear lista enlazada.\n");
            // Lógica para crear la lista
            break;

        case 'b':
            printf("Opción b seleccionada. Aplicar métodos de ordenamiento.\n");
            do
            {
                printOpcionesOrdenamiento();
                scanf("%d", &opcionOrdenamiento);

                switch (opcionOrdenamiento)
                {
                case 1:
                    metodoBurbuja(registro);
                    break;

                case 2:
                    metodoInsercion(registro);
                    break;

                case 3:
                    metodoSeleccion(registro);
                    break;

                case 4:
                    metodoOrdenacionRapida(registro);
                    break;

                case 5:
                    printf("Volviendo al menú principal...\n");
                    break;

                default:
                    printf("Opción de ordenamiento inválida. Intente nuevamente.\n");
                    break;
                }
            } while (opcionOrdenamiento != 5);

            break;

        case 'c':
            printf("Opción c seleccionada. Aplicar búsqueda secuencial y binaria.\n");
            // Lógica para aplicar la búsqueda secuencial y binaria y mostrar resultados
            break;

        case 'd':
            printf("Opción d seleccionada. Insertar número nuevo.\n");
            // Lógica para insertar un número nuevo en la lista original y en la lista ordenada
            break;

        case 'e':
            printf("Opción e seleccionada. Mostrar menor y mayor valor.\n");
            // Lógica para mostrar el menor y mayor valor de la lista original y la lista ordenada
            break;

        case 'f':
            printf("Opción f seleccionada. Armar árbol con la lista original.\n");
            // Lógica para armar el árbol con la lista original y mostrar el resultado
            break;

        case 'g':
            printf("Opción g seleccionada. Salir.\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 'g');

    return 0;
}
