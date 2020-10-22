//Metodo de jacobi

#include<iostream>  //Libreria para mostrar por pantalla
#include<vector>
#include <cmath>

using namespace std;    //Espacio de nombres para usar la libreria

//Definicion de tipos
typedef vector<vector<float>> Matriz;
typedef vector<float> Vector;
typedef vector<float>::iterator Iterador; 

//Funcion para multiplicar matrices de tamaño nx1 y 1xn
float mult_vectores(Vector A, Vector B){
    float res=0;
    for (int i = 0; i < A.size(); i++){
        res=res + A[i]*B[i];
    }
    return res;
}

//Funcion para restar 2 vectores y hallar la suma maxima de la columna
float norm_resta(Vector A, Vector B){
    float res;
    for (int i = 0; i < A.size(); i++){
        res= res + abs(A[i]-B[i]);
    }
    return res;
}

//Funcion para el metodo de Jacobi con los parametros y su salida
Vector jacobi(Matriz A, Vector b, Vector X0, int Nmax, int Tol){
    int n=A[0].size(); //Columnas de la matriz 
    float error = 1000;  //el error
    int itr = 1;  //para las iteraciones

    //Variables para el metodo
    Iterador it;  //Iterador para moverse por los datos
    Vector a;  //vector para guardar la fila de A
    Vector x;  //vector para guardar X0
    Vector X;  //Vector para el resultado
    X.resize(n); //Se asigna memoria para guardar el resultado

    //While para las iteraciones maximas y el error
    while (itr<=Nmax && error>Tol){
        //For para hallar X
        for (int i = 0; i < n; i++){
            a=A[i];  //Se copia la fila i
            it=a.begin(); //Se coloca el iterador al comienzo de a
            a.erase(it+i);  //Se borra el elemento que apunta el iterador (it+i)
            x=X0; //Se copia X0
            it=x.begin();  //Se coloca el iterador al comienzo de x
            x.erase(it+i);  //Se borra el elmento que apunta (it+i)
            X[i]=(b[i] - mult_vectores(a,x))/A[i][i];  //jacobi
        }
        error=norm_resta(X,X0); //se acutualiza el error
        X0=X;  //Se actualiza X0 con el resultado de la iteracion
        itr++;  //Se incrementa en 1 itr
    }
    //Al terminar las iteraciones retorna X
    return X;
}

//Funcion para ingresar una matriz
void ingresar_matriz(Matriz& M,int n){
    M.resize(n);
    for (int i = 0; i < n; i++){
        M[i].resize(n);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout<<"Ingresa la posicion ("<<i+1<< ") ("<<j+1<<")   ";
            cin>>M[i][j];
        }    
        cout<<endl;
    }
}

//Funcion para ingresar un vector
void ingresar_vector(Vector& V, int n){
    V.resize(n);
    for (int i = 0; i < n; i++){
        cout<<"Ingresa la posicion ("<<i+1<< ")   ";
        cin >> V[i];
    }
}

int main(){
    Matriz A;
    Vector b;
    Vector X0;
    int Nmax;
    float Tol;

    int n;
    cin >> n;
    ingresar_matriz(A,n);
    ingresar_vector(b,n);
    ingresar_vector(X0,n);
    cin>>Nmax;
    cin>>Tol;

    Vector res = jacobi(A, b, X0, Nmax, Tol);
    //Para imprimir el resultado
    for (int i = 0; i < n; i++){
        cout<<res[i]<<"  ";
    }
    return 0;
}