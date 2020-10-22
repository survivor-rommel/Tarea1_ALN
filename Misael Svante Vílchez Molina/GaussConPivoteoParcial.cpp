#include <iostream>
#include <cmath>
#include <stdlib.h>

void mostrarMatriz(double **M, unsigned int equations, unsigned int variables) {
	for (size_t i = 0; i < equations; i++) {
		std::cout << "[ ";
		for (size_t j = 0; j < variables; j++)
			std::cout << M[i][j] << "\t";
		std::cout << "|  " << M[i][variables] << " ]\n";
	}
	std::cout << "\n";
}

void swapFilas(double **M, unsigned int fila1, unsigned int total_columnas, unsigned int fila2) {
	for (size_t i = 0; i < total_columnas; i++) {
		double temp = M[fila1][i];
		M[fila1][i] = M[fila2][i];
		M[fila2][i] = temp;
	}
}

void gaussConPivoteoParcial(unsigned int equations, unsigned int variables) {
	double **M = new double *[equations];
	for (size_t i = 0; i < equations; i++)
		M[i] = new double [variables + 1];

	std::cout << "\nIngrese A:\n";
	for (size_t i = 0; i < equations; i++) {
		for (size_t j = 0; j < variables; j++) {
			std::cout << "Ingrese el valor de A[" << i << "][" << j << "]: ";
			std::cin >> M[i][j];
		}
	}
	std::cout << "\nIngrese b:\n";
	for (size_t i = 0; i < equations; i++) {
		std::cin >> M[i][variables];
	}
	std::cout << "\n";

	mostrarMatriz(M, equations, variables);
	for (size_t i = 0; i < equations; i++) {
		double pivot = abs(M[i][i]);
		unsigned int pivot_pos = i;
		for (size_t k = i + 1; k < equations; k++)
			if (abs(M[k][i]) > pivot) {
				pivot = abs(M[k][i]);
				pivot_pos = k;
			}
		if (pivot_pos != i) swapFilas(M, i, variables + 1, pivot_pos);
		for (size_t j = i + 1; j < equations; j++) {
			double constant = -1 * M[j][i] / M[i][i];
			for (size_t k = 0; k < variables + 1; k++) {
				M[j][k] += (M[i][k] * constant);
			}
		}
	}
	mostrarMatriz(M, equations, variables);

	double *A = new double [variables];
	
	for (int i = variables; i > 0; i--) {
		double s = M[i - 1][variables];
		for (size_t j = i; j < variables; j++)
			s -= M[i - 1][j] * A[j];
		A[i - 1] = s / M[i - 1][i - 1];
	}
	
	for (size_t i = 0; i < variables; i++)
		std::cout << "X" << i << " = " << A[i] << "\n";

	delete[] A;

	for (size_t i = 0; i < equations; i++)
		delete[] M[i];
	delete[] M;
}

int main()
{
	unsigned int equations, variables;

	std::cout << "Ax = b\n\n";

	std::cout << "Ingrese el numero de ecuaciones: "; std::cin >> equations;
	std::cout << "Ingrese el numero de variables: "; std::cin >> variables;

	gaussConPivoteoParcial(equations, variables);

	return 0;
}