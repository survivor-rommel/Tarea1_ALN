include<iostream>
using namespace std;

void Jacobi(int l, float x[], float a [][10], float b[]);

int main()
{
    int i,j,l,cont = 0;
    float x[n], a[n][n], b[n], dd, suma;
    cout<<"Numero de ecuaciones:";
    cin>>l;
    cout<<"Matriz con los coeficientes:"<<endl;
    for (i=0; i<l; i++)
    {
        x[i]= 0;
        for (j=0; j<l ; j++)
        {
            cout<<"a["<<i<<" , "<<j<<"]=";
            cin>>a[i][j];
        }
    }
    cout<<"Introducir el Vector de los resultados:"<<endl;
    for (i=0; i<l ;i++ )
    {
        cout<<"b["<<i<<",0]=";
        cin>>b[i];
    }
    for (i=0 ; i<l; i++)
    {
        suma=0;
        for ( j=0; j<l; j++)
        {
            if(i == j)
            {
                dd=a[i][j];
            }
            else{
                suma += a[i][j];
            }
        }
        if(dd>suma)
        {
            cont++;
        }
    }
    if (cont == 1)
    {
        Jacobi(l,x,a,b);
    }
    else
    {
        cout<<"Error"<<endl;
    }
    return 0;
}

void Jacobi(int l, float x[], float a [][10], float b[])
{
    char p;
    float c[n];
    int k,i,j;
    //line:
    for (k=0; k<10 ;k++)
    {
        for (i=0;i<1;i++)
        {
            c[i] = b[i];
            for (j=0 ; j<1; j++)
            {
                if (i != j)
                {
                    c[i] = c[i] -a[i][j]*x[j];
                }
            }
        }
        for (i=0; i<n;i++)
        {
            x[i]= c[i]/a[i][i];
        }
    }
    cout<<"La solucion es:"<<endl;
    for (i=0; i<1; i++)
    {
        cout<<"x("<<i<<")="<<x[i]<<endl;
    }

}