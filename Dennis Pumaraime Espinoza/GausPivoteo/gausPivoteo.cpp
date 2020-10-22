/*
La funcion GaussPivoteoParcial() solicita datos que deben ingresarse de la forma:
Ej. si las ecuaciones son:
    3x + 2y = 20
    4x + 3y = 30
entonces cuando se solicite valores debe ingresarse:
    Fila 1: 3 2 20
    Fila 2: 4 3 30
*/

#include<iostream>
#include <iomanip>
using namespace std;

void cambiarFila(float** &A, int col, int fila1, int fila2)
{
    float tmp;
    for(int i = 0; i< col; i++)
    {
        tmp = A[fila1][i];
        A[fila1][i] = A[fila2][i];
        A[fila2][i] = tmp;
    }
}

void crearMatriz(float** &A, int f, int c)
{
    A = new float*[f];
    for(int i = 0; i < f; i++)
        A[i] = new float[c];
}

void mostrarMatriz(float **matriz, int f,int c)
{
    cout << endl;
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            cout << fixed << setprecision(3) << matriz[i][j] << "\t";
            //printf("%.2f\t", matriz[i][j]);
        }
        cout<<endl;
    }
}

void GaussPivoteoParcial()
{
    int f, c;
    cout << "Cant. Filas : "; cin >> f; cout << endl;
    c = f+1;

    float** A;
    crearMatriz(A, f, c);

    cout << "### Valores para la matriz COEFICIENTES Y RESULTADOS ###" << endl;
    cout << "Ingrese valores separados por espacios: " << endl << endl;
    for(int i = 0; i < f; i++) {
        cout << "     fila " << i+1 << ": ";
        for(int j = 0; j < c; j++)
            cin >> A[i][j];
    }
    mostrarMatriz(A,f,c);

    for(int i = 0; i < f; i++)
    {
        int maxi = A[i][i];
        int pMax = i;

        for(int j = i+1; j < f; j++)
        {
            if (A[j][i] > maxi)
            {
                maxi = A[j][i];
                pMax = j;
            }
        }
        if (pMax != i){
            cambiarFila(A, c, i, pMax);
            mostrarMatriz(A,f,c);
        }

        for(int j = i + 1; j < f; j++)
        {
            float cte = (A[j][j-1] / A[i][i]);
            if(A[j][i] != 0)
            {
                for(int k = i; k < c; k++)
                {
                    A[j][k] = A[j][k]-(cte*A[i][k]);
                }
            }
        }
        mostrarMatriz(A,f,c);
    }

    float *despeje = new float[f];
    int pos = 0;
    float sumatoriaG = 0;

    for(int i = f-1; i >= 0; i--)
    {
        for(int j = c-2; j != i; j--)
        {
            sumatoriaG += (A[i][j]) * (despeje[pos++]);
        }
        despeje[pos] = (A[i][c-1] - sumatoriaG)/A[i][i];
        pos = 0;
        sumatoriaG = 0;
    }

    for(int i = 0; i < f; i++)
    {
        float tmp = despeje[i];
        despeje[i] = despeje[f-1-i];
        despeje[f-1-i] = tmp;
    }

    cout << endl;
    cout << "Los valores de las variables son:" << endl;
    for(int i = 0; i < f; i++)
        cout << "X" << i << " = " << despeje[i] <<"\t";
    cout << endl;
}

int main()
{
    GaussPivoteoParcial();
    return 0;
}
