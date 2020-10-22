//ALEJANDRA BUSTINZA CORNEJO
//METODO GAUSS_PIVOTE

#include<iostream>

using namespace std;

void mostrar(float m[50][50],int n){
	cout<<"\n";
	cout<<"\n\n";

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			cout<<m[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}

void rep_(float m[50][50], int n){
	int c,i,a;
	for(c=n; c>=1; c--){
		m[c][n+1]=m[c][n+1]/m[c][c];
			for(i=c-1; i>=1; i--)
				m[i][n+1]=m[i][n+1]-m[i][c]*m[c][n+1];
	}


	for(a=1; a<=n; a ++){
		cout<<" X"<<a<<": "<<m[a][n+1]<<endl;
	}
}

void escalona_pivoteo(float m[50][50],int n)
{
	int i,ii,j,a;
    float x,y;
	a=1;

	for(i=0+a;i<=n;i++){
        for (ii=2;ii<=n;ii++){
            if(m[i][i]<m[ii][i]){
                for (j=0; j<=n ; j++){
                    x=m[i][i+j];
                    m[i][i+j]=m[ii][i+j];
                    m[ii][i+j]=x;
                }
		   }
        }

    for (ii=1;ii<n;ii++){
         x = m[ii+a][a];
         y=  m[a][a];
         for (j=1;j<n+2;j++){
             m[ii+a][j]=m[ii+a][j]-(x/y)*m[a][j];
			}
		 }
	      a=a+1;
	}
	cout<<" LA MATRIZ ESCALONADA POR EL METODO DEL PIVOTEO ES : "<<endl;
	mostrar(m,n);
	cout<<" LAS RESPUESTAS SON : "<<endl;
	rep_(m,n);
}

int main(){
    float m[50][50];
    int i,j,n;

    // DIGITAR LA MATRIZ DE LAS ECUACIONES Y GUARDAR
	cout<<"        <<<<  Metodo de pivoteo  >>>>         ";
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";


	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<"\n M=["<<i<<","<<j<<"]= ";
			cin>>m[i][j];
		}
		cout<<"\n Termino independiente de X"<<i<<" ";
		cin>>m[i][n+1];
	}

    escalona_pivoteo(m,n);
    return 0;
}

