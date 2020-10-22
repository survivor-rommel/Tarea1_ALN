#include<iostream>
using namespace std;

void createM(float** &matriz, int f, int c)
{
    matriz = new float*[f];
    for(int i = 0; i < f; i++)
        matriz[i] = new float[c];
}

void display(float** matriz, int f, int c)
{
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

class Jacobi
{
    float** matriz;
    float* sol;
    float* valores;
    int n;
    int itera;
public:
    Jacobi();
    void pushing();
    float sumaArrayJacobi(int);
    void metJacobi();
};

Jacobi::Jacobi()
{
    pushing();
}

void Jacobi::pushing()
{
    cout << "Filas: ";
    cin >> n;
    cout << endl;
    cout << "Iteraciones: ";
    cin >>itera;
    cout << endl;

    cout << "Matrix -> " << endl;
    createM(matriz, n, n);
    for(int i = 0; i < n; i++)
    {
        cout << "* Fila " << i << ": ";
        for(int j = 0; j < n; j++)
            cin >> matriz[i][j];
    }
    display(matriz, n, n);

    sol = new float[n];
    cout << "Soluciones " << ": ";
    for(int i = 0; i < n; i++)
        cin >> sol[i];

    valores = new float[n];
    cout << "Aproximacion " << ": ";
    for(int i = 0; i < n; i++)
        cin >> valores[i];

}

float Jacobi::sumaArrayJacobi(int posFil) // posFil = fila que se est� evaluando
{
    float acum = 0.0;
    for(int posCol = 0; posCol < n; posCol++)
        if(posFil!=posCol)
            acum += matriz[posFil][posCol]*valores[posCol]; // sumatoria del producto de coeficientes*Xn en cada fila

    return acum;
}

void Jacobi::metJacobi()
{
    for(int i = 0; i < itera; i++)
    {
        for(int j = 0; j < n; j++)
        {
            valores[j] = (sol[j] - sumaArrayJacobi(j))/matriz[j][j];
            cout << valores[j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++)
        cout << valores[i] << " ";
    cout << endl;
}

int main()
{
    Jacobi J;
    J.metJacobi();
    return 0;
}

