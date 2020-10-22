import numpy as np


def descomposicionLU(A):
    boo = matrizQuadrada(A)

    if boo:
        U = np.copy(A)  # Copiar elementos de A a U
        n = np.shape(U)[0]  # Recibe el número de líneas
        # Crea una matriz con 1 en la diagonal principal y cero en los otros puntos
        L = np.eye(n)

        for j in np.arange(n-1):
            for i in np.arange(j+1, n):
                # divida el elemento debajo del pivote por el pivote y agregue L
                #  simulando aquí un inverso de una matriz de combinación de líneas
                if U[j, j] == 0:
                    # para identificar matrices singulares al final
                    boo = False
                L[i, j] = U[i, j]/U[j, j]
                for k in np.arange(j+1, n):
                    # multiplica U por los valores de L previamente encontrados
                    U[i, k] = U[i, k] - L[i, j]*U[j, k]
                U[i, j] = 0  # agrega 0 a todos los elementos debajo del pivote en U

        if not boo:
            L = np.zeros(1)
            U = np.eye(1)
        return(L, U)


def matrizQuadrada(A):
    n = np.shape(A)[0]  # Recibe el numero de líneas
    m = np.shape(A)[1]  # Recibe el numero de columnas
    if n != m:
        return False
    return True

def redondeado(A, x):

    n = np.shape(A)
    aux = len(n)

    n = np.shape(A)[0]

    if aux == 1:
        for i in np.arange(n):
            A[i] = round(A[i], x)
    else:
        m = np.shape(A)[1]
        for i in np.arange(n):
            for j in np.arange(m):
                # redondea cada valor a 1  decimal
                A[i, j] = round(A[i, j], x)
