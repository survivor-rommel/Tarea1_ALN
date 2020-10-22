#include<iostream>
#define n 10
using namespace std;

void Jacobi(int l, float vectorX[] , float matriz[][10] , float vectorB[]);

int main()
{
	int i , j , l , contador = 0;
	float vectorX[n] , matriz[n][n] , vectorB[n], dd , suma;
	cout <<"Introduzca el numero de ecuaciones \n";
	cin>>l;
	cout<<"Introduce el numero de coeficientes\n"<<endl;
	for(i = 0 ; i < l ; i++)
	{
		vectorX[i] = 0;
		for(j = 0 ; j < l ; j++)
		{
			cout<<"Matriz["<<i<<" , "<<j<<"] = ";
			cin>>matriz[i][j];
		}
	}
	cout<<"Introduzca el vector de resultados\n";
	
	for(int i = 0 ; i < l ; i++)
	{
		cout<<"B["<<i<<",0] = ";
		cin>>vectorB[i];
	}
	
	for(i = 0 ; i < l ; i++)
	{
		suma = 0;
		for(j = 0 ; j < l ; j++)
		{
			if(i == j)
			{
				dd = matriz[i][j];
			}
			else
			{
				suma+=matriz[i][j];
			}
		}
		if(dd > suma)
		{
			contador++;
		}
	}
	if(contador  == l)
	{
		Jacobi(l , vectorX , matriz , vectorB);
	}
	else
	{
		cout<<" EL proceso finalizo , matriz no es diagnonalmente dominante \n";	
	}
	
	
	
	return 0;	
}

void Jacobi(int l, float vectorX[] , float matriz[][10] , float vectorB[])
{
	char p;
	float vectorC[n];
	int k , i , j;
	line:
	for(k = 0 ; k < 10 ; k++)
	{
		for(i = 0 ; i < l ; i++)
		{
			vectorC[i] = vectorB[i];
			for(j = 0 ; j < l ; j++)
			{
				if(i!=j)
				{
					vectorC[i] = vectorC[i]-matriz[i][j] * vectorX[j];
				}
			}
		}
		
		for(i = 0 ; i < n ; i++)
		{
			vectorX[i] = vectorC[i]/matriz[i][i];
		}
			
	}
	
	cout<<"La solucion es : "<<endl;
	for(i = 0 ; i < l ; i++)
	{
		cout<<"vectorX("<<i<<")  = "<<vectorX[i]<<endl;	
	}	 
	cout<<"Requiere que el resultado tenga mas precision ? "<<endl;
	cout<<"(S) SI"<<endl;
	cout<<"(N) NO"<<endl;
	cin>>p;
	switch(p)
	{
		case 'S' : goto line ; break;
		case 'N' : cout<<"Proceso ha finalizado\n"; break;
	}
}
