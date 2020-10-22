/*-----------------------------------------------------------------
|  Programa realizacdo en DEV C++ 4.9 
|  Obtenido de: http://openboxer.260mb.com/pamn.html
|  Descripción: Programa que utiliza el método de descomposición LU
|  para la solución de sistemas de ecuaciones.
|-------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
 
int main()
{
	int i,j,k,n;
	float a[MAX][MAX],b[MAX],x[MAX],l[MAX][MAX],y[MAX],u[MAX][MAX],sum;

	printf ("\nIngresa el numero de incognitas: ");
        scanf("%d",&n);
        
        printf ("\nIngrese los coeficientes:\n\n");
	for(i=0;i<n;i++)
        {
		for(j=0;j<=n;j++)
		{
			if(j<n)
			{
				printf("a[%d][%d] = ",i,j);
				scanf("%f",&a[i][j]);
				
			}
			else 
			{
				printf("b[%d] = ",i);
				scanf("%f",&b[i]);
				printf("\n");
			}
		}
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i>j) 
			{
			  u[i][j]=0;
			}
			else if(i==j) 
			{
			  l[i][j]=1;
			}
			else 
			{
			  l[i][j]=0;
			}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			if(i<=j)
			{
				for(k=0;k<n;k++) 
					if(k!=i)
						sum=sum+l[i][k]*u[k][j];
				        u[i][j]=a[i][j]-sum;
			}
			else 
			{
				for(k=0;k<n;k++)
					if(k!=j)
						sum=sum+l[i][k]*u[k][j];
					l[i][j]=(a[i][j]-sum)/u[j][j];
			}
		}
	}

        printf("\n\n L =");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
                          
                        printf ("%10.2f",l[i][j]);
 			printf("\n    ");
	}
    
        printf("\n\n U =");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
                         printf ("%10.2f",u[i][j]);
 			printf("\n    ");
	}

	y[0]=b[0]/l[0][0];
	for(i=1;i<n;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
		{
			sum=sum+y[j]*l[i][j];
			
		}
		y[i]=b[i]-sum;
	}
	printf("\n\n Y =");
	for(i=0;i<n;i++)
	{
                printf ("%10.2f",y[i]);
 			printf("\n    ");
	}

	x[n-1]=y[n-1]/u[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		sum=0;
		for(j=n-1;j>i;j--)
			sum=sum+x[j]*u[i][j];
		x[i]=(y[i]-sum)/u[i][i];

	}

	printf("\nLa solucion es :\n");
	for(i=0;i<n;i++)
  		printf("\n x[%d] = %.2f ",i+1,x[i]);
	printf("\n\n");

system("pause");
}
