/*  
*   Estudiante: Shyndell Ayelén Cutipa Ayala
*   Eliminación Gaussiana con pivoteo parcial
*   para resolver un sistema linear de n x n
*   
*   E1:  A[1,1] x[1] + A[1,2] x[2] +...+ A[1,n] x[n] = b[1,n+1]
*   E2:  A[2,1] x[1] + A[2,2] x[2] +...+ A[2,n] x[n] = b[2,n+1]
*   :
*   .
*   EN:  A[n,1] x[1] + A[n,2] x[2] +...+ A[n,n] x[n] = b[n,n+1]
*
*   INPUT:   número de ecuaciones, coeficientes de la matriz aumentada.
*
*   OUTPUT:  solucion x(1), x(2),...,x(n) 
*/

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <iomanip> 
/* para setprecision(Establece la precisión decimal 
   que se utilizará para dar formato a los valores 
   de punto flotante en las operaciones de salida.)*/

using namespace std;

void MostrarMatriz(float A[100][100], int i, int n, int j)
{
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= n; j++)
            cout<<("%6.1f",A[i][j])<<" "<<setprecision(7);
        printf("\n");
    }
} 

/* Realizamos el pivoteo parcial, comparando a los coeficientes 
   e intercambiamos filas si es que corresponde */
void PivoteoParcial(float A[100][100],float C, int i, int n, int j)
{
    for(i = n - 1;i > 0; i--)        
    {
        if(A[i - 1][0] < A[i][0])
            for(j = 0;j <= n; j++)
            {
                C = A[i][j];
                A[i][j] = A[i-1][j];
                A[i-1][j] = C;
            }
    }

}

/* Realizamos la eliminación progresiva 
   para formar una matriz triangular */
void EliminacionProgresiva(float A[100][100],float C, int k, int n, int i, int j)
{    
    for(k = 0; k < n-1; k++)
        for(i = k; i < n-1; i++)
        {
            C = (A[i+1][k] / A[k][k]) ;

            for( j = 0;j <= n; j++)
                A[i+1][j] -= C * A[k][j];
        }
}

/* Con la sustitución regresiva
   hallaremos el vector solución */
void SustitucionRegresiva(float A[100][100],float C,float x[100], int i, int n, int j)
{
    for(i = n-1; i >= 0; i--)
    {
        C = 0;
        for(j = i; j <= n-1; j++)
            C = C + A[i][j] * x[j];

        x[i] = (A[i][n] - C) / A[i][i];
    }
}

int main()
{
    int n, i, j, k;
    float A[100][100], C, x[100] = {0};

    cout<<"Ingrese el numero de ecuaciones: ";
    cin>>n;
    cout<<"Ingrese los coeficientes para formar la matriz aumentada \n";
    for(i = 0;i < n; i++)
    {
        cout<<"Ecuacion Nro"<<i + 1<< ":   ";
        for(j = 0;j <= n; j++)
            cin>>A[i][j];
    }
    cout<<endl<<"Matriz aumentada:"<<endl;
    MostrarMatriz(A, i, n,j);
    
    cout<<endl<<"Proceso aplicando las operaciones elementales de una fila:"<<endl;
	
    
    // Aplicamos Pivoteo Parcial y mostramos la matriz
    PivoteoParcial(A, C,i,n,j);
    MostrarMatriz(A, i, n,j);

    // Aplicamos Sustitucion Progresiva y mostramos la matriz superior
    EliminacionProgresiva(A, C, k,n, i, j);
    printf("\n\n");
    MostrarMatriz(A, i, n,j);
	
    // Aplicamos la Sustitución Regresiva
    SustitucionRegresiva(A, C, x, i, n, j);
	// Mostrar resultado de las variables
    cout<<endl<<"La solucion del sistema de ecuaciones es:"<<endl;
    for(i = 0; i < n; i++)
        cout<<"x("<<i+1<<") = "<<setprecision(5)<<x[i]<<"\t";

    return 0;

}