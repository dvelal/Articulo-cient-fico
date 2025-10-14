#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
using namespace std;

long long obtenerMax(long long A[], long long n, long long &comparaciones) {
    long long max = A[0];
    for (long long i = 1; i < n; i++) {
        comparaciones++;
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void RadixSort(long long A[], long long n, long long &comparaciones, long long &movimientos) {
    long long max = obtenerMax(A, n, comparaciones);

    for (long long peso = 1; max / peso > 0; peso = peso * 10) {
        comparaciones++;

        long long urna[10][n];
        long long cuenta[10] = {0};

        for (long long i = 0; i < n; i++) {
            long long digito = (A[i] / peso) % 10;
            comparaciones++;
            urna[digito][cuenta[digito]++] = A[i];
            movimientos++;
        }

        long long idx = 0;
        for (long long i = 0; i < 10; i++) {
            for (long long j = 0; j < cuenta[i]; j++) {
                A[idx++] = urna[i][j];
                movimientos++;
            }
        }
    }
}

void InsercionBin(long long A[], long long n, long long &comparaciones, long long &intercambios) {
    comparaciones = 0;
    intercambios = 0;
    for (long long i = 1; i < n; i++) {
        long long aux = A[i];
        long long izq = 0;
        long long der = i - 1;
        while (izq <= der) {
            comparaciones++;
            long long m = (izq + der) / 2;
            if (aux < A[m])
                der = m - 1;
            else
                izq = m + 1;
        }
        long long j = i - 1;
        while (j >= izq) {
            A[j + 1] = A[j];
            j--;
            intercambios++;
        }
        A[izq] = aux;
        intercambios++;
    }
}
#endif