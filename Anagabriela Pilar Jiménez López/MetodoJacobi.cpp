// Anagabriela Pilar Jiménez López      Álgebra Lineal Grupo A

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const int N = 4;

// función del Método de Jacobi
void jacobi(double a[N][N], double v[N][N]);
// función para mostrar los elementos de la diagonal
void disp_valorpropio(double a[N][N]);
// mostrar vector
void disp_vectorpropio(double matrix[N][N]);
// Mostaramos matriz de una dimensión (en forma de vector)
void disp_vector(double row[N]);
// función de normalización (para establecer la longitud del vector en 1)
void normarize(double x[N]);


int main()
{
    double a[N][N] = {{5.0, 4.0, 1.0, 1.0}, 
                      {4.0, 5.0, 1.0, 1.0}, 
                      {1.0, 1.0, 4.0, 2.0},
                      {1.0, 1.0, 2.0, 4.0}};
	double v[N][N] = {{1.0 ,0.0 ,0.0 ,0.0},
	                  {0.0 ,1.0 ,0.0 ,0.0},
	                  {0.0 ,0.0 ,1.0 ,0.0},
	                  {0.0 ,0.0 ,0.0 ,1.0}};

    jacobi(a, v);

    cout << endl << "valores propios" << endl;
	disp_valorpropio(a);

    cout << endl << "vectores propios" << endl;
	disp_vectorpropio(v);

    return 0;
}

void jacobi(double a[N][N], double v[N][N])
{
    for (int k = 1; k <= 100; k++)
    {
        // Encuentra el máximo
		int p = 0;
		int q = 0;
        double max_val = 0.0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (max_val < fabs(a[i][j]))
                {
                    max_val = fabs(a[i][j]);
                    p = i;
                    q = j;
				}
			}
		}

        // Encuentra θ
        double t;
        if (fabs(a[p][p] - a[q][q]) < 0.00000000001)
        {
            // a_{pp} ＝ a_{qq} Cuando el ángulo de rotación t se establece en π / 4.
            t = M_PI / 4.0;
            if (a[p][p] < 0)
                t = -t;
        }
        else
        {
            // a_{pp} ≠ a_{qq} Cuando:
            t = atan(2.0 * a[p][q] / (a[p][p] - a[q][q])) / 2.0;
        }

        // Creamos una matriz U usando θ, A = U ^ t × A × U
        double c = cos(t);
        double s = sin(t);
        // U^t × A
        double t1;
        double t2;
        for (int i = 0; i < N; i++)
        {
            t1      =  a[p][i] * c + a[q][i] * s;
            t2      = -a[p][i] * s + a[q][i] * c;
            a[p][i] = t1;
            a[q][i] = t2;
            // Vector Único
            t1      =  v[p][i] * c + v[q][i] * s;
            t2      = -v[p][i] * s + v[q][i] * c;
            v[p][i] = t1;
            v[q][i] = t2;
        }
        // A × U
        for (int i = 0; i < N; i++)
        {
            t1      =  a[i][p] * c + a[i][q] * s;
            t2      = -a[i][p] * s + a[i][q] * c;
            a[i][p] = t1;
            a[i][q] = t2;
        }

        // mostramos la diagonal
        cout << setw(3) << k << "\t";
        disp_valorpropio(a);

        // convergencia
    	if (max_val < 0.00000000001) break;
    }
}


void disp_valorpropio(double a[N][N])
{
    for (int i = 0; i < N; i++)
        cout << setw(14) << fixed << setprecision(10) << a[i][i] << "\t";
    cout << endl;
}

void disp_vectorpropio(double matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
		double row[N];
        for (int j = 0; j < N; j++)
            row[j] = matrix[i][j] ;
        normarize(row);
        disp_vector(row);
	}
}

void disp_vector(double row[N])
{
    for (int i = 0; i < N; i++)
        cout << setw(14) << fixed << setprecision(10) << row[i] << "\t";
    cout << endl;
}

void normarize(double x[N])
{
    double s = 0.0;

    for (int i = 0; i < N; i++)
        s += x[i] * x[i];
    s = sqrt(s);
    
    for (int i = 0; i < N; i++)
        x[i] /= s;
}