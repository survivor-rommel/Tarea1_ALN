#include<iostream>
#include<cmath>
#include<locale>
/*
Teniendo el siguiente sistema de ecuaciones:
        2x1 + x2 + x3 = 5
             4x1 - 6x2 = -2
        -2x1 + 7x2 + 2x3 = 9

El programa pedirá el número de ecuaciones, en este caso se ingresaria 3.
Y luego pedirá ingresar cada elemento de la ecuación, para lo cual
ingresaremos el valor correspondiente a la posisción indicada con su
respectivo signo.
Por ejemplo:
Elemento posición [2][4] : -2
*/
using namespace std;

void pedir_datos();
void sistema_triangulado(double **,int n);
void vector_solucion(double *,double **,int n);

double **M, *V;
int n;

int main ()
{
    setlocale(LC_ALL, "");
    cout << "\t\t\t___________________________________________________" << endl;
    cout << "\t\t\tMétodo de Eliminación Gaussiana con Pivoteo Parcial" << endl;
    cout << "\t\t\t___________________________________________________\n\n";
    cout << endl;
    pedir_datos();
    cout << "La Matriz aumentada es:" << endl;
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
    cout << endl;
    cout << "Se obtuvo el sistema triangular: " << endl;
    sistema_triangulado(M,n);
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                cout << M[i][j]<<"\t";
            }
            cout << endl;
    }
    cout << endl;
    cout << "La solución del sistema de ecuaciones es: " << endl;
    vector_solucion(V,M,n);
    for(int i = 0; i < n; i++)
    {
        cout << "X" << i+1 << " = " << V[i] << "\n";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
		delete[] M[i];
	}
	delete[] M;
	delete[] V;
    system("pause");
    return 0;
}

void pedir_datos()
{
    cout << "Ingrese número de ecuaciones:";
    cin >> n;
    int m = n;
    M = new double*[n];
    for(int i = 0; i < n; i++)
    {
		M[i] = new double[m];
    }
    V = new double[n];
    cout << "Ingrese los coeficientes de las ecuaciones:" << endl;
    for(int i = 0; i < n; i++)
        {
            cout << "\t" << "Fila " << i+1 << " : " <<endl;
            for(int j = 0; j < n+1; j++)
            {
                cout << "Elemento posición [" << i+1 << "][" << j+1 << "]: ";
                cin >> *(*(M + i)+ j);
            }
            cout << endl;
    }
}

void sistema_triangulado(double **M, int n)
{
    double mayor;
    int pos;
    double aux;
    double pivote;

    for(int k = 0; k < n-1; k++)
        {
            mayor = abs(*(*(M+k)+k));
            pos = k;
            for(int l = k+1; l < n; l++)
            {
                if( mayor < abs(*(*(M+l)+k)))
                {
                    mayor = abs(*(*(M+l)+k));
                    pos = l;
                }
            }

        if(k != pos)
        {
            for(int i = 0; i < n+1; i++)
            {
                aux = *(*(M+k)+i);
                *(*(M+k)+i) = *(*(M+pos)+i);
                *(*(M+pos)+i) = aux;
            }
        }

        if(*(*(M+k)+k) == 0)
        {
            cout << "El sistema no tiene solución";
            break;
        }
        else
        {
            for(int i = k+1; i <n; i++)
            {
                pivote = -(*(*(M+i)+k));
                for(int j = k; j <n+1 ; j++)
                {
                    *(*(M+i)+j) = *(*(M+i)+j) + pivote * (*(*(M+k)+j)) / *(*(M+k)+k);
                }
            }
        }
    }
}

void vector_solucion(double *V, double **M, int n)
{
    double aux1;
    for(int i = n-1; i >= 0; i--)
    {
        aux1 = 0;
        for(int j = n-1; j >= 0; j--)
        {
            if(j > i)
            {
                aux1 += *(*(M+i)+j) * (*(V+j));
            }
        }
        *(V+i) = (*(*(M+i)+n) - aux1) / *(*(M+i)+i);
    }
}
