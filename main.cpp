#include "algoritmos.h"
#include "otros.h"
#include <chrono>
#include <iostream>
using namespace std;

int main(){
    const long long n = 1000;
    long long A[n];
    long long B[n];


    for (long long i = 0; i < 30; i ++){
        if (!leerCSV("array_1000.csv", A, n))
            return 1; // error al leer archivo
        if (!leerCSV("array_1000.csv", B, n))
            return 1; // error al leer archivo

        auto inicio1 = chrono::steady_clock::now();
        InsercionBin(A, n);
        auto fin1 = chrono::steady_clock::now();

        auto inicio2 = chrono::steady_clock::now();
        RadixSort(B, n);
        auto fin2 = chrono::steady_clock::now();

        cout << "========================" << endl;

        cout << "Tiempo Algoritmo de Insercion Binaria = " << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(fin1 - inicio1).count() << "[ns]" << endl;
        cout << chrono::duration_cast<chrono::microseconds>(fin1 - inicio1).count() << "[us]" << endl;

        cout << "Tiempo Algoritmo de RadixSort = " << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(fin2 - inicio2).count() << "[ns]" << endl;
        cout << chrono::duration_cast<chrono::microseconds>(fin2 - inicio2).count() << "[us]" << endl;
    }

    return 0;
}
