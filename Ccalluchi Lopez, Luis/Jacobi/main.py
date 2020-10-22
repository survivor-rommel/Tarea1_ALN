import numpy as np
import Jacobi as jc

A = np.matrix([[10, 2, 1],
               [1, 5, 1],
               [2, 3, 10]], dtype=float)

B = np.array([7, -8, 6], dtype=float)

total = 0.1

if __name__ == "__main__":
    
        Vector = np.zeros_like(B)
        print('\tMETODO JACOBI\n')

        V_jacobi, boolean, it = jc.jacobi(A, B, Vector, total)

        if (boolean == False):
            print(
                '\n ¡La matriz A no es diagonal dominante! \n\n A =\n {A}\n Nº iteraciones: {it}')
        else:
            print('\n Matriz A: \n ', A, '\n\n Vector B: ', B, '\n\n Vector de solución: ', V_jacobi, '\n\n ¿La matriz es diagonal dominante? ',
                  boolean, '\n\n Nº iteraciones:', it)

