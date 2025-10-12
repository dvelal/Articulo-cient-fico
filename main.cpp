#include "algoritmos.h"
#include "otros.h"
#include <chrono>
#include <iostream>
using namespace std;

int main(){
    const int n = 1000;
    int A[n];

    if (!leerCSV("array_1000.csv", A, n)) {
        return 1; // error al leer archivo
    }

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    interDirDer(A, n);

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
    
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[us]" << endl;
    
    cout << "Time difference = ";
    cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "[ns]" << endl;

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
