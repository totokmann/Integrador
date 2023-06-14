# Estructura del proyecto

## MenuPrincipal

* ```main``` maneja la ejecución.
* Recién cuando el usuario entra al programa se ejecuta ```CreacionDeLista```.
* Si hay que ordenar se ocupan las funciones de ```ManejarOrdenamiento```.
* Para las búsquedas ```ManejoBusquedas```.
* Todas estos modulos dependen de las estructuras y métodos definidos en ```Estructuras```.
* Los arboles están definidos en ```ArbolBinario```.

# Donde está cada actividad? 
* a) crear una lista enlazada con 100 números distintos y desordenados, no consecutivos
    * Se crea la lista con el ejecutable ```RandomNumbers```
    * Se lee el archivo de texto creado con ```Estructuras.c```

* b) aplicar los diferentes métodos de ordenamiento (burbuja,inserción,selección, ordenación rápida), tomar el tiempo de cada uno y mostrar por pantalla el resultado indicando el método aplicado.
    * En la carpeta "Sorts" están todos los algoritmos, se manejan con el archivo ```ManejarOrdenamientos```

* c) aplicar la búsqueda secuencial y binaria de un número de la lista ingresado por
teclado, primero sobre la lista sin ordenar y luego sobre la lista ordenada según método
de inserción. Para cada caso tomar el tiempo y mostrarlo.
    * ```ManejarBusquedas``` tiene los algoritmos y controla cada uno.

* d) Insertar un número nuevo. Hacer la inserción sobre la lista original, y sobre la lista
ordenada por el método de inserción, tomar el tiempo y mostrar la lista origen, resultado y el tiempo. Probar con un número menor o igual al menor existente, mayor o igual al mayor existente, y un valor medio de los existentes, tomar el tiempo de cada operación y mostrarlo.
    * También dentro de ```ManejarBusquedas```, la función ```insercionDeNumero```.

* e) Mostrar el menor y mayor valor de la lista, primero sobre la lista original y luego sobre la lista ordenada por el método inserción, tomar los tiempos y mostrar los resultados.
    * También dentro de ```ManejarBusquedas```, la función ```encontrarMaximoMinimo```
    
* f) Con la lista original armar un árbol, donde la raíz sea el valor medio de todas los números y luego ir insertando nodos de acuerdo a que si el valor es menor que la raíz se agrega a la izquierda y si es mayor se agrega a la derecha. Mostrar el resultado
    * ```ArbolBinario``` define la estructura y los métodos.