#include <iostream>

using namespace std;
void crear(float **&M,float *&V,float *&I,float *&AI,int n)
{
	M= new float *[n];
	V= new float [n];
	I= new float [n];
	AI= new float [n];
	for(int i=0;i<n;i++){
		M[i]= new float[n];
		I[i]=0;
		AI[i]=0;
	}
					
	for(int i=0;i<n;i++){
		cout<<"Fila "<<i+1<<endl;
		for(int j=0;j<n;j++){
			cout<<"M["<<i+1<<"]["<<j+1<<"] = ";
			cin>>*(*(M+i)+j);
		}
		cout<<"="; cin>>*(V+i);
	}	
}
void metodo_jacobi(float **&M,float *&V,float *&I,float *&AI,int n)
{
	while(true){
		for(int i=0;i<n;i++){
			float suma=0;
			float valor=0;
			for(int j=0;j<n;j++){
				if(i!=j){
					valor= M[i][j] * -1;
					valor= valor * AI[j];
					suma+= valor;
				}
			}
			suma+= V[i];
			I[i]= suma/M[i][i];
		}
		
		cout<<"Iteracion ( ";
		for(int j=0;j<n;j++)
			cout<<I[j]<<" ";
		cout<<")"<<endl;
		
		bool b= true;
		for(int i=0;i<n;i++){
			float x=I[i]-AI[i];
			x=x/I[i]*100;
			if(x>5){
				b= true;
				break;
			}
			else
				b= false;
		}

		if(b==false)
			break;
		
		for(int j=0;j<n;j++)
			AI[j]=I[j];	
	}
}
int main()
{
	float **M, *V, *I, *AI;
	int n;
	cout<<"Matriz"<<endl;
	cout<<"Numero de filas y columnas:";cin>>n;
	crear(M,V,I,AI,n);
	metodo_jacobi(M,V,I,AI,n);
	return 0;
}
// Joselyn Lizeth Quispe Huanca
