#include "iostream"
#include "math.h"
#include "stdlib.h"
using namespace std;

int main(){
    float a, b, c, d, e, f, g, h, i, x1, x2, x3, rpta1, rpta2, rpta3, t1, t2, t3;
    int contador = 0;
    cout << "\tINGRESE EL SISTEMA DE ECUACIONES CON LA DIAGONAL ESTRICTAMENTE DOMINANTE" << endl;
    cout << "Ingrese los coeficientes (1a) : "; cin >> a >> b >> c;
    cout << "Ingrese la respuesta de la 1a ecuacion : "; cin >> rpta1;
    cout << "Ingrese los coeficientes (2a) : "; cin >> d >> e >> f;
    cout << "Ingrese la respuesta de la 2a ecuacion : "; cin >> rpta2;
    cout << "Ingrese los coeficientes (3a) : "; cin >> g >> h >> i;
    cout << "Ingrese la respuesta de la 3a ecuacion : "; cin >> rpta3;

    //Cambio de  signo///////////////
    if (b > 0|| c > 0 || d > 0 || f > 0 || g > 0 || h > 0)
    {
        b = -1 * b;
        c = -1 * c;
        d = -1 * d;
        f = -1 * f;
        g = -1 * g;
        h = -1 * h;
    }
    else
    {
        b = -1 * b;
        c = -1 * c;
        d = -1 * d;
        f = -1 * f;
        g = -1 * g;
        h = -1 * h;
    }
    //Operaciones////////////////
    do
    {
        t1 = (rpta1 + (b*x2) + (c*x3))/a;
        t2 = (rpta2 + (d*x1) + (f*x3))/e;
        t3 = (rpta3 + (g*x1) + (h*x2))/i;
        
        x2 = t2;
        x1 = t1;
        x3 = t3;
        contador++;
        cout << t1 << " , " << t2 << " , " << t3 << " | " << contador <<  endl;
    } while (contador <= 4);

    system("pause");
    return 0;
}