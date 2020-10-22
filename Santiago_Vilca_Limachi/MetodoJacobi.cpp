// MetodoJacobi.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>

#include <stdlib.h>

int dim;
float norma(float vector1[], float vector2[]);
float suma_jacobi(float Matriz[], float vector[], int componente);

int main() {
    int i, j, iteraciones = 0;
    float error, epsilon;
    int p;
    std::cout << "METODO DE JACOBI DE RESOLUCION DE SISTEMAS Ax=b \n";

    std::cout<< "Digite la dimension de la matriz A: \n";
    std::cin >> dim;

    float** A = new float* [dim];
    float* b = new float[dim];
    float* x = new float[dim];
    float* x_prev = new float [dim];
    float* aux = new float[dim];
    
    for (int i = 0; i < dim; i++)
    {
        A[i] = new float[dim];
    }
    std::cout << "La matriz es de " << dim << "x" << dim << "\n";

    std::cout<<"Elementos de la matriz A: \n";
    for (i = 0; i < dim; i++) for (j = 0; j < dim; j++) {
        std::cout << "A [" << i << "][" << j << "]";
        std::cin >> A[i][j];
    }

    std::cout<< "Elementos del vector b: \n";
    for (i = 0; i < dim; i++) {
        std::cout << "b [" << i << "]";
        std::cin >> b[i];
    }

    std::cout << "Error de parada: \n";
    std::cout << "E=" << i << "\n";
    std::cin >> epsilon;
    error = epsilon + 1;

    //cominezo algoritmo de Jacobi
    //Error se mide como la norma del vector diferenceia entre la iteracion i e i+1
    std::cout << "Valor inicail de la iteracion: \n";
    for (i = 0; i < dim; i++) {
        std::cout << i << "\n";
        std::cin >> x_prev[i];
    }
    while (error > epsilon) {
        for (i = 0; i < dim; i++) {
            for (j = 0; j < dim; j++) aux[j] = A[i][j];
            x[i] = (1 / A[i][i]) * (b[i] - suma_jacobi(aux, x_prev, i));
        }
        error = norma(x, x_prev);

        std::cout << "Iteracion: \n" << iteraciones;
        for (i = 0; i < dim; i++) {
            x_prev[i] = x[i];
            std::cout << "X" << i << "\t" << x[i] << "\t";
        }

        iteraciones++;
        if (iteraciones == 10) error = epsilon - 1;
    }

    std::cout << "Solucion del sistema\n";
    std::cout << "Numero de iteraciones: \n", iteraciones;
    for (i = 0; i < dim; i++) {
        std::cout << "x\n" << i << "\t" << x[i] << "\t";
    }
    //std::cin >> p;
    return 0;
}

float norma(float vector1[], float vector2[]) {
    float aux = 0;
    int i;
    for (i = 0; i < dim; i++) {
        aux = aux + (vector1[i] - vector2[i]) * (vector1[i] - vector2[i]);
    }
    return aux;
}

float suma_jacobi(float Matriz[], float vector[], int componente)
{
    float aux = 0;
    int i;
    for (i = 0; i < dim; i++) {
        if (componente != i) {
            aux = aux + Matriz[i] * vector[i];
        }
    }
    return aux;
}
