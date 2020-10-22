/*
La funcion jacobi() solicita datos que deben ingresarse de la forma:
Ej. si las ecuaciones son:
    3x + 2y = 20
    4x + 3y = 30

cuando se solicite COEFICIENTES debe ingresarse:
    Fila 1: 3 2
    Fila 2: 4 3
cuando se solicite SOLUCIONES debe ingresarse:
    valores: 20 30
cuando se solicite APROXIMACION debe ingresarse:
    valores: 0 0 (por ejemplo)
ITERACION: es la cantidad de vueltas que dará para resolver Jacobi
*/

#include<iostream>
#include <iomanip>
using namespace std;

void crearMatriz(float** &A, int f, int c)
{
    A = new float*[f];
    for(int i = 0; i < f; i++)
        A[i] = new float[c];
}

float sumatoriaJ(float** A, int n, int i, float* V)
{
    float s = 0;
    for(int j = 0; j < n; j++)
        if(i!=j)
            s = s + A[i][j]*V[j];
    return s;
}

void jacobi()
{
    int n, it;
    cout << "Cant. Filas : "; cin >> n; cout << endl;

    float** A;      // matriz de coeficientes
    crearMatriz(A, n, n);

    float* B = new float[n];    // array de soluciones
    float* V = new float[n];    // array de aproximaciones


    cout << "### Valores para la matriz de COEFICIENTES ###" << endl;
    cout << "Ingrese valores separados por espacios: " << endl << endl;
    for(int i = 0; i < n; i++) {
        cout << "     fila " << i+1 << ": ";
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
    }

    cout << "\n### Valores para el array de SOLUCIONES ###" << ": " << endl;
    cout << "Ingrese valores separados por espacios: "<< endl << endl;
    cout << "     valores: ";
    for(int i = 0; i < n; i++)
        cin >> B[i];

    cout << "\n### Valores para el vector de APROXIMACION ### " << ": " << endl;
    cout << "Ingrese valores separados por espacios: "<< endl << endl;
    cout << "     valores: ";
    for(int i = 0; i < n; i++)
        cin >> V[i];

    cout << "\n### Ingrese la cantidad de ITERACIONES: ";
    cin >>it;
    cout << endl;


    for(int j = 0; j < it; j++)
    {
        for(int i = 0; i < n; i++)
        {
            V[i] = (1 / A[i][i]) * (B[i] - sumatoriaJ(A, n, i, V));  // FORMULA ITERATIVA PAR EJECUTAR JACOBI
            cout << fixed << setprecision(3) << V[i] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    jacobi();
    return 0;
}

