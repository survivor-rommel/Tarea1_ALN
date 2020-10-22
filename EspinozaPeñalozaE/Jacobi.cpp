//Gauss Elimination
#include<iostream>
#define n 10
using namespace std;

void Jacobi(int l, float x[], float[][10], float b[]);
int main()
{
    int i, j, l, cont = 0;
    float x[n], a[n][n], b[n], dd, suma;
    cout << "Introduce numero de ecuaciones: ";
    cin >> l;
    cout << "Introduce la matriz de coeficientes: \n";
    for (i = 0;i < l;i++) {
        x[i] = 0;
        for (j = 0;j < l;j++) {
            cout << "a[" << i << "," << j << "]= ";
            cin >> a[i][j];
        }
    }
    cout << "Introduce el vector columna: \n";
    for (i = 0;i < l;i++) {
        cout << "b[" << i << "," << j << "]= ";
        cin>>b[i];
    }
    for (i = 0;i < l;i++) {
        suma = 0;
        for (j = 0;j < l;j++) {
            if (i == j) {
                dd = a[i][j];
            }
            else {
                suma = suma + a[i][j];
            }

        }
        if (dd > suma) {
            cont++;
        }
    }
    if (cont == 1) {
        Jacobi(l, x, a, b);
    }
    else {
        cout << "La matriz no es Diagonalmente Dominante, proceso terminado \n";
        return 0;
    }
    void Jacobi(int l, float x[], float a[][10], float b[]) {
        char p;
        float c[n];
        int k, i, j;
        for (k = 0;k < 10;k++) {
            for (i = 0;i < l;i++) {
                c[i] = b[i];
                for (j = 0;j < l;j++) {
                    if (i != j) {
                        c[i] = c[i] - a[i][j] * x[j];
                    }
                }
            }
            for (i = 0;i < n;i++) {
                x[i] = c[i] / a[i][i];
            }
        }
    }
    cout << "La solucion es: \n";
    for (i = 0;i < l;i++) {
        cout << "x(" << i << ") = " << x[i] << "\n";
    }
    return 0;
}