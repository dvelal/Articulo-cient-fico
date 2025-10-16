#include<iostream>
using namespace std;
void InsercionBin(long long A[], long long n) {
 	long long comparaciones= 0;  	//contador de comparaciones
    long long intercambios= 0;    	//contador de movimientos
    for (int i = 1; i < n; i++) {	//recorre desde el segundo elemento y comienza en 1 porque A[0] ya esta disque ordenado
        long long aux = A[i];		//guarda temporalmente el elemento actual
        long long izq = 0;			//limite izquierdo para la busqueda binaria
        long long der = i - 1;		//limite derecho: parte del arreglo ya ordenado
//busqueda binaria para encontrar la posicion de insercion
        while (izq <= der) {		//mientras no se haya reducido el rango de busqueda
			comparaciones++;
            long long m = (izq + der) / 2;//calcula la posicion media del rango
            if (aux < A[m])			//si el elemento es menor que el del medio
                der = m - 1;		//se mueve el limite derecho hacia la izquierda
            else
                izq = m + 1;		//se mueve el limite izquierdo hacia la derecha
        }
//mover los elementos a la derecha para hacer espacio
        long long j = i - 1;		//comienza desde el elemento anterior a i
        while (j >= izq) {			//mientras haya elementos mayores al valor a insertar
            A[j + 1] = A[j];		//desplaza los elementos una posicion a la derecha
            j--;					//retrocede una posicion
            intercambios++;
        }
//insertar el elemento en su posicion
        A[izq] = aux;				//inserta el valor en la posicion correcta
        intercambios++;
    }
    cout << "Comparaciones: "<< comparaciones << endl;
    cout << "Intercambios:  "<< intercambios << endl;
}
int main() {
    long long n;
    cout << "Ingrese el numero de elementos: ";
    cin >> n;
    long long A[n];
    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    InsercionBin(A, n);
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}