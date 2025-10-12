#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
using namespace std;

long long obtenerMax(long long A[], long long n){
    long long max=A[0];
    for(long long i=1; i<n; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}

void RadixSort(long long A[],long long n){
    long long max=obtenerMax(A,n);

    for(long long peso=1; max/peso>0 ; peso=peso*10){

        long long urna[10][n];
        long long cuenta[10]={0};

        for(long long i=0; i<n; i++){
            long long digito = (A[i]/peso) % 10;
            urna[digito][cuenta[digito]++]=A[i];
        }

        long long idx=0; 
        for(long long i=0; i<10; i++){
            for(long long j=0; j<cuenta[i]; j++){
                A[idx++]=urna[i][j];
            }
        }
    }
}

void InsercionBin(long long A[], long long n) {
    for (long long i = 1; i < n; i++) {	
        long long aux = A[i];				
        long long izq = 0;				
        long long der = i - 1;			
        while (izq <= der) {		
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
        }
        A[izq] = aux;
    }
}
#endif