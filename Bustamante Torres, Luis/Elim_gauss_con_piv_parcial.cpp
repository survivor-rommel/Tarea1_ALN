//Eliminacion gaussiana con pivoteo parcial
#include<iostream>
#include<vector>
#include <cmath>
#include <iomanip>

using namespace std;

//Definicion de tipos
typedef vector<vector<float>> Matriz;
typedef vector<float> Vector;
typedef vector<float>::iterator Iterador; 

//Declaracion de las funciones
void mostrar(Matriz);
void mostrar_vector(Vector);
void ingresar_matriz(Matriz&, int n);
void ingresar_vector(Vector&, int n);


//Metodo para la sustitucion regresiva
Vector sust_regresiva(Matriz A,Vector b){
    int n=A.size();
    Vector X;
    X.resize(n);
    //se crea el vector con la division de los valores extremos 
    X[n-1]=b[n-1]/A[n-1][n-1];
    float s;

    //for para las filas
    for (int i = n-2; i >= 0; i--){
        s=0;
        //for para las columnas
        for (int j = n-1; j >= i+1; j--){
            //la suma y el factor por la fila
            s=s+ A[i][j]*X[j];
        }
        //Se pasa al vector 
        X[i]=(b[i]-s)/(A[i][i]);
    }
    return X;
}

//Metodo para la sustitucion progresiva con pivote
Matriz sust_progresiva_piv(Matriz A,int piv){
    int n=A.size();
    float m;
    //For para las filas
    for (int i = piv+1; i < n; i++){
        //Se halla el factor para multiplicar 
        m=-A[i][piv]/A[piv][piv];
        //For para las columnas
        for (int j = piv; j < A[0].size(); j++){
            //Se multiplica la fila pivote con el factor y se suma con la fila de iteracion 
            A[i][j]=A[i][j]+m*A[piv][j];
        }
    }
    return A;
}


//Para hallar el maximo de la columna
int maximo_colum(Matriz A,int colum){
    int n=A.size();
    float max=0;
    int ind;
    for (int i = 0; i < n; i++){
        if(abs(A[i][colum])>max){
            max=A[i][colum];
            ind=i;
        }
    }
    return ind;
}


//Eliminacion gaussiana con pivoteo parcial
Vector elim_gauss_piv(Matriz A, Vector b){
    Matriz Ab; //Matriz aumentada
    int n=A.size();  //Numero de filas
    Ab.resize(n); //Se actualiza el tamaño de la matriz aumentada

    //Para construir la matriz aumentada a partir de A y b
    for (int i = 0; i < n; i++){
        Ab[i]=A[i];
        Ab[i].resize(n+1);
        Ab[i][n]=b[i];
    }
    
    //Variables temporales
    Vector temp;
    int ind;

    //Pivoteo 
    for (int i = 0; i < n-1; i++){
        ind=maximo_colum(Ab,i); //Se busca el elemento maximo
        temp=Ab[i];  //Se guarda la fila en un temp
        Ab[i]=Ab[ind];  //Se intercambia de filas
        Ab[ind]=temp;  //Toma el valor de la variable temp
        Ab=sust_progresiva_piv(Ab,i); //Sustitucion progresiva con el Piv
    }

    //Para mostrar la matriz triangular superior
    cout<<"Matriz triangular superior"<<endl<<endl;
    mostrar(Ab);

    //Para crear las varibles que se pasaran al metodo de sustitucion regresiva
    Vector B;
    Matriz AA=Ab;
    B.resize(n);

    //Para la asigancion de las variables
    for (int i = 0; i < n; i++){
        B[i]=Ab[i][n];
        AA[i].erase(AA[i].end()-1);
    }

    Vector res;  //Vector de salida con la respuesta
    //Se llama al metodo de sustitucion regresiva
    res=sust_regresiva(AA,B);
    //Retorna la respuesta
    return res;
}


//Funcion main
int main(){
    Matriz A;
    Vector b;
    int n;
    cout<<"Ingrese la dimension "<<endl;
    cin>>n;
    ingresar_matriz(A,n);
    ingresar_vector(b,n);
    cout<<endl<<endl;
    mostrar_vector(elim_gauss_piv(A,b));
    return 0;
}



//
//Funciones para mostrar e ingresar los datos
//

//Funcion para mostrar una matriz
void mostrar(Matriz A){
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < A[0].size(); j++){
            cout<<setprecision(4)<<fixed<<A[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Funcion para mostrar un vector
void mostrar_vector(Vector A){
    cout<<"Respuesta"<<endl;
    for (int i = 0; i < A.size(); i++){
        cout<<setprecision(4)<<fixed<<A[i]<<"  ";
    }
    cout<<endl<<endl;
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