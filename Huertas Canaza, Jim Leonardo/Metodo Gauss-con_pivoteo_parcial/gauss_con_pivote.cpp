#include<iostream>
#include<cmath>
using namespace std;

void triangularizacion(double M[20][20],int n){
    
    double may;
    int ind;
    double aux;
    double pivote;
    
    for(int k=0;k<n-1;k++){

        may=abs(M[k][k]);
        ind=k;
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
        if(M[k][k]==0){
            cout<<"no tiene solucion";
            break;
        }
        else{
            
            for(int i=k+1;i<n;i++){
                pivote=-M[i][k];
                for(int j=k;j<n+1;j++){
                    M[i][j]=M[i][j]+pivote*M[k][j]/M[k][k];
                }
                
            }
        }
   
    }
}

void vector_solucion(double V[20],double M[20][20],int n){
    
    double acum;
    for(int i=n-1;i>=0;i--){
        acum=0;
        for(int j=n-1;j>=0;j--){
            if(j>i){
                acum+=M[i][j]*V[j];
            }
        }
        V[i]=(M[i][n]-acum)/M[i][i];
    }
}

void ingresar_coeficientes(double M[20][20],int n){
    cout<<"ingrese ecuaciones:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t"<<"fila "<<i+1<<" : "<<endl;
        for(int j=0;j<n+1;j++){
            cin>>M[i][j];
        }
    }
}

int main (int argc, char *argv[]) {
    int n;
    double M[20][20];
    double V[20];
    cout<<"ingrese numero de ecuaciones:";
    cin>>n;
    ingresar_coeficientes(M,n);
    cout<<"matriz aumentada:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cout<<M[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"triangularizacion:"<<endl;
    triangularizacion(M,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cout<<M[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"la solucion del sistema de ecuaciones es:"<<endl;
    vector_solucion(V,M,n);
    for(int i=0;i<n;i++){
        cout<<"X"<<i+1<<"="<<V[i]<<"\t";
    }
    
    return 0;
}
