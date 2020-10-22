import numpy as np


def modulo(x):
    if (x < 0):
        return (-x)
    return x


def criterio_convergencia(A):
    boo = True
    n = np.shape(A)[0]
    m = np.shape(A)[1]
    if (n != m):
        boo = False
        # no convergen
        return boo 

    for i in np.arange(n):
        sumai, sumaj = 0, 0
        for j in np.arange(n):
            if (i != j):
                lin = modulo(A[i, j])
                col = modulo(A[j, i])

                sumai += lin
                sumaj += col
        a = modulo(A[i, i])

        if ((a < sumai) or (a < sumaj)):
            boo = False

    return boo


def residuo(v1, v0):
    n = np.shape(v1)[0]
    num, den = 0, 0

    for i in np.arange(n):
        num += (v1[i]-v0[i])**2
        den += (v1[i])**2

    num = num**0.5
    den = den**0.5
    res = num/den

    return res


def jacobi(A, b, vectorSolucion, tolerancia):
    iteracion = 0

    boolean = criterio_convergencia(A)
    if (boolean == False):
        return (vectorSolucion, boolean, iteracion)

    vectorAuxiliar = np.copy(vectorSolucion)
    n = np.shape(A)[0]
    res = 1

    while (res > tolerancia):
        for i in np.arange(n):
            x = b[i]
            for j in np.arange(n):
                if (i != j):
                    x -= A[i, j]*vectorSolucion[j]
            x /= A[i, i]
            vectorAuxiliar[i] = x
        iteracion += 1

        res = residuo(vectorAuxiliar, vectorSolucion)
        vectorSolucion = np.copy(vectorAuxiliar)
        print('\n Vector solucion de la iteracion: ', iteracion, ' :\n', vectorSolucion)

    return (vectorSolucion, boolean, iteracion)
