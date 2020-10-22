#include<iostream>
#include<stdio.h>

int main(){
int i=0,j=0,k=0,n=0;

std::cout << "\t\tDESCOMPOSICION LU";
std::cout << std::endl;
std::cout << std::endl;
std::cout << "El orden de la matriz debe ser mayor o igual que 2 y entero." << std::endl;
std::cout << "Ingresa el orden de la matriz: ";
std::cin >> n;

if(n<=1){
    std::cout << std::endl;
    std::cout << "No ha ingresado un valor correcto. Cerrando el programa...";
    std::cout << std::endl;
    return 0;
} else {
    float A[n][n]={0}, B[n]={0}, X[n]={0}, L[n][n]={0}, Y[n]={0}, U[n][n]={0},sum=0;
    std::cout << "La matriz es de " << n << "x" << n <<".";
    std::cout << std::endl << std::endl;

    std::cout<<"Ingrese los coeficientes de la matriz A de coeficientes: ";
    std::cout << std::endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            std::cout << "Ingrese el elemento A["<<i+1<<"]["<<j+1<<"]: ";
            std::cin >> A[i][j];
        }
    }
    std::cout << std::endl;

    std::cout << "Ingrese la matriz B:" << std::endl;
    for(i=0;i<n;i++){
        std::cout << "Ingrese el elemento B["<<i+1<<"]: ";
        std::cin >> B[i];
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(i>j){
              U[i][j]=0;    
            }
            else if(i==j){
              L[i][j]=1;    
            } else{
              L[i][j]=0;    
            }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum=0;
            if(i<=j){               
                for(k=0;k<n;k++){
                    if(k!=i){
                        sum=sum+L[i][k]*U[k][j];
                    }else {
                        U[i][j]=A[i][j]-sum;               
                    }
                }
            } else{                 
                for(k=0;k<n;k++){
                    if(k!=j){
                        sum=sum+L[i][k]*U[k][j];
                    }else {
                        L[i][j]=(A[i][j]-sum)/U[j][j];      
                    }
                }
            }
        }
    }

        printf("\n\n L =");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)

                        printf ("%10.2f",L[i][j]);
            printf("\n    ");
    }

        printf("\n\n U =");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
                         printf ("%10.2f",U[i][j]);
            printf("\n    ");
    }

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
    printf("\n\n Y =");
    for(i=0;i<n;i++)
    {
                printf ("%10.2f",Y[i]);
            printf("\n    ");
    }

    X[n-1]=Y[n-1]/U[n-1][n-1];
    for(i=n-2;i>=0;i--){
        sum=0;
        for(j=n-1;j>i;j--)
            sum=sum+X[j]*U[i][j];
        X[i]=(Y[i]-sum)/U[i][i];
    }

    printf("\nLa solucion es :\n");
    for(i=0;i<n;i++)
        printf("\n x[%d] = %.2f ",i+1,X[i]);
    printf("\n\n");
}
}