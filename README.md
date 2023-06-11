# Estructura del proyecto

## MenuPrincipal

* ```main``` maneja la ejecución.
* Recién cuando el usuario entra al programa se ejecuta ```CreacionDeLista```.
* Si hay que ordenar se ocupan las funciones de ```ManejarOrdenamiento```.
* Si es busqueda secuencial ocupa ```BusquedaSecuencial```. Se debería añadir un archivo ```ManejoBusquedas```.
* Todas estos modulos dependen de las estructuras y métodos definidos en ```Estructuras```.