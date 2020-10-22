#include <iostream>

using namespace std;
void crear(float **&M,float *&V,float *&R,int n)
{
	M= new float *[n];
	V= new float [n];
	R= new float [n];
	for(int i=0;i<n;i++){
		M[i]= new float[n];
		R[i]=0;
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
void metodo_gauss(float **&M,float *&V, float *&R,int n)
{
	//convierte debajo de la diagonal en cero
	
	float p;
	for(int i=1;i<n;i++){
		if(M[i][0]!=0){
			for(int j=1;j<n;j++){
			    p= M[0][0] * M[i][j];
				p= p - (M[i][0] * M[0][j]);
				M[i][j] = p;
			}
			p= M[0][0] * V[i];
			p= p - (M[i][0] * V[0]);
			V[i]= p;
			M[i][0]= 0;
		}
		if(i>1){
			for(int k=0;k<i-1;k++){
				if(M[i][k+1]!=0){
					for(int l=k+2; l<n;l++){
						p= M[k+1][k+1] * M[i][l];
						p= p - (M[i][k+1] * M[k+1][l]);
						M[i][l]= p;
					}
					p= M[k+1][k+1] * V[i];
					p= p - (M[i][k+1] * V[k+1]);
					V[i]= p;
					M[i][k+1]= 0;
				}
			}
		}
	}
	
	//despejar
	int t= n - 1;
	for(int i=0; i<n; i++){
		float s= M[t][t];
		float s1=0;
		int t2= n - 1;
		for(int k=0; k<i; k++)
			s1+= M[t][t2-k] * R[k];
		R[i]= V[t]-s1;
		R[i]= R[i]/s;
		--t;
	}
	
	//mostrar
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<M[i][j]<<" ";
		}	
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<V[i]<<" ";
		
	//resultado
	cout<<"\nRESULTADO:"<<endl;
	if(M[n-1][n-1] == 0 and V[n-1]!=0)
		cout<<"Incompatible";
	
	else if( V[n-1]==0 )
		cout<<"Compatible-Indeterminado";
		
	else{
		for(int i=n-1;i>=0;i--)
		cout<<R[i]<<" ";
	}	
}
int main()
{
	float **M, *V, *R;
	int n;
	cout<<"Matriz"<<endl;
	cout<<"Numero de filas y columnas:";cin>>n;
	crear(M,V,R,n);
	metodo_gauss(M,V,R,n);
	return 0;
}
/*
   Joselyn Lizeth Quispe Huanca
   nota: Antes de ingresar la matriz esta se debe acomodar para que su diagonal tenga valores distinto a cero.
*/
