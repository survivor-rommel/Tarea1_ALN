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

void jacobi(unsigned int equations, unsigned int variables, double *X0, unsigned int Nmax, double tol) {
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

	double *A = new double [variables * 2] { 0 };
	for (size_t i = 0; i < variables; i++) {
		A[variables + i] = X0[i];
		std::cout << "X" << i << ": " << X0[i] << "\t";
	}
	std::cout << "\n";

	double error = 1000;

	for (size_t a = 0; a < Nmax && error > tol; a++) {
		for (size_t i = 0; i < equations; i++) {
			double s = M[i][variables];
			for (size_t j = 0; j < variables; j++)
				if (i != j)
					s -= (M[i][j] * A[variables + j]);
			s /= M[i][i];
			A[i] = s;
		}

		double k = 0;
		for (size_t i = 0; i < variables; i++)
			k += abs(A[i] - A[variables + i]);

		for (size_t i = 0; i < variables; i++)
			A[variables + i] = A[i];

		for (size_t i = 0; i < variables; i++)
			std::cout << "X" << i << ": " << A[i] << "\t";
		std::cout << "\n";
	}

	delete[] A;

	for (size_t i = 0; i < equations; i++)
		delete[] M[i];
	delete[] M;
}

int main()
{
	unsigned int equations, variables, Nmax;

	std::cout << "Ax = b\n\n";

	std::cout << "Ingrese el numero de ecuaciones: "; std::cin >> equations;
	std::cout << "Ingrese el numero de variables: "; std::cin >> variables;

	double *X0 = new double [variables];
	std::cout << "Ingrese los valores iniciales: ";
	for (size_t i = 0; i < variables; i++)
		std::cin >> X0[i];

	std::cout << "Ingrese el Nmax: "; std::cin >> Nmax;

	jacobi(equations, variables, X0, Nmax, 10^-4);

	return 0;
}