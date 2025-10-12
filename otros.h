#ifndef OTROS_H
#define OTROS_H

#include <iostream>
#include <fstream>
using namespace std;

bool leerCSV(const string& Archivo, long long arr[], long long n) {
    ifstream archivo(Archivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << Archivo << endl;
        return false;
    }

    long long num;
    char coma;
    for (long long i = 0; i < n; i++) {
        if (!(archivo >> num)) {
            cerr << "Error leyendo numero " << i << endl;
            return false;
        }
        arr[i] = num;
        archivo >> coma; 
    }
    archivo.close();
    return true;
}

void imprimirArray(long long arr[], long long n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif
