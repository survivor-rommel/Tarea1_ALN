#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	cout<<setprecision(6); cout<<fixed;
	
	int n, nmax, i, j;
	cout << "\t\tMETODO DE JACOBI\n\tHECHO POR: RODRIGO SANTISTEBAN\n\tALGEBRA LINEAL NUMERICA\n\n";
	cout << "Ingrese el numero de ecuaciones ";cin >> n;
	
	float a[n][n], b[n], x[100][n], suma, temp;
	
	cout << "\nLa matriz será de " << n << "x" << n <<".\n\n";
	
	
	cout<<"Ingrese los coeficientes de la matriz A de coeficientes: "<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << "Ingrese el elemento A["<<i+1<<"]["<<j+1<<"]: "; cin >> a[i][j];
		}
	}
	
	cout<<endl;
	
	cout<<endl<<"Su matriz es: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
    }
	
		
	//Obtencion de los terminos independientes
    cout <<endl<<endl <<"Ingrese los terminos independientes" << endl;
    for(i=0;i<n;i++){
        cout << "Ingrese el elemento B["<<i+1<<"]: ";
        cin >> b[i];
    }
		
		
	cout <<endl<<endl <<"Ingrese los valores iniciales" << endl;
	for(int i=0; i<n; i++){
		cout<<"Valor inicial "<<i+1<<": "; cin>>x[0][i];
	}
		
	
	cout <<endl<<endl <<"Ingrese el numero de iteraciones: " ;cin>>nmax; cout<< endl;
	
	//Numero de iteraciones
	int k=0;
	
	//Algoritmo recursivo
	while(k<=nmax){
		for(int i=0; i<n; i++){
			suma = 0.0;
			for(int j=0; j<n;j++){
				if(j!=i){
					suma = suma+a[i][j]*x[k][j];
				}
			}
			x[k+1][i] = (b[i]- suma)/a[i][i];
		}
		k++;
	}
		
	cout<<"Mostrando resultados:\n\n";
	for(k=0;k<=nmax;k++){
		for(int i=0; i<n; i++){
			cout<<setw(15)<<x[k][i];
		}
		cout<<"\n";
	}
	
		
	return 0;
}
