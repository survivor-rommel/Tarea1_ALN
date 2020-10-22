#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	
	int i=0,j=0,k=0,n=0;
	
	cout << "\t\tDESCOMPOSICION LU\n\tHECHO POR: RODRIGO SANTISTEBAN\n\tALGEBRA LINEAL NUMERICA\n\n";
	cout << "Ingrese el número de ecuaciones ";cin >> n;

    float A[n][n], B[n], X[n], L[n][n], Y[n], U[n][n],sum=0;
    
    cout << "\nLa matriz será de " << n << "x" << n <<".\n\n";
    
    //Obtención de los coeficientes de la matriz A
    cout<<"Ingrese los coeficientes de la matriz A de coeficientes: ";
    cout << endl;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << "Ingrese el elemento A["<<i+1<<"]["<<j+1<<"]: "; cin >> A[i][j];
        }
    }
    cout << endl;

	//Mostramos la matriz 
	
	cout<<endl<<"Su matriz es: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
    }
	
    //Obtencion de los terminos independientes
    cout <<endl<<endl <<"Ingrese los terminos independientes" << endl;
    for(i=0;i<n;i++){
        cout << "Ingrese el elemento B["<<i+1<<"]: ";
        cin >> B[i];
    }
	
	
	
    //DESCOMPOSICIÓN LU

    //Llenamos las matrices con ceros y unos en las posiciones conocidas
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i>j){
              U[i][j]=0;    //Ceros  para la matriz U
            }
            
			else if(i==j){
              L[i][j]=1;    //Unos en la diagonal de L
            } 
			
			else{
              L[i][j]=0;    //Ceros para la matriz L
            }
		}
    }
    
    //Operamos para las demás posiciones

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum=0;
            if(i<=j){               //Elementos de la diagonal y encima de U
                for(k=0;k<n;k++){
                    if(k!=i){
                        sum=sum+L[i][k]*U[k][j];
                    }
					
					else {
                        U[i][j]=A[i][j]-sum;               //Elementos restantes de U
                    }
                }
            } 
			
			else{                 //Elementos debajo de la diagonal de L
                for(k=0;k<n;k++){
                    if(k!=j){
                        sum=sum+L[i][k]*U[k][j];
                    }
					
					else {
                        L[i][j]=(A[i][j]-sum)/U[j][j];      //Elementos restantes de L
                    }
                }
            }
        }
    }
	
	//Mostramos las matrices L y U
	
    cout<<endl<<endl<<"La matriz L es: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
    }

    cout<<endl<<endl<<"La matriz U es: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
    }
	
	//Solucionamos el sistema de ecuaciones
	
    Y[0]=B[0]/L[0][0];
    for(i=1;i<n;i++)
    {
        sum=0;
        for(j=0;j<i;j++)
        {
            sum=sum+Y[j]*L[i][j];
	
        }
        Y[i]=B[i]-sum;
    }
    
    //Mostramos el primer corte 
    
    cout<<"\n\nMostrando la resolución con la primer matriz\n";
    for(i=0;i<n;i++){
        cout<<Y[i]<<endl;
    }

	//Operamos con la matriz final
	
    X[n-1]=Y[n-1]/U[n-1][n-1];
    for(i=n-2;i>=0;i--){
        sum=0;
        for(j=n-1;j>i;j--)
            sum=sum+X[j]*U[i][j];
        X[i]=(Y[i]-sum)/U[i][i];
    }

    cout<<"\n\nLa solucion final es :\n";
    for(i=0;i<n;i++)
        cout<<X[i]<<endl;

	return 0;
}
