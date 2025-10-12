#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
using namespace std;

int obtenerMax(int A[], int n, int &comparaciones){
    int max=A[0];
    for(int i=1; i<n; i++){
        comparaciones++; 
        if(A[i] > max){
            max=A[i];
        }
    }
    return max;
}

void RadixSort(int A[], int n, int &comparaciones, int &movimientos){
    int max = obtenerMax(A, n, comparaciones);

    for(int peso = 1; max/peso > 0; peso = peso * 10){
        comparaciones++; 

        int urna[10][n];
        int cuenta[10]={0};

        for(int i = 0; i < n; i++){
            int digito = (A[i]/peso) % 10;
            comparaciones++; 
            urna[digito][cuenta[digito]++] = A[i];
            movimientos++; 
        }

        int idx = 0; 
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < cuenta[i]; j++){
                A[idx++] = urna[i][j];
                movimientos++; 
            }
        }
    }
}


#endif