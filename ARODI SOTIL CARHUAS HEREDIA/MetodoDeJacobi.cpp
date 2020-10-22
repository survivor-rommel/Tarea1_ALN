#include <cmath>
#include <iostream>

using namespace std;

float err(float ec[3], float b, float x1, float x2, float x3 ) {
	return fabs(ec[0] * x1 + ec[1] * x2 + ec[2] * x3 - b);
}

float solucion(float b, float a1, float x1, float a2, float x2, float a3) {
	return (b - a1*x1 - a2*x2) / a3;
}

	
void ingresarMatriz_A_B(float **matrizA,float *b,int nFilCol){
	cout <<"\nEjemplo de como ingresar la matriz:"<<endl;
	cout <<"1 2 3"<<endl;
  	cout <<"4 5 6"<<endl;
  	cout <<"7 8 9"<<endl;
	cout <<endl;
	
	cout << "\nIngrese la matriz A: "<<endl;
	for (int i = 0; i < nFilCol; ++i)
	{
		matrizA[i] = new float[nFilCol];
		for (int j = 0; j < nFilCol; ++j)
		{
			cin>>matrizA[i][j];
		}
	}
	cout <<"\n\nIngrese la Matriz B\n"<<endl;
	for (int i = 0; i < nFilCol; ++i)
	{
		cin >> b[i];
	}
}
int main()
{
	int nFilCol;
	cout << "\nIngrese la dimension de la matriz cuadrada: ";cin>>nFilCol;
	float **matrizA = new float*[nFilCol]; //MAtriz A
	float b[nFilCol]; //Matriz B
	
	ingresarMatriz_A_B(matrizA,b,nFilCol);//Ingresamos la matriz A y B 

	float x1, x2, x3, error, e1, e2, e3, t1, t2, t3;
	int i;

	x1 = x2 = x3 = 0.0f;
	error = 0.0001f;
	i = 0;

	do {
		t1 = x1;
		t2 = x2;
		t3 = x3;

		x1 = solucion(b[0], matrizA[0][1], t2, matrizA[0][2], t3, matrizA[0][0]);
		x2 = solucion(b[1], matrizA[1][0], t1, matrizA[1][2], t3, matrizA[1][1]);
		x3 = solucion(b[2], matrizA[2][0], t1, matrizA[2][1], t2, matrizA[2][2]);

		e1 = err(matrizA[0], b[0],x1,x2,x3);
		e2 = err(matrizA[1], b[1],x1,x2,x3);
		e3 = err(matrizA[2], b[2],x1,x2,x3);

		i++;

	} while (e1 > error || e2 > error || e3 > error);


	cout << "\nAplicando jacobi obtenemos: \n"<<endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	cout << "Iteraciones = " << i << endl;

	delete [] matrizA;
}