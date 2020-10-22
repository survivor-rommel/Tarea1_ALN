#Descomposicion LU
# funcion que efectua factorizacion LU para matrices cuadradas
import numpy as np

def lu_desc(matriz):
    A = np.array(matriz)
    epsilon = np.finfo(np.float).eps
    dim = A.shape
    L = np.zeros(dim)
    U = np.zeros(dim)
    for j in range(dim[0]):
        if abs(A[j, j]) < epsilon:
            print('ERROR: pivote nulo')
            return None
        L[j, j] = 1.0
        for i in range(j + 1, dim[0]):
            L[i, j] = A[i, j] / A[j, j]
            for k in range(j + 1, dim[0]):
                A[i, k] = A[i, k] - L[i, j] * A[j, k]
        for k in range(j, dim[0]):
            U[j, k] = A[j, k]

    return L, U


A = [[1.0,2.0,-1.0],[2.0,1.0,-2.0],[-3.0,1.0,1.0]]
L, U = lu_desc(A)

print('L = ')
print(L)
print('U = ')
print(U)