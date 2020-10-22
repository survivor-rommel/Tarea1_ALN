//PROFESOR ALGUNAS INDICACIONES PARA QUE EL PROGRAMA FUNCIONE:
// el archivo jacobi.txt dentro de la carpeta Jacobi es necesario para leer la matriz
//
//Los aproximaciones de debe ingresar en una sola linea y separado por espacios
//		Ejemplo: 1 1 1

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
T Suma(T **matriz, int fila, T *aprox, int n){
    T suma=0;
    for(int j=0; j<n; j++){
        if(fila!=j){
            suma=suma + matriz[fila][j]*aprox[j];
        }
    }
    return suma;
}

template <typename T>
void Jacobi(){
int fi=3, col=4;

    //int matriz[fi][col];
    T **matriz=new T *[fi]; //puntero que apunta a un array de punteros
    for(int i=0; i<fi;i++)
        matriz[i]=new T[col];

    ifstream f;
    f.open("C:jacobi.txt");

    for(int i=0; i<fi; i++)
        for(int j=0; j<col; j++)
            f>>matriz[i][j];
    f.close();

    cout<<"Matriz ingresada por fichero:"<<endl<<endl;
    cout<<"     variables      | resultados"<<endl;
    for(int i=0; i<fi; i++){
        for(int j=0; j<col; j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    T *result=new T[fi];
    for(int i=0; i<fi; i++)
        result[i]=matriz[i][col-1];

    //JACOBI
    T *aprox=new T[fi];
    cout<<"\nIngresa aproximaciones: ";
    for(int i=0; i<fi; i++)
        cin>>aprox[i];

    int n=fi; //n la dimension de la matriz cuadrada
    int iteraciones;
    cout<<"\nCuantas iteraciones quiere?: "; cin>>iteraciones;
    cout<<endl;
    for(int k=0; k<iteraciones; k++){
        for(int i=0; i<n; i++){
            aprox[i]=(result[i]-Suma(matriz,i,aprox,n))/matriz[i][i];
            cout<<aprox[i]<<"     ";
        }
        cout<<endl;
    }

    cout<<"\nLa aproximacion de los valores despues de "<<iteraciones<<" iteraciones es: "<<endl;
    for(int i=0; i<n; i++)
        cout<<aprox[i]<<" ";
    cout<<endl;

    for(int i=0;i<fi;i++){
        delete [] matriz[i];
    }
    delete [] matriz;
}

int main(){
   Jacobi<float>();
}
