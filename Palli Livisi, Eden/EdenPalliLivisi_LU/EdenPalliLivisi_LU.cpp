#include<iostream>
#include<conio.h>
using namespace std;
void metodoLU(){

}
void ingresarDatos(int n,float A[][10], float B[]){
    cout<<"Ingrese los coeficientes de la matriz A de coeficientes: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"A["<<i+1<<"]["<<j+1<<"]: ";
            cin>>A[i][j];
        }
    }
    cout<<"Ingrese la matriz B:"<<endl;
    for(int i=0;i<n;i++){
        cout<<" B["<<i+1<<"]: ";
        cin>>B[i];
    }    
}
int main(){
    int n=0;
    cout<<"\t\tDESCOMPOSICION LU";
    cout<<endl;
    cout<<endl;
    cout<<"- El orden de la matriz debe ser mayor que 2."<<endl;
    cout<<"Ingresa el orden de la matriz: ";
    cin >> n;
    //mayor que 1
    if(n<=1){
        cout<<endl;
        cout<<"No ha ingresado un valor correcto. Cerrando el programa...";
        cout<<endl;
    } else {
        float A[n][10]={0}, B[n]={0}, X[n]={0}, L[n][n]={0}, Y[n]={0}, U[n][n]={0};
        float sum = 0;
        //---
        ///ingresar datos
        ingresarDatos(n,A,B);
        //--- metodo LU

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(i>j){
                U[i][j]=0;
                }
                else if(i==j){
                L[i][j]=1;
                } else{
                L[i][j]=0;
                }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum=0;
                if(i<=j){
                    for(int k=0;k<n;k++){
                        if(k!=i){
                            sum=sum+L[i][k]*U[k][j];
                        }else {
                            U[i][j]=A[i][j]-sum;
                        }
                    }
                } else{
                    for(int k=0;k<n;k++){
                        if(k!=j){
                            sum=sum+L[i][k]*U[k][j];
                        }else {
                            L[i][j]=(A[i][j]-sum)/U[j][j];
                        }
                    }
                }
            }
        }
        //imprimir 
        printf("\n\n L =");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf ("%10.2f",L[i][j]);
                printf("\n    ");
        }
        printf("\n\n U =");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf ("%10.2f",U[i][j]);
                printf("\n    ");
        }

        Y[0]=B[0]/L[0][0];
        for(int i=1;i<n;i++)
        {
            sum=0;
            for(int j=0;j<i;j++)
            {
                sum=sum+Y[j]*L[i][j];

            }
            Y[i]=B[i]-sum;
        }
        printf("\n\n Y =");
        for(int i=0;i<n;i++)
        {
                    printf ("%10.2f",Y[i]);
                printf("\n    ");
        }

        X[n-1]=Y[n-1]/U[n-1][n-1];
        for(int i=n-2;i>=0;i--){
            sum=0;
            for(int j=n-1;j>i;j--)
                sum=sum+X[j]*U[i][j];
            X[i]=(Y[i]-sum)/U[i][i];
        }

        printf("\nLa solucion es :\n");
        for(int i=0;i<n;i++)
            printf("\n x[%d] = %.2f ",i+1,X[i]);
        printf("\n\n");
        getch();
        return 0;
        }
}