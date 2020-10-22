#include<iostream>
#include<conio.h>
#define n 10 /// longitud del numero
using namespace std;

void Jacobi(int l, float x[], float a[][10], float b[]){
    char p;
    float c[n];
    line:
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < l; i++)
        {
            c[i] = b[i];
            for (int j = 0; j < l; j++)
            {
                if(i!=j){
                    c[i] = c[i] - a[i][j] * x[j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            x[i] = c[i] / a[i][i];
        }
    }
    cout<<"\n-----------------------------------------"<<endl;
    cout<<"La solucion es: "<<endl;
    for (int i = 0; i < l; i++)
    {
        cout<<"x("<<i<<") = "<<x[i]<<endl;
    }
    cout<<"Solucion mas exacta: "<<endl<<"Precione : Si(s) / No (n)"<<endl;
    cin>>p;
    switch (p)
    {
    case 's' : goto line;
        break;
    case 'n' : cout<<"Proceso Finalizado."<<endl;
        break;
    return;
    }
}
void VierificarSIesDominante(int l, float a[][10], float x[], float b[]){
    float suma,dd;
    int cont = 0;
    for (int i = 0; i < l; i++)
    {
        suma = 0;
        for (int j = 0; j < l; j++)
        {
            if(i==j){
                dd = a[i][j];
            }
            else
            {
                suma+=a[i][j];
            }
        }
        if(dd>suma){
            cont++;
        }
    }
    if(cont==l){
        Jacobi(l, x, a, b);
    }else
    {
        cout<<"La matriz no es diagonalmente dominante. proceso finalizado"<<endl;
    }
}
void ingresarDatos(int l, float b[], float x[], float a[][10]){
    //--------INGRESAR NUMEROS------
    cout<<"\n-----------------------------------------"<<endl;
    cout<<"Ingrese la matriz de los coheficientes: "<<endl;
    for(int i=0;i<l;i++){
        x[i] = 0;
        for (int j=0 ; j < l ; j++)
        {
            cout<<"a["<<i<<","<<j<<"] = ";
            cin>>a[i][j];
        }    
    }
    //----INGRESAR RESULTADOS----
    cout<<"\nINTRODUCE LOS RESULTADOS: "<<endl;
    for (int i = 0; i < l; i++)
    {
        cout<<"b["<<i<<",0] = ";
        cin>>b[i];
    }
}

int main(){
    int l;

    float x[n];//incognitas
    float a[n][n];//cohefientes
    float b[n];//para los resultados

    cout<<"\t\tMETODO DE JACOBI " <<endl;
    cout<<"\n1)La matriz debe de tener igual numero de incognitas y ecuaciones."<<endl;
    cout<<"2)La matriz sea diagonalmente dominante."<<endl;
    cout<<"3)El numero de equaciones debe ser mayor que 2"<<endl;
    //--------INGRESAR DATOS------
    cout<<"\nINGRESE EL NUMERO DE ECUACIONES : ";
    cin>>l;
    if (l<=1){
        cout<<endl;
        cout<<"No ha ingresado un valor correcto. Cerrando el programa...";
        cout<<endl;
    }else{
        ingresarDatos(l,b,x,a);
        VierificarSIesDominante(l,a,x,b);
    }

    getch();
    return 0;
}