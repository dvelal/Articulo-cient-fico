#ifndef OTROS_H
#define OTROS_H

#include <iostream>
#include <fstream>
using namespace std;

bool leerCSV(const string& Archivo, int arr[], int n) {
    ifstream archivo(Archivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << Archivo << endl;
        return false;
    }

    int num;
    char coma;
    for (int i = 0; i < n; i++) {
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

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif
