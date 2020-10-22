#include<iostream>
#include<cmath>
using namespace std;

void triangularizacion(double M[20][20], int cantecuaciones){
    
    int indice;
    double aux, mayor, pivote;
    
    for(int k = 0; k < cantecuaciones-1; k++){//recorrer columnas de la matriz reducida

        mayor = abs(M[k][k]);
        indice = k;
        for(int l = k+1; l < cantecuaciones; l++){
            if(mayor < abs(M[l][k])){
                mayor = abs(M[l][k]);
                indice = l;
            }
           
        }
        
        //cambio de filas
        if(k != indice){
            for(int i = 0; i < cantecuaciones+1; i++){
                aux = M[k][i];
                M[k][i] = M[indice][i];
                M[indice][i] = aux;
            }
        
        }
        
        //triangularizacion normal         
        if(M[k][k] == 0){
            cout<<"No tiene solucion!";
            break;
        }
        else{
            for(int i = k+1; i < cantecuaciones; i++){
                pivote = -M[i][k];
                for(int j = k; j < cantecuaciones+1; j++){//recorrer elementos de una fila
                    M[i][j] = M[i][j]+pivote*M[k][j]/M[k][k];
                }
                
            }
        }
   
    }
}

void vector_solucion(double V[20],double M[20][20],int cantecuaciones){
    
    double acum;
    //Recorre matriz
    for(int i = cantecuaciones-1; i >= 0; i--){
        acum = 0;
        for(int j = cantecuaciones-1; j >= 0; j--){
            if(j > i){
                acum += M[i][j]*V[j];
            }
        }
        V[i] = (M[i][cantecuaciones]-acum)/M[i][i];
    }
}

void insertar_coeficientes(double M[20][20],int cantecuaciones){
    cout<<"Ingrese ecuaciones:"<<endl;
    for(int i = 0; i < cantecuaciones; i++){
        cout<<"\t"<<"fila "<<i+1<<" : "<<endl;
        for(int j = 0; j < cantecuaciones+1; j++){
            cin>>M[i][j];
        }
    }
}
int main() {
    int cantecuaciones;
    double M[20][20];
    double V[20];
    cout<<"Ingrese cantidad de ecuaciones:";
    cin>>cantecuaciones;
    insertar_coeficientes(M,cantecuaciones);
    cout<<"Matriz aumentada:"<<endl;
    for(int i=0;i<cantecuaciones;i++){
        for(int j=0;j<cantecuaciones+1;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Triangularizacion:"<<endl;
    triangularizacion(M,cantecuaciones);
    for(int i=0;i<cantecuaciones;i++){
        for(int j=0;j<cantecuaciones+1;j++){
            cout<<M[i][j]<<"\t";
        }cout<<endl;
    }
    cout<<"Solución:"<<endl;
    vector_solucion(V,M,cantecuaciones);
    for(int i=0;i<cantecuaciones;i++){
        cout<<"X"<<i+1<<"="<<V[i]<<"\t";
    }
    
    return 0;
}
