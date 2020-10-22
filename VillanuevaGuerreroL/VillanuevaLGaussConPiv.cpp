#include<iostream>
#include<math.h>

using namespace std;
/*
M-->Matriz
n-->numero de ecuaciones
*/ 
void gaussConPivoteo(double M[100][100],int n)
{
    double temp,aux,acum,b[n];
    double may;//variable para almacenar el mayor de la columna k
    int ind;//indice del mayor-->indice de may
    
    //pivoteo parcial
    for(int i=0;i<n;i++){
        may=abs(M[i][i]);
        //recorrer la columna j para buscar el indice del mayor
            for(int j=i+1;j<n;j++){
                if(may<abs(M[j][i])){
                    may=abs(M[j][i]);
                    ind=j;
                }
            }
            
        //cambiar filas
        if(i!=ind){//asegurar que no se trata de la misma fila
            for(int k=0;k<n+1;k++){
                aux=M[i][k];
                M[i][k]=M[ind][k];
                M[ind][k]=aux;
            }
                
        }
    }

    //escalonamiendo de matriz (Row echelon form)
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n-1;j++)
        {
            temp= (M[j+1][i]/M[i][i]) ;

            for(int k=0;k<=n;k++)
                M[j+1][k]-=temp*M[i][k];
        }

    //Método de sustitución
    for(int i=n-1;i>=0;i--)
    {
        temp=0;
        for(int j=i;j<=n-1;j++)
            temp=temp+M[i][j]*b[j];

        b[i]=(M[i][n]-temp)/M[i][i];
    }

	//Mostrar resultado
    for(int i=0;i<n;i++)
        cout<<"X"<<i<<" = "<<b[i]<<endl;

}

int main()
{
    std::cout<<"========================================\n";
    std::cout<<"Metodo de Gauss con Pivoteo\n";
    std::cout<<"========================================\n";
    int n;
    std::cout<<"Ingrese numero de ecuaciones: ";
    std::cin>>n;
    double M[n][100];
    for(int i=0;i<n;i++)
    {
        std::cout<<"Fila "<<i+1<<":"<<std::endl;
        for(int j=0;j<=n;j++)
            std::cin>>M[i][j];
    }
    std::cout<<"========================================\n";
    std::cout<<"Resultado:\n";
    //double M[][100]={{1,1,1,6},{1,-1,1,2},{2,-1,3,7}};
    gaussConPivoteo(M,n);
}