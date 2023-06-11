#include <stdio.h>
#include "Estructuras.h"
#include "CreacionDeLista.h"
#include "ManejarOrdenamientos.h"

void printOpciones()
{
    printf("\nMenu:\n");
    printf("1) Imprimir lista enlazada\n");
    printf("2) Aplicar los diferentes metodos de ordenamiento y mostrar el resultado\n");
    printf("3) Aplicar la busqueda secuencial y binaria de un numero en la lista\n");
    printf("4) Insertar un numero nuevo en la lista original y en la lista ordenada\n");
    printf("5) Mostrar el menor y mayor valor de la lista original y la lista ordenada\n");
    printf("6) Armar un arbol con la lista original y mostrar el resultado\n");
    printf("7) Salir\n");
    printf("Ingrese una opcion: ");
}

void printOpcionesOrdenamiento()
{
    printf("\nMetodos de ordenamiento disponibles:\n");
    printf("1) Burbuja\n");
    printf("2) Insercion\n");
    printf("3) Seleccion\n");
    printf("4) Ordenacion Rapida\n");
    printf("5) Volver al menu principal\n");
    printf("Ingrese una opcion de ordenamiento: ");
}

int main()
{
    int opcion;
    int opcionOrdenamiento;
    Registro *registro = CreacionDeLista();

    do
    {
        printOpciones();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("La lista es:\n");
            imprimirMatriz(registro);
            printf("\nIngrese 0 para volver al menu principal...\n");
            do
            {
                scanf("%d", &opcion);
            } while (opcion != 0);
            break;

        case 2:
            printf("Opcion 2 seleccionada. Aplicar metodos de ordenamiento.\n");
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
                    printf("Volviendo al menu principal...\n");
                    break;

                default:
                    printf("Opcion de ordenamiento invalida. Intente nuevamente.\n");
                    break;
                }
            } while (opcionOrdenamiento != 5);

            break;

        case 3:
            printf("Opcion 3 seleccionada. Aplicar busqueda secuencial y binaria.\n");
            // Logica para aplicar la busqueda secuencial y binaria y mostrar resultados
            break;

        case 4:
            printf("Opcion 4 seleccionada. Insertar numero nuevo.\n");
            // Logica para insertar un numero nuevo en la lista original y en la lista ordenada
            break;

        case 5:
            printf("Opcion 5 seleccionada. Mostrar menor y mayor valor.\n");
            // Logica para mostrar el menor y mayor valor de la lista original y la lista ordenada
            break;

        case 6:
            printf("Opcion 6 seleccionada. Armar arbol con la lista original.\n");
            // Logica para armar el arbol con la lista original y mostrar el resultado
            break;

        case 7:
            printf("Opcion 7 seleccionada. Salir.\n");
            break;

        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 7);

    return 0;
}