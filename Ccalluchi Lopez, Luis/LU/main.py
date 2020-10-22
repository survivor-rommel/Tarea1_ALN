import numpy as np
import Descomposicion_LU as lu

A = np.matrix([[1, -4, 6, -4], [0, 1, -4, 5],
               [5, -4, 1, 0], [-4, 6, -4, 1]], dtype=float)

if __name__ == "__main__":
    decimales = 3
    L, U = lu.descomposicionLU(A)

    lu.redondeado(L, decimales)
    lu.redondeado(U, decimales)

    print("\tDescomposicion LU\n \tMatriz L\n", L,"\n\tMatriz U\n", U, "\t\nMatriz A\n", A)
