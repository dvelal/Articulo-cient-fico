#include "algoritmos.h"
#include "otros.h"
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

int main(){
    long long n;
    cout << "Cantidad de elementos:" << endl;
    cin >> n;
    cin.ignore();
    string m;
    cout << "Archivo.csv:" << endl;
    getline(cin, m);
    long long A[n];
    long long B[n];
    string patron;
    cout << "Patron" << endl;
    getline(cin, patron);

    ofstream archivo("resultados.csv");
    archivo << "algoritmo,n,patron,repeticion,tiempo_ns,comparaciones,intercambios\n";
    archivo << "\n";

    for (long long i = 0; i < 30; i ++){
        if (!leerCSV(m.c_str(), A, n))
            return 1; // error al leer archivo

        long long comp = 0;
        long long inter = 0;

        auto inicio1 = chrono::steady_clock::now();
        InsercionBin(A, n, comp, inter);
        auto fin1 = chrono::steady_clock::now();

        auto tiempo1 = chrono::duration_cast<chrono::nanoseconds>(fin1 - inicio1).count();

        archivo << "Insercion Binaria," << n << "," << patron << "," << (i + 1) << ","
        << tiempo1 << "," << comp << "," << inter << "\n";
    }

    archivo << "\n";

    for (long long i = 0; i < 30; i ++){
        if (!leerCSV(m.c_str(), B, n))
            return 1;

        long long comp = 0;
        long long inter = 0;

        auto inicio2 = chrono::steady_clock::now();
        RadixSort(B, n, comp, inter);
        auto fin2 = chrono::steady_clock::now();

        auto tiempo2 = chrono::duration_cast<chrono::nanoseconds>(fin2 - inicio2).count();

        archivo << "Radix sort," << n << "," << patron << "," << (i + 1) << ","
        << tiempo2 << "," << comp << "," << inter << "\n";
    }
    archivo.close();
    return 0;
}
