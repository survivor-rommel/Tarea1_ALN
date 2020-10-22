#include<iostream>
#include<cmath>
#include<iomanip>

/*
M-->matriz aumentada modificada en la funcion convergencia(matriz diagonalmente dominante)
n-->numero de ecuaciones
*/ 
bool convergencia(double M[100][100],int n)
{
    int cont=0;
    float suma, temp;
    for(int i=0; i<n; i++){
        suma=0;
        for(int j=0; j<n; j++){
            if(i==j){
                temp=M[i][j];
            }
            else{
                suma+=M[i][j];
            }
        }
        if(temp>suma)
            return true;
    }
    return false;
}

/*
M-->matriz 
n-->numero de ecuaciones
tol-->tolerancia para encontrar la solucion
maxiter-->maximo de iteracciones
*/ 
void jacobi(double M[100][100],int n,double tol,int maxiter){
    double error=1000;
    double acum=0;
    int iter=0;//número de iteraciones
    double V[n];//guarda iteraccion actual
    double VA[n];//guarda la iteracion anterior
    while(error>tol && iter<maxiter){
        iter++;
        //recorre diagonal de matriz
        for(int i=0;i<n;i++){
            acum=M[i][n];
            //recorre filas de la matriz 
            for(int j=0;j<n;j++){
                if(i!=j){
                    acum=acum-VA[j]*M[i][j];
                }
            }
            V[i]=acum/M[i][i];
           //imprimir iteraciones//std::cout<<"X"<<i<<"="<<V[i]<<"\t\t\t";
        }
        //std::cout<<std::endl;
        
        //actualizar error
        acum=0;
        for(int i=0;i<n;i++){
            error=V[i]-VA[i];
            acum=acum+pow(error,2);
        }
        error=sqrt(acum);
        
        //almacena la iteracion actual
        for(int i=0;i<n;i++){
            VA[i]=V[i];
        }
    }

    //mostrar resultado
    for(int i=0;i<n;i++){
        std::cout<<"X"<<i<<" = "<<V[i]<<std::endl;
    }
} 

int main () {
    std::cout<<"========================================\n";
    std::cout<<"Metodo de Jacobi\n";
    std::cout<<"========================================\n";
    int n,maxiter,tol;
    std::cout<<"Ingrese numero de ecuaciones: ";
    std::cin>>n;
    double M[n][100];
    for(int i=0;i<n;i++)
    {
        std::cout<<"Fila "<<i+1<<":"<<std::endl;
        for(int j=0;j<=n;j++)
            std::cin>>M[i][j];
    }
    std::cout<<"Ingrese tolerancia: ";
    std::cin>>tol;
    std::cout<<"========================================\n";
    std::cout<<"Resultado:\n";
    
    //solo si hay convergencia se puede realizar el método de jacobi
    if(convergencia(M,n))
        jacobi(M,n,tol,50); //50 es el numero maximo de iteraciones, puede ser cambiado
    else
    {
        std::cout<<"La matriz no es estrictamente diagonal dominante";
    }
    
}