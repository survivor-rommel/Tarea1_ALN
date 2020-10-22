//gauss con pivoteo parcial 

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>


int main(){
    int n,i,j,k,temp;
    float a[10][10],c,d[10]={0};

    std::cout<<"introduce el nuemero de ecuaciones:\n";
    std::cin>>n;
    std::cout<<"introduce la matriz con los coeficientes: \n";
    for(i=0;i<n;i++){ //llenar la matriz de coeficientes
        for(j=0; j<=n;j++){
            if(j==n){
                std::cout<<"resultado de la ecuacion= ";
                std::cin>>a[i][j];
            }
            else{
                std::cout<<"a["<<i<<","<<j<<"]= ";
                std::cin>>a[i][j];
            }
        }
    }

    for(i=n-1;i>0;i--){// pivoteo parcial	
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++){
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }

    for(i=0;i<n;i++){//mostrar la matriz
        for(j=0;j<=n;j++)
            std::cout<<a[i][j]<<"\t";
        std::cout<<"\n";
    }
    
    //Cambiando a matriz triangular superior
    //eliminacion desde atras 
    for(k=0;k<n-1;k++)
        for(i=k;i<n-1;i++)
        {
            c= (a[i+1][k]/a[k][k]) ;

            for(j=0;j<=n;j++)
                a[i+1][j]-=c*a[k][j];
        }

     // mostrando matriz
    std::cout<<"\n\n";
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++)
            std::cout<<a[i][j]<<"\t";
        std::cout<<"\n";
	}
	

    for(i=n-1;i>=0;i--){//Sustitucion hacia atras 
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];

        d[i]=(a[i][n]-c)/a[i][i];
    }

    std::cout<<"\nResultado\n";
    //mostrar    
    for(i=0;i<n;i++)
    std::cout<<d[i]<<"\t";

    return 0;
    
}