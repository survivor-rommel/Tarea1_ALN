import numpy as np

'''
    Este programa corresponde al método númerico iterativo de Jacobi.
    Resuelve sistemas lineales de la forma Ax = b, para ello se le pasa
    como argumentos la Matriz A (coeficientes), el vector b(resultados)
    y devuelve un arreglo con las las soluciones del sistema.

    Adicionalmente se le pasa un número máximo de iteraciones (Nmax) asi
    como un un valor de Tolerancia al error (Tol), los cuales tienen valores por defecto
    en el caso que no se le pase como parámetro 
'''


#Método de Jacobi para resolver Ax = b
"""
Entrada: A, matriz de coeficiente
         b, arreglo de los resultados
         x0, arreglo de condición inicial
         Nmax, numero de iteraciones (Valor por defecto = 1000)
         Tol, tolerancia al error del sistema (Valor por defecto = 1e-10)
Salida:  x, arreglo con las soluciones del sistema lineal
"""

def jacobi(A, b, Nmax  = 1000, Tol=1e-10):

    #inicializando el arreglo de soluciones
    x = np.zeros_like(b)

    for it_count in range(Nmax):
        x_new = np.zeros_like(x)

        for i in range(A.shape[0]):
            s1 = np.dot(A[i, :i], x[:i])
            s2 = np.dot(A[i, i+1:], x[i+1:])
            x_new[i] = (b[i] - s1 - s2)/A[i,i]
        if np.allclose(x, x_new, atol = Tol, rtol=0.):
            break
        x = x_new
    return x

A = [[10., -1., 2., 0.],
     [-1., 11., -1., 3.],
     [2., -1., 10., -1.],
     [0.0, 3., -1., 8.]]
b = [6., 25., -11., 15.]


# Caso de prueba
# Indicaciones de uso en el archivo README.md
'''
    El sistema es de la forma:
    
    10x - y + 2z = 6
    -x + 11y - z + 3w = 25
    2x -y + 10z - w = -11
    3y - z + 8w = 15

    Cuya solución es:
    x = 1
    y = 2
    z = -1
    w = 1
'''
A = np.array(A)
b = np.array(b)
x = jacobi(A,b)
error  = np.dot(A,x) - b
print(x)
print(error)