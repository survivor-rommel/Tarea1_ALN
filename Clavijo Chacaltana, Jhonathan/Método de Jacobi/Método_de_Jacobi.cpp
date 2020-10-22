/*
Teniendo el siguiente sistema de ecuaciones:
        10x1 + 3x2 + x3 = 14
        5x1 - 10x2 + 3x3 = -5
        x1 + 3x2 + 10x3 = 14
Se ingresarían los datos por la matriz principal:
Dimesión de la Matriz A en este caso sería: 3
        10   3   1
    A=   5 -10   3
         1   3  10
Con el vector:
        14
    b=  -5
        14
Y un vector de inicio:
        0
    x=  0
        0
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
void pedir_datos();
double norma(double *v1,double *v2);
double jacobi(double *M, double *v, int componente);

double **A, *b, *x, *x1, *aux;
int dim, iteraciones = 0, iter = 0;
float error, epsilon;

int main()
{
    setlocale(LC_ALL, "");
    cout << "\t\t\t_________________" << endl;
    cout << "\t\t\tMétodo de Jacobi" << endl;
    cout << "\t\t\t_________________\n\n";
    cout << endl;
    pedir_datos();

    while (error > epsilon)
    {
        for(int i = 0; i < dim; i++)
        {
            for(int j = 0; j< dim; j++)
            {
                *(aux + j) = *(*(A + i)+ j);
                *(x + i) = (1 / *(*(A + i)+ i)) * (*(b + i) - jacobi(aux, x1, i));
            }
        }
        error = norma(x, x1);
        cout << "Iteración: " << iteraciones << endl;
        for(int i = 0; i < dim; i++)
        {
            *(x1 + i)= *(x + i);
            cout << "X" << i << " = " << *(x + i) << endl;
        }
        iteraciones++;
        if (iteraciones == iter)
        {
            error = epsilon - 1;
        }
    }
    cout << "\n____________________\nSolución del sistema\n____________________ " << endl;
    cout << "\nNúmero de iteraciones: " << iteraciones << endl;
    for(int i = 0; i < dim; i++)
    {
        cout << "X" << i << " = " << *(x + i) << endl;
    }
    for(int i = 0; i < dim; i++)
    {
		delete[] A[i];
	}
	delete[] A;
	delete[] b;
	delete[] x;
	delete[] x1;
	delete[] aux;
	system("pause");
    return 1;
}

void pedir_datos()
{
    cout << "Dimensión de la matriz A: ";
    cin >> dim;
    int n = dim;
    A = new double*[dim];
    for(int i = 0; i < n; i++)
    {
		A[i] = new double[n];
    }
    b = new double[n];
    x = new double[n];
    x1 = new double[n];
    aux = new double[n];
    cout << "Ingrese los elementos de la matriz A:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "\t" << "Fila " << i+1 << " : " <<endl;
        for(int j = 0; j < n; j++)
        {
            cout << "Elemento posición [" << i+1 << "][" << j+1 << "]: ";
            cin >> *(*(A + i)+ j);
        }
        cout << endl;
    }
    cout << "Ingrese los elementos del vector b:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Elemento posición [" << i+1 << "][1]: ";
        cin >> *(b + i);
    }
    cout << "\nError de parada: " << endl;
    cout << "E = ";
    cin >> epsilon;
    error = epsilon + 1;
    cout << "\nIngrese el número de iteraciones:" << endl;
    cin >> iter;
    cout << "\nValor inicial de la iteración: " << endl;
    for(int i = 0; i < dim; i++)
    {
        cout << "X0(" << i << ") = ";
        cin >>  *(x1 + i);
    }
}

double norma(double *v1, double *v2)
{
    double aux1 = 0;
    for(int i = 0; i < dim; i++)
    {
        aux1 = aux1 +(*(v1 + i) - (*(v2 + i))) * (*(v1 + i) - (*(v2 + i)));
    }
    return aux1;
}

double jacobi(double *M, double *v, int componente)
{
    double aux1 = 0;
    for(int i = 0; i < dim; i++)
    {
        if (componente != i)
        {
            aux1 = aux1 + (*(M + i))* (*(v + i));
        }
    }
    return aux1;
}
