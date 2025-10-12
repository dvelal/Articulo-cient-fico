#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
using namespace std;

void interDirDer(int A[], int n) {
    int aux;
    for (int i = 0; i < n - 1; ++i) {     
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

#endif