#Anagabriela Pilar Jiménez López        Álgebra lineal Grupo A
#Descomposición LU pero esta vez en python

#importamos bibliotecas
import numpy as np
from random import randint

#Ingresamos la matriz nxn que deseamos descomponer 
n = 3
A = np.array([[randint(1,10) for j in range(0, n)] for i in range(0,n)]).astype(np.float)#A es un ejemplo c:
print(A);print()

class ClaseLU:
    def __init__(self, matrix):
        self.row = len(matrix)
        self.matrix = matrix
    
    def Descomponer(self):
        #Generamos la matriz LU inicial
        row = self.row
        matrix = self.matrix
        U = np.identity(n = row, dtype = float) #Si establecemos todo en 0, ZeroDividionError da miedo :'D, así que lo convertimos en una matriz unitaria
        L = np.identity(n = row, dtype = float)
        #El algoritmo para la descomposición LU empieza aquí
        for k in range(0, row):
            for j in range(k, row):
                U[k][j] = matrix[k][j] - (sum(L[k][s] * U[s][j] for s in range(0, row) if s != k))
                if j == k:
                    w = 1 / U[k][k]
            for i in range(k + 1, row):
                L[i][k] =  w * (matrix[i][k] - sum(L[i][s] * U[s][k] for s in range(0, row) if s != k))
        return (L, U)

K = ClaseLU(A)
L, U = K.Descomponer()
print(L);print();print(U);print()
print(np.dot(L, U))