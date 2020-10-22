#include <iostream>
#include <cmath>
using namespace std;

double EPSILON = 0.00001; 

double x=0;
    double a=x;
double y=0;
    double b=y; 
double z=0;
    double c=z;

int rowA[]={2,-1,1,7}; 
int rowB[]={1,2,-1,6}; 
int rowC[]={1,1,1,12}; 

double anteriorX=-999999; 
double anteriorY=-999999; 
double anteriorZ=-999999; 

int times=0;

void gaussSeidel(){
    while(true){
        times++;
        if(times>2){
            x=(rowA[3]-(rowA[1]*anteriorY)-(rowA[2]*anteriorZ))/rowA[0];
            y=(rowB[3]-(rowB[0]*anteriorX)-(rowB[2]*anteriorZ))/rowB[1];
            z=(rowC[3]-(rowC[0]*anteriorX)-(rowC[1]*anteriorY))/rowC[2];
        }else{
            x=(rowA[3]-(rowA[1]*b)-(rowA[2]*c))/rowA[0];
            y=(rowB[3]-(rowB[0]*a)-(rowB[2]*c))/rowB[1];
            z=(rowC[3]-(rowC[0]*a)-(rowC[1]*b))/rowC[2];
        }
        a=x;
        b=y;
        c=z;

        if(abs((x-anteriorX)/x)<=EPSILON && abs((y-anteriorY)/y)<=EPSILON && abs((z-anteriorZ)/z)<=EPSILON){
            break;
        }
        anteriorX=x;
        anteriorY=y;
        anteriorZ=z;
    }
}

int main(){
    gaussSeidel();
    cout << "RAÍCES" << endl;
    cout << "x: "<< x << endl;
    cout << "y: " << y <<endl;
    cout << "z: " << z << endl;
    return 0;
}