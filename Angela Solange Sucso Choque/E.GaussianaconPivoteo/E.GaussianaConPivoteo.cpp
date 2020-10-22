//PROFESOR ALGUNAS INDICACIONES PARA QUE EL PROGRAMA FUNCIONE:
// el archivo GaussianaConPivoteo.txt dentro de la carpeta E.GaussianaconPivoteo es necesario para leer la matriz

#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
void mostrarMatriz(T **matriz, int fi,int col){
    for(int i=0; i<fi; i++){
        for(int j=0; j<col; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        cout<<endl;
    }
}

template <typename T>
void MatrizPorFichero(T **&matriz,int fi,int col){
    //int matriz[fi][col];
    matriz=new T *[fi]; //puntero que apunta a un array de punteros
    for(int i=0; i<fi;i++)
        matriz[i]=new T[col];

    ifstream f;
    f.open("C:GaussianaConPivoteo.txt");
    for(int i=0; i<fi; i++)
        for(int j=0; j<col; j++)
            f>>matriz[i][j];
    f.close();
}

template <typename T>
void pivoteo(T** &matriz1, int col, int pos1, int pos2){
    T aux;
    for(int i=0; i<col; i++){
        aux = matriz1[pos1][i];
        matriz1[pos1][i]=matriz1[pos2][i];
        matriz1[pos2][i]=aux;
    }
}

template <typename T>
void EliminacionHaciaAdelante(){
    int fi=3, col=4;
    T **matriz1;
    MatrizPorFichero(matriz1,fi,col);
    
    cout<<"\nMatriz ingresada por fichero: "<<endl;
    mostrarMatriz(matriz1,fi,col);
    cout<<endl;

    // para cada elemento de la diagonal
    for(int i=0;i<fi-1;i++){
        T mayor = matriz1[i][i];
        int posMayor = i;
        //busca al mayor de la columna para el pivoteo
        for(int j=i+1;j<fi;j++){
            if (matriz1[j][i] > mayor){
                mayor = matriz1[j][i];
                posMayor = j;
            }
        }
        if (posMayor != i){
            pivoteo(matriz1, col, i, posMayor);
            cout<<"\nPivoteo Parcial: "<<endl;
			mostrarMatriz(matriz1,fi,col);
        }

        // convierte a ceros la parte inferior
        for(int j=i+1;j<fi;j++){
            float fraccion=(matriz1[j][j-1]/matriz1[i][i]);
            if(matriz1[j][i]!=0){
                for(int k=i; k<col; k++){
                    matriz1[j][k]=matriz1[j][k]-(fraccion*matriz1[i][k]);
                }
            }
        }
    }
 
    cout<<endl;
    cout<<"Eliminacion Hacia Adelante: "<<endl;
    mostrarMatriz(matriz1,fi,col);
	cout<<endl;

    T *X = new T[fi];
    int aux=0;
    for(int i=fi-1; i>=0; i--){
    	T acum=0;
        for(int j=col-2; j!=i; j--){
            acum = acum + matriz1[i][j]*X[aux];
            aux++;
        }
        X[aux]=(matriz1[i][col-1]-acum)/matriz1[i][i];
    	acum=0;
    	aux=0;
    }
    
    cout<<"Sustitucion Hacia Atras "<<endl;
    cout<<"Soluciones: "<<endl;
    for(int i=fi-1; i>=0; i--){
        cout<<X[i]<<"  ";
    }
    
    
}

int main(){
    EliminacionHaciaAdelante<float>();
    return 0;
}
