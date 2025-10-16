COMPARACIÓN ENTRE LOS ALGORITMOS DE ORDENACIÓN INSERCIÓN BINARIA Y RADIX SORT Y SU MEDICIÓN EN TÉRMINOS DE EFICIENCIA

OBJETIVOS
El objetivo de este proyecto es comparar el rendimiento de distintos algoritmos de ordenamiento, específicamente Inserción Binaria y Radix Sort, midiendo su tiempo de ejecución, número de comparaciones e intercambios. Los resultados se registran en un archivo resultados.csv para su  análisis y generación de gráficos o tablas.

CÓMO COMPILAR
Para compilar el código fuente en C++ (estándar C++17), ejecutar: g++ main.cpp -o benchmark -std=c++17
Asegúrate de tener instalado G++ versión 15.1.0 (o compatible con C++17).

CÓMO EJECUTAR EL BENCHMARK
Ejecuta el programa compilado desde la terminal:./benchmark
El programa pedirá los siguientes datos:
 	- Cantidad de elementos (ejemplo: 1000)
 	- Archivo CSV de entrada (ejemplo: array_1000.csv)
 	- Patrón de datos (aleatorio, ascendente, descendente)
 	- Luego se realizarán 30 repeticiones por algoritmo, midiendo el tiempo en nanosegundos, número de comparaciones e intercambios.
Los resultados se guardan en el archivo resultados.csv

CÓMO REGENERAR TABLAS Y FIGURAS
Abre el archivo resultados.csv con un programa como Excel, LibreOffice Calc o Python.
Analiza los datos promediando tiempos y comparaciones.
Genera gráficos de rendimiento (tiempo vs. tamaño de entrada, comparaciones vs. algoritmo)

VERSIONES DE COMPILADOR Y SISTEMA OPERATIVO
Sistema operativo: 	Windows 11 (64 bits)
Procesador: 		    Intel Core i5 (arquitectura x64)
Memoria RAM: 		    8 GB
Compilador: 		    G++ 15.1.0 (MSYS2 project)
Estándar: 		      C++17

SEMILLAS Y COMMIT HASH
commit: c2292fbcd08020091c8023adefa488508c24a436
Esta versión corresponde a la versión validada y usada para la obtención de los resultados reportados en el informe final.

ARCHIVOS PRINCIPALES
otros.h
Contiene funciones auxiliares:

leerCSV(): 		Lee una cantidad determinada de números desde un archivo.csv y los almacena en un arreglo.
imprimirArray():	Muestra por consola los valores del arreglo.

2 algoritmos.h
Incluye la implementación de los algoritmos de ordenamiento y funciones de apoyo:

RadixSort(): 		  Ordena un arreglo de números enteros por sus dígitos, contando comparaciones y movimientos.
 	- obtenerMax(): Devuelve el valor máximo de un arreglo (usado en Radix Sort).
InsercionBin(): 	Método de inserción que usa búsqueda binaria para reducir comparaciones.

3. main.cpp
Archivo principal del programa:
Solicita la cantidad de elementos del arreglo.
Pide el nombre del archivo CSV que contiene los datos.
Solicita el patrón de los datos.
Ejecuta ambos algoritmos (Insercion Binaria y Radix Sort) 30 veces cada uno, midiendo:

 	- Tiempo de ejecución en nanosegundos.
 	- Número de comparaciones.
 	- Número de intercambios o movimientos.

Registra los resultados en el archivo resultados.csv con las siguientes columnas:
algoritmo: 		    Nombre del método de ordenamiento utilizado.
n: 			          Tamaño del arreglo que se ordenó.
patron: 		      Tipo o patrón de los datos usados.
repetición: 		  Número de la ejecución o prueba.
tiempo_ns: 		    Tiempo total que tardó el algoritmo en ordenar el arreglo, medido en microsegundos.
comparaciones:		Número total de comparaciones realizadas entre elementos durante el ordenamiento.
intercambios:		  Cantidad de movimientos o asignaciones realizadas para reordenar los elementos.
