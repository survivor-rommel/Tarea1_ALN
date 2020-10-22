#include <iostream>

#define n 10
void Jacobi(int numEcu, float x[], float a[][10], float b[])
{
    char p;
    int iter = 0;
    float c[n];
    int k, i, j;
//identificador que nos ayuda a realizar mas iteraciones
line:
    //desarrollo del método de jacobi
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < numEcu; i++)
        {
            c[i] = b[i];
            for (j = 0; j < numEcu; j++)
            {
                if (i != j)
                {
                    c[i] = c[i] - a[i][j] * x[j];
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            x[i] = c[i] / a[i][i];
        }
    }
    iter++;
    std::cout << "La solucion en la iteracion n°" << iter << ": \n";
    for (i = 0; i < numEcu; i++)
    {
        std::cout << "x(" << i << ") = " << x[i] << "\n";
    }
    std::cout << "¿Siguiente iteración?\n";
    std::cout << "(s) Si\n";
    std::cout << "(n) No\n";
    std::cin >> p;
    switch (p)
    {
    case 's':
        //decimos que vamos hacia nuestro identificador para realizar una nueva iteracion
        goto line;
        break;
    case 'n':
        std::cout << "Fin del programa.\n";
        break;
        return;
    }
}

int main()
{
    int i, j, numEcu, cont = 0;
    float x[n], a[n][n], b[n], dd, suma;
    std::cout << "N° de ecuaciones: ";
    std::cin >> numEcu;
    std::cout << "Introduce los coeficientes respectivos: \n";
    for (i = 0; i < numEcu; i++)
    {
        x[i] = 0;
        for (j = 0; j < numEcu; j++)
        {
            std::cout << "a[" << i << "," << j << "]= ";
            std::cin >> a[i][j];
        }
    }
    std::cout << "Introduce el vector de los resultados: \n";
    for (i = 0; i < numEcu; i++)
    {
        std::cout << "b[" << i << ",0]= ";
        std::cin >> b[i];
    }
    for (i = 0; i < numEcu; i++)
    {
        suma = 0;
        for (j = 0; j < numEcu; j++)
        {
            if (i == j)
            {
                dd = a[i][j];
            }
            else
            {
                suma += a[i][j];
            }
        }
        if (dd > suma)
        {
            cont++;
        }
    }
    //verificando si la diagonal es dominante
    if (cont == numEcu)
    {
        Jacobi(numEcu, x, a, b);
    }
    else
    {
        std::cout << "La matriz no es diagonalmente dominante. Fin del programa.\n";
    }
    return 0;
}