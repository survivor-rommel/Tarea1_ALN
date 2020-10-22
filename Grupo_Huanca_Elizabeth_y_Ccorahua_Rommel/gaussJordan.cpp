// para resolver LPP dado usando el m�todo de Gauss-Jordan
#include<iostream>
using namespace std;
// declarar variables de uso frecuente como globales
int row_num,col_num;

void printMatrix(float arr[][10]);
void partially_pivot(float arr[][10],int, int);

main(){
	float arr[10][10];
	float diagonal_element,flag;
	int i,j,k,l,step=0,add=0,sub=0,mul=0,div=0;

	cout<<"ingrese el n�mero de filas \n";
	cin>>row_num;
	
	cout<<"ingrese el n�mero de columnas\n";
	cin>>col_num;
	
	cout<<"ingrese los elementos en la matriz: \n";
	for(i=0; i<row_num; i++){
		for(j=0; j<col_num; j++){
			cout<<"fila "<< i << " columna "<< j << ":\t";
			cin>>arr[i][j];
			cout<<endl;
		}
	}	

	for(i=0; i<row_num; i++){
		for(j=0; j<col_num; j++){
			if(i == j){
				partially_pivot(arr,i,j);
				
				diagonal_element = arr[i][j];
				k = i;
				l = j;
				
				for(l=0; l<col_num; l++){
					// para hacer el elemento diagonal 1
					arr[k][l] /= diagonal_element;
					div++;
				}
					
				
				for(k=0; k<row_num; k++){
					
					// marca de establecimiento = el elemento en la fila respectiva que est� exactamente debajo del elemento diagonal en cuesti�n
					flag = arr[ k ][ j ];
										
					for(l=0; l<col_num; l++)
						if(k != i){
							
							// realizando la operaci�n de fila para macho todos los elementos = 0, excepto el elemento diagonal 
							arr[k][l]= (arr[k][l]) - flag * (arr[i][l]);
							mul++;
							sub++;
						}
							
				}	
			}
		}
		cout<<"Paso:\t"<<step<<endl;
		printMatrix(arr);
		step++;
	}
	
// resultado de impresi�n
	for(i=0;i<row_num;i++)
		cout<<arr[i][col_num-1]<<endl;
		cout<<"\nEl numero total de"<<endl;
		cout<<"adicion ="<<add<<"  sustraccion ="<<sub<<"  multiplicacion ="<<mul<<"  division ="<<div<<endl;
}


// funci�n para pivotar parcial
void partially_pivot(float arr[][10], int pivot_row, int pivot_col){
	float temp;
	int i,large_pivot_row = pivot_row;
	
	for(i=pivot_row; i<row_num ; i++){
		// Para encontrar la mejor entre la columna de la columna pivote
		if(arr[i][pivot_col]>arr[large_pivot_row][pivot_col]){
			 large_pivot_row = i;
		}
	}
	
	if(pivot_row != large_pivot_row){
		// para intercambiar las filas
		for(i=0; i<col_num; i++){
			temp = arr[large_pivot_row][i];
			arr[large_pivot_row][i] = arr[pivot_row][i];
			arr[pivot_row][i] = temp;
		}
	}
}

// funci�n para imprimir la matriz
void printMatrix(float arr[][10]){
	int i,j;
	for(i=0; i<row_num; i++){
		for(j=0; j<col_num; j++){
			cout<< arr[i][j];
			cout<<"\t";
		}
		cout<<endl;
	}	
	cout<<endl;
}
