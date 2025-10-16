#include<iostream>
using namespace std; 
int obtenerMax(int A[], int);
void RadixSort(int A[],int);
int main(){
    int n; 
    cout<<"Ingrese el numero de elementos: ";
    cin>>n; 
    int A[n];
    cout<<"Ingrese los elemento: ";
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    RadixSort(A,n);

    cout<<"Arreglo ordenado: ";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0; 
}

int obtenerMax(int A[], int n){
    int max=A[0];
    for(int i=1; i<n; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}

void RadixSort(int A[],int n){
    int max=obtenerMax(A,n);

    for(int peso=1; max/peso>0 ; peso=peso*10){

        int urna[10][n];
        int cuenta[10]={0};

        for(int i=0; i<n; i++){
            int digito = (A[i]/peso) % 10;
            urna[digito][cuenta[digito]++]=A[i];
        }

        int idx=0; 
        for(int i=0; i<10; i++){
            for(int j=0; j<cuenta[i]; j++){
                A[idx++]=urna[i][j];
            }
        }
    }
}