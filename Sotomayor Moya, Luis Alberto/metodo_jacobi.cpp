#include<iostream>
#include<iomanip>

#define D 10

using namespace std;

int main(){
    char salir;
    int cantecuaciones, i, j, k, cantiteraciones;
    float coeficientes[D][D], terminosindependientes[D], valiniciales[100][D], suma, temp;
    cout<<setprecision(4);
    cout<<fixed;
    do{
        cout<<"Cantidad de ecuaciones: ";
        cin>>cantecuaciones;
        cout<<"Coeficientes de las variables (en orden dominante): "<<endl;
        for(i = 0; i < cantecuaciones; i++){
            for(j = 0; j < cantecuaciones; j++){
                cin>>coeficientes[i][j];
            }
        }
        cout<<"Terminos independientes"<<endl;
        for(i = 0; i < cantecuaciones; i++){
            cin>>terminosindependientes[i];
        }
        cout<<"Valores iniciales"<<endl;
        for(i = 0; i < cantecuaciones; i++){
            cin>>valiniciales[0][i];
        }
        cout<<"Cantidad de iteraciones: ";
        cin>>cantiteraciones;
        cout<<endl;
        k = 0;

        while(k <= cantiteraciones){
            for(i = 0; i < cantecuaciones; i++){
                suma = 0;
                for(j = 0; j < cantecuaciones; j++){
                    if(j != i)
                        suma += coeficientes[i][j]*valiniciales[k][j];
                }
                valiniciales[k+1][i]=(terminosindependientes[i]-suma)/coeficientes[i][i];
            }
            k++;
        }
        cout<<"Resultados"<<endl;
        for(k = 0; k < cantiteraciones; k++){
            for(i = 0; i < cantecuaciones; i++){
                cout<<setw(15)<<valiniciales[k][i];
            }
            cout<<endl;
        }
        cout<<"Presione 's' si desea salir: ";
        cin>>salir;
    }while(salir != 's');
}