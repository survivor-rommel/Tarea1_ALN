#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void luDecomposition(int mat[][MAX], int n)
{
    int inferior[n][n], superior[n][n];
    memset(inferior, 0, sizeof(inferior));
    memset(superior, 0, sizeof(superior));

    // Descomponemos en la parte superior e inferior
    for (int i = 0; i < n; i++)
    {
        // triangular superior
        for (int k = i; k < n; k++)
        {

            // sumatoria de L(i, j) * U(j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (inferior[i][j] * superior[j][k]);

            // Asignando U(i, k)
            superior[i][k] = mat[i][k] - sum;
        }

        // triangular inferior
        for (int k = i; k < n; k++)
        {
            if (i == k)
                inferior[i][i] = 1; // Diagonal as 1
            else
            {

                // sumatoria de L(k, j) * U(j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (inferior[k][j] * superior[j][i]);

                // asignando L(k, i)
                inferior[k][i] = (mat[k][i] - sum) / superior[i][i];
            }
        }
    }

    //mostrar en pantalla
    cout << setw(4) << "     Triangular inferior "
         << setw(30) << "Triangular superior" << endl;

    for (int i = 0; i < n; i++)
    {
        // inferior
        for (int j = 0; j < n; j++)
            cout << setw(6) << inferior[i][j] << "\t";
        cout << "\t";

        // Superior
        for (int j = 0; j < n; j++)
            cout << setw(6) << superior[i][j] << "\t";
        cout << endl;
    }
}

// Driver code
int main()
{
    int i, j, numEcu;
    int a[MAX][MAX];
    std::cout << "N° de ecuaciones: ";
    std::cin >> numEcu;
    std::cout << "Introduce los coeficientes respectivos: \n";
    for (i = 0; i < numEcu; i++)
    {
        for (j = 0; j < numEcu; j++)
        {
            std::cout << "a[" << i << "," << j << "]= ";
            std::cin >> a[i][j];
        }
    }
    luDecomposition(a, numEcu);
    return 0;
}