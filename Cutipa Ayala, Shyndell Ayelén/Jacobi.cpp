/*  
*   Estudiante: Shyndell Ayelén Cutipa Ayala
*   Método Iterativo de Jacobi
*   para resolver un sistema de ecuaciones 
*   linear de n x n
*   
*   E1:  A[1,1] x[1] + A[1,2] x[2] +...+ A[1,n] x[n] = b[1,n+1]
*   E2:  A[2,1] x[1] + A[2,2] x[2] +...+ A[2,n] x[n] = b[2,n+1]
*   :
*   .
*   EN:  A[n,1] x[1] + A[n,2] x[2] +...+ A[n,n] x[n] = b[n,n+1]
*
*   INPUT:   número de ecuaciones, coeficientes de la matriz aumentada,
*            número de iteraciones y tolerancia del error.
*
*   OUTPUT:  solucion x(1), x(2),...,x(n) 
*/

#include <math.h>
#include <stdlib.h> // para el uso de la función exit
#include <iostream> // cin & cout
#include <iomanip> // para el uso de la función setprecision
/* setprecision(Establece la precisión decimal 
   que se utilizará para dar formato a los valores 
   de punto flotante en las operaciones de salida.)*/
using namespace std;



void Jacobi(float A[100][100], float x[100], int i, int j, int k, int n, 
            int num_iter, float b, float sum, float temp, 
            float error_relativo, float limite_superior)
{
     
    /* Le damos un valor inicial a x, para la primera iteración */ 
    for (i = 1; i <= n; i++)
        x[i] = 0;

    /* Se toma la aproximacion inicial para hallar las nuevas aproximaciones, 
       teniendo en cuenta el fundamento del método. */
    for (k = 1; k <= num_iter; k++)
    {
        b = 0;
        for (i = 1; i <= n; i++)
        {
            sum = 0;
            for (j = 1; j <= n; j++)
            {
                if (i != j)
                    sum = sum + A[i][j] *
                            x[j];
            }

            temp = (A[i][n+1] - sum) /
                    A[i][i];

            /* Se calcula el error absoluto relativo
               y se irá actualizando */ 
            error_relativo = fabs((x[i] - temp) /
                                  temp);

            if (error_relativo > b)
                b = error_relativo;

            x[i] = temp;
        }

        /* Si el error es menor del propuesto al principio; 
           la ultima iteración tendrá las aproximaciones 
           a la solución del sistema de ecuaciones. */
        if(b <= limite_superior)
        {
            cout << "La solucion del sistema de ecuaciones es:\n";
            for (i = 1; i <= n;i++)
                cout << "x(" << i << ") = " << setprecision(4) << x[i] << "\t";
            exit(1);
        }
    }
}



int main()
{
    float A[100][100],
            x[100],
            limite_superior,
            b,
            temp,
            error_relativo,
            sum;

    int n,
            i, // Primer iterador
            j, // Segundo iterador
            num_iter, // Número de iteraciones
            k; // Tercer iterador

    cout << "Ingrese el numero de ecuaciones: ";
    cin >> n;

    cout<<"Ingrese los coeficientes para formar la matriz aumentada \n";
    for (i = 1; i <= n; i++)
    {
        cout << "Ecuacion nro" << i << ": ";
        for (j = 1; j <= n + 1; j++)
        cin >> A[i][j];
    }

    cout << "Ingrese tolerancia de error: ";
    cin >> error_relativo;

    cout << "Ingrese numero de iteraciones: ";
    cin >> num_iter;


    Jacobi(A, x, i, j, k, n, num_iter, b, sum, temp, error_relativo, limite_superior);
    cout << "La solucion del sistema de ecuaciones es:\n";
    for (i = 1; i <= n;i++)
        cout << "x(" << i << ") = " << setprecision(4) << x[i] << "\t";

    return 0;
}