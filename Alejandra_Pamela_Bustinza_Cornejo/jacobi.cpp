//ALEJANDRA BUSTINZA CORNEJO
/*METODO JACOBI*/

#include<iostream>
#include<cmath>
using namespace std;
#define PRECISION 4

void unir(double M[100][100],double b[100],int n){
	for(int i=0;i<n;i++){
			M[i][n]=b[i];
	}
}

void mostrarM(double M[100][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n+1;j++){
			cout<<M[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}

bool M_DiagDom( double M[100][100], int n){
	int i,j,x,b,a;

	for(i=0; i<n; i++){
		a=abs(M[i][i]);
		for(int j=0;j<n;j++){
            if(i!=j){
               x=x + abs(M[i][j]);
			}
			if(a>x){
				b=b+1;
			}
		}
	}
	if(b==n){
		return true;
	}
	else
		return false;
}

void jacobi(double M[100][100],double V[100],int n,double tol){
    float a,b,ko,ki;
	double n_x=0;
	double dif=10000;
    double VA[100];//vector solucion de la iteracion siguiente
    int iter=0;//iteraciones

   // Tolerancia
   while(dif>=tol) {
         ko=0;
		 ki=0;
		cout<<"ITERACCION "<<iter+1<<endl;
        for(int k=0;k<n;k++){
            n_x=M[k][n];
            for(int j=0;j<n;j++){
                if(k!=j){
                    n_x=n_x-V[j]*M[k][j];
                }

            }
            VA[k]=n_x/M[k][k];

			cout<<"VALOR DEL X"<<k<<" : "<<VA[k]<<"\t";
        }
		cout<<endl;

		for(int i=0; i<n; i++){
			a=V[i]-VA[i];
				if(b>a){
				b=a;
			}
		}

		for(int i=0;i<n;i++){
			ko=ko+abs(V[i]);
			ki=ki+abs(VA[i]);
        }

		dif=abs(ki)-abs(ko);

        for(int i=0;i<n;i++){
            V[i]=VA[i];
        }
		iter +=1;
    }
	cout<<endl;
	cout<<"la ultima iteraccion es la respuesta"<<endl;
}
int main () {
    double m[100][100], b[100];
    int n,i,j,x;
	bool a;
    double V[100];
    double tol;
	cout<<endl;
	cout<<" INGRESE EL TANANO DE LA MATRIZ CUADRADA : ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<"\n M=["<<i<<","<<j<<"]= ";
			cin>>m[i][j];
		}
		cout<<"\n Ingrese el termino independiente"<<"M=["<<i<<","<<j<<"]= ";
		cin>>b[i];
	}
	cout<<endl;
	cout<<"  ---- Matriz ingresada ---- "<<endl;
	unir(m,b,n);
	mostrarM(m,n);
	cout<<endl;

	a=M_DiagDom(m,n);

	if(a== 1){
		cout<<" --- LA  DIAGONAL DE LA MATRIZ SI ES DOMINANTE --- "<<endl;
		cout<<endl;
		for (x=0; x<n ;x++){
			cout<<" ingreselos valores de x0 inicial x0"<<x<<" : ";
			cin>>V[x];
			//cout<<endl;
		}
		cout<<endl;
		cout<<" Ingrese la Tolerancia : ";
		cin>>tol;
		cout<<endl;
		jacobi(m,V,n,tol);
	}
	else
		cout<<" --- LA  DIAGONAL DE LA MATRIZ NO ES DOMINANTE NO SE PUEDE UZAR EL METODO JACOBI ---";
    return 0;
}
