//metodo jacobi

#include <iostream>


void jacobi(int l, float x[], float a[][10], float b[], int n){
    float c[n]; //resultados
    int k, i, j, p;
    do //iteraciones en la matriz hasta hallar una proximacion
    {
        for(k=0; k<10; k++){
            for(i=0;i<l;i++){
                c[i]=b[i];
                for (j=0;j<l;j++){
                    if(i!=j)    
                        c[i]=c[i]-a[i][j]*x[j];
                }
            }
            for(i=0;i<n;i++) //resultado de las ecuaciones
                x[i]=c[i]/a[i][i];
        }
        std::cout<<"¿resultado: \n";
        for (i=0;i<l;i++){ //imprimir
            std::cout<<"x("<<i<<")= "<<x[i]<<"\n";
        }
        std::cout<<"¿quiere que el resultado sea mas preciso?\n(1)Si\n(0)No\n";
        std::cin>>p;
    } while (p!=0);

}

int main(){
    int i, j, l, cont=0, n=10;
    float x[n], a[n][n],b[n], dd, suma; //x = resultados, a=coeficientes, b=resultado de las ecuaciones
    std::cout<<"introduce el nuemero de ecuaciones:\n";
    std::cin>>l;
    std::cout<<"introduce la matriz con los coeficientes:\n";
    for(i=0;i<l;i++){ //llenar la matriz de coeficientes
        x[i]=0;
        for(j=0; j<l;j++){
            std::cout<<"a["<<i<<","<<j<<"]= ";
            std::cin>>a[i][j];
        }
    }
    std::cout<<"Introduce el vector de los resultados: \n";
    for(i=0;i<l;i++){ //lenar el resultado de las ecuaciones
        std::cout<<"b["<<i<<",0]= ";
        std::cin>>b[i];
    }
    for(i=0; i<l; i++){ ///para comprobar que la matriz es diagonalmente dominante
        suma=0;
        for(j=0; j<l; j++){
            if(i==j){//si esta en la diagonal
                dd=a[i][j];
            }else {
                suma+=a[i][j];
            }
        }
        if(dd>suma) cont++;
    }
    if(cont==l) jacobi(l,x,a,b,n);
    else std::cout<<"la matriz es incorrecta\n";
    return 0;
}