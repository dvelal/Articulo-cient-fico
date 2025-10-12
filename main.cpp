#include "algoritmos.h"
#include "otros.h"
#include <chrono>
#include <iostream>
using namespace std;

int main(){
    const int n = 1000;
    int A[n];


    for (long i = 0; i < 30; i ++){
        if (!leerCSV("array_1000.csv", A, n)) {
            return 1; // error al leer archivo
        }

        auto inicio = chrono::steady_clock::now();

        interDirDer(A, n);

        auto fin = chrono::steady_clock::now();
        cout << "========================" << endl;
        cout << chrono::time_point_cast<chrono::nanoseconds>(inicio).time_since_epoch().count() << endl; //Punto en el tiempo (inicio del conteo)
        cout << chrono::time_point_cast<chrono::nanoseconds>(fin).time_since_epoch().count() << endl; //Punto en el tiempo (fin del conteo)
        cout << "Time difference = " << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count() << "[ns]" << endl;
        cout << chrono::duration_cast<chrono::microseconds>(fin - inicio).count() << "[us]" << endl;
        cout << chrono::duration_cast<chrono::milliseconds>(fin - inicio).count() << "[ms]" << endl;
    }
    return 0;
}
