#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
bool convergencia(double M[100][100],int n){
    double may;
    int ind;
    bool band=true;
    double aux;
    double acum;

    for(int k=0;k<n;k++){
        may=abs(M[k][k]);
        for(int l=k+1;l<n;l++){
            if(may<abs(M[l][k])){
                may=abs(M[l][k]);
                ind=l;
            }

        }
        if(k!=ind){
            for(int i=0;i<n+1;i++){
                aux=M[k][i];
                M[k][i]=M[ind][i];
                M[ind][i]=aux;
            }

        }
        acum=0;
        for(int j=0;j<n;j++){
            if(k!=j){
                acum=acum+abs(M[k][j]);
            }
        }
        if(acum>abs(M[k][k])){
            break;
        }


}
    return band;
}

int jacobi(double M[100][100],double V[100],int n,double tol){
    double error=0;
    double acum=0;
    double VA[100];
    int iter=0;
    do{
        iter++;

        for(int k=0;k<n;k++){
            acum=M[k][n];

            for(int j=0;j<n;j++){
                if(k!=j){
                    acum=acum-VA[j]*M[k][j];
                }

            }
            V[k]=acum/M[k][k];

        }
        acum=0;
        for(int i=0;i<n;i++){
            error=V[i]-VA[i];
            acum=acum+pow(error,2);
        }
        error=sqrt(acum);

        for(int i=0;i<n;i++){
            VA[i]=V[i];
        }
    }while(error>tol);
    return iter;
}
int main (int argc, char *argv[]) {
    double M[100][100];
    int n;
    bool band;
    double V[100];
    double tol;
    cout<<"ingrese el numero de ecuaciones:";
    cin>>n;
    cout<<"ingrese elementos de la matriz aumentada:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"fila "<<i+1<<":"<<endl;
        for(int j=0;j<n+1;j++){
            cout<<"\tcolumna "<<j+1<<":"<<endl;
            cin>>M[i][j];
        }
    }
    cout<<"matriz aumentada:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cout<<M[i][j]<<"\t";
        }cout<<endl;
    }
    band=convergencia(M,n);
    if(band){

        cout<<"se garantiza la convergencia"<<endl;
        cout<<"matriz diagonalmente dominante:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++){
                cout<<M[i][j]<<"\t";
            }cout<<endl;
        }
        if(band){
            cout<<"ingrese tolerancia: ";
            cin>>tol;


            cout<<"-->iteraciones: "<<jacobi(M,V,n,tol)<<endl;
            cout<<"la solucion es:"<<endl;
            for(int i=0;i<n;i++){
                cout<<"-->X"<<i+1<<"="<<setprecision(30)<<V[i]<<endl;
            }
        }
    }
    else
        cout<<"no se garantiza convergencia-->la matriz no es diagonalmente dominante"<<endl;
    return 0; }
