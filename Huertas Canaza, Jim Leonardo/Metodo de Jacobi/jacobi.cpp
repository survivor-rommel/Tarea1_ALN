#include <iostream>
using namespace std;

class Matriz{
private:
    float** matrix;
    float* constantes;
    float** variables;
    int iter;//Nro de Iteraciones
    int fil;
    int colum;
    

public:
    Matriz(int);
    ~Matriz();
    void llenar();
    void jacobi();
    void print_matrix();

};

Matriz::Matriz(int num){
    fil=num;
    colum=fil;
    matrix = new float *[fil];
    for(int i=0;i<fil;i++){
        matrix[i] = new float [fil];
    }
        
    
    constantes=new float[fil];



    cout<<"Para las variables"<<endl;
    for(int i=0; i<fil; i++){
        for(int j=0; j<fil; j++){
            cout<<"Matriz "<<i+1<<j+1<<": ";
            cin>>*(*(matrix+i)+j);
        }
    }

    cout<<"\n\nPara las Constantes"<<endl;
    for(int i=0; i<fil; i++){
        cout<<"Constante "<<i+1<<": ";cin>>*(constantes + i);
    }

    
    cout<<"\n\nNro de Iteraciones: ";cin>>iter;

    variables = new float *[iter+2];
    for(int i=0; i<iter+2; i++){
        variables[i] = new float [colum];
    }

    cout<<"\n\nValores iniciales"<<endl;
    for(int i=0; i<fil; i++){
        cout<<"X"<<i+1<<": ";
        cin>>variables[0][i];
    }
}

Matriz::~Matriz(){
}

void Matriz::jacobi(){
    int suma, aux=0;

    while (aux <= iter){
        cout<<"while"<<endl;
        for(int i=0; i<fil; i++){
            suma=0;
            for(int j=0; j<colum; j++){
                if(i != j){
                    suma += *(*(matrix + i)+ j) * variables[aux][j];
                }
            }
            variables[aux+1][i] = (*(constantes + i) - suma) / *(*(matrix + i) + i);
        }
        aux++;
    }
    
    cout<<endl;
    cout<<"Resultados"<<endl;
    for(int i=0; i<iter; i++){
        for(int j=0; j<fil; j++){
            cout<<"\t\t"<< *(*(variables + i) +j);
        }
            cout<<endl;
    }
}


void Matriz::print_matrix(){
    for(int i=0; i<fil; i++){
        for(int j=0; j<fil; j++){
            cout<<*(*(matrix + i)+ j)<<"  ";
        }
        cout<<endl;
    }
}


int main(){
    int tam;
    cout<<"Matriz (tamanio): ";cin>>tam;
    Matriz M(tam);

    M.print_matrix();
    M.jacobi();
    return 0;
}