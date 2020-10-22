import numpy as np

'''
    El siguiente programa resuelve sistemas lineales de la forma Ax  = b
    con pivoteo de columnas. Adicionalmente se usa intercambio de filas y
    columnas para ello se presenta dos funciones adicionales.
'''

#Funcion para intercambio de filas
"""
M: La matriz
i,j: indices de fila que se intercambian
"""
def swapRows(M,i,j):
    if len(M.shape) == 1:
        M[i],M[j] = M[j],M[i]
    else:
        M[[i,j],:] = M[[j,i],:]

#Funcion para intercambio de columnas
"""
M: La matriz
i,j: indices de columna que se intercambian
"""
def swapCols(M,i,j):
    M[:,[i,j]] = M[:,[j,i]]


#Metodo Eliminacion Gaussiana con Pivoteo
def ElimGaussConPiv(A,b):
    n = len(b)
    s = np.zeros(n)

    #Hallar los factores de escala
    for i in range(n):
        s[i] = max(np.abs(A[i,:]))
    
    for k in range(0,n-1):
        p = np.argmax(np.abs(A[k:n,k])/s[k:n]) + k

        #Intercambio de filas si se requiere
        if p != k:
            swapRows(b,k,p)
            swapRows(s,k,p)
            swapRows(A,k,p)

        #Eliminacion
        for i in range(k+1,n):
            if A[i,k] != 0.0:
                lam = A[i,k]/A[k,k]
                A[i,k+1:n] = A[i,k+1:n] - lam*A[k,k+1:n]
                b[i] = b[i] - lam*b[k]
    
    #Sustitución Regresiva
    b[n-1] = b[n-1]/A[n-1,n-1]
    for k in range(n-2,-1,-1):
        b[k] = (b[k] - np.dot(A[k,k+1:n],b[k+1:n]))/A[k,k]
    return b



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

A = [[10., -1., 2., 0.],
     [-1., 11., -1., 3.],
     [2., -1., 10., -1.],
     [0.0, 3., -1., 8.]]
b = [6., 25., -11., 15.]

A = np.array(A)
b = np.array(b)
print(ElimGaussConPiv(A,b))