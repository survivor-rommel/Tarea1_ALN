#include<stdio.h>
#include<stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;


void ingresarMatriz_A_B(float **matrizA,float *b,int nFilCol){
  cout <<"\nEjemplo de como ingresar la matriz:"<<endl;
  cout <<"1 2 3"<<endl;
  cout <<"4 5 6"<<endl;
  cout <<"7 8 9"<<endl;
  cout <<endl;
  
  cout << "\nIngrese la matriz A: "<<endl;
  for (int i = 0; i < nFilCol; ++i)
  {
    matrizA[i] = new float[nFilCol];
    for (int j = 0; j < nFilCol; ++j)
    {
      cin>>matrizA[i][j];
    }
  }
  cout <<"\n\nIngrese la Matriz B\n"<<endl;
  for (int i = 0; i < nFilCol; ++i)
  {
    cin >> b[i];
  }
}


int main()
{
  int n,a,b,i,j,k;
  
  //LLenamos la matriz 
  cout << "METODO DE ELIMINACION DE GAUSSIANA"<<endl;
  cout << "Ingrese la dimension de la matriz cuadrada: ";
  cin >> n;
  float **ma= new float*[n]; //Matriz A
  float mb[n],cte,aux;//Matriz B
  ingresarMatriz_A_B(ma,mb,n); //LLeno las Matrices

  //Triangulo el sistema
  for(i=0;i<n;i++)
  {
      //Compruebo que el pivote sea diferente de 0
      if (ma[i][i]==0)
      {
         for(int s=i+1;s<=n+1;s++)
         {
           if (ma[s][i]!=0)
           {//Intercambio de filas
                        aux=ma[i][s-1];
                        ma[i][s-1]=ma[i+1][s-1];
                        ma[i+1][s-1]=aux;
                        
                        aux=mb[i];
                        mb[i]=mb[i+1];
                        mb[i+1]=aux;
           }      
         }
                        
      }
      for(j=i+1;j<n;j++)
      {
      cte=ma[j][i]/ma[i][i];
      for(k=i;k<n;k++)
         {
          ma[j][k]=ma[j][k]-cte*ma[i][k];
         }
         mb[j]=mb[j]-cte*mb[i];
      }
  }
  //Aplico Sustitucion regresiva
  float suma=0,x[10];

  cout << "SOLUCION DEL SISTEMA"<<endl<<endl;
  x[n-1]=mb[n-1]/ma[n-1][n-1];
  cout << "x["<<i<<"]"<< " = " <<x[n-1]<<endl;
  for(int z=n-2;z>=0;z--)
  {
      suma=0;
  	for(int y=z+1;y<n;y++)
  	{
  		suma=suma+ma[z][y]*x[y];
  	}
  	x[z]=(mb[z]-suma)/ma[z][z];
    cout << "x["<<z+1<<"]"<< " = " <<x[z]<<endl;
  }

  return 0;
}