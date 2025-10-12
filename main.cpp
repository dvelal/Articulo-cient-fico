#include "algoritmos.h"
#include "otros.h"
#include <chrono>
#include <iostream>
using namespace std;

int main(){
    const int n = 1000;
    int A[n];
    int B[n];


    for (long i = 0; i < 30; i ++){
        if (!leerCSV("array_1000.csv", A, n))
            return 1; // error al leer archivo
        if (!leerCSV("array_1000.csv", B, n))
            return 1; // error al leer archivo

        auto inicio1 = chrono::steady_clock::now();
        InsercionBin(A, n);
        auto fin1 = chrono::steady_clock::now();

        
        auto inicio2 = chrono::steady_clock::now();
        shellsort(B, n);
        auto fin2 = chrono::steady_clock::now();

        cout << "========================" << endl;
        cout << "------------------------" << endl;
        cout << chrono::time_point_cast<chrono::nanoseconds>(inicio1).time_since_epoch().count() << endl; //Punto en el tiempo (inicio del conteo)
        cout << chrono::time_point_cast<chrono::nanoseconds>(fin1).time_since_epoch().count() << endl; //Punto en el tiempo (fin del conteo)
        cout << chrono::time_point_cast<chrono::nanoseconds>(inicio2).time_since_epoch().count() << endl;
        cout << chrono::time_point_cast<chrono::nanoseconds>(fin2).time_since_epoch().count() << endl;
        cout << "------------------------" << endl;

        cout << "Tiempo Algoritmo de Insercion Binaria = " << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(fin1 - inicio1).count() << "[ns]" << endl;
        cout << chrono::duration_cast<chrono::microseconds>(fin1 - inicio1).count() << "[us]" << endl;
        cout << chrono::duration_cast<chrono::milliseconds>(fin1 - inicio1).count() << "[ms]" << endl;

        cout << "Tiempo Algoritmo de RadixSort = " << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(fin2 - inicio2).count() << "[ns]" << endl;
        cout << chrono::duration_cast<chrono::microseconds>(fin2 - inicio2).count() << "[us]" << endl;
        cout << chrono::duration_cast<chrono::milliseconds>(fin2 - inicio2).count() << "[ms]" << endl;
    }

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    return 0;
}
