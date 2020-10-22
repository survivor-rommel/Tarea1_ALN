import numpy as np
"""m = int(input("Valor de m:"))
n = int(input("Valor de n:"))
A = np.zeros((m,n))
b = np.zeros((n))

print("Introduce la matriz de coeficientes y el vector solución")
for r in range(0,m):#r = raw c = column
    for c in range(0,n):
        A[(r),(c)]=(input("Elemento a["+str(r+1)+","+str(c+1)+"] "))
    b[(r)]=(input("b["+str(r+1)+"]: "))
print(A)"""##llenar a conveniencia

def jacobi(A,b,x0,eps=1e-10,Nmax=500):
    D = np.diag(np.diag(A))
    LU = A - D # L + U
    x = x0
    for i in range(Nmax):
        D_inv = np.linalg.inv(D)
        xTemp = x
        x = np.dot(D_inv, np.dot(-(LU), x ) + b)
        if np.linalg.norm(x - xTemp) < eps:
            return x
    return x
A = np.array([
    [5, 2, 1, 1],
    [2, 6, 2, 1],
    [1, 2, 7, 1],
    [1, 1, 2, 8]
])

b = np.array([29, 31, 26, 19])

x0=np.random.rand(4)
x=jacobi(A,b,0)
print("x",x)
print("b calculado: ", np.dot(A,x))
print("b verdadero ",b)
print("solucion de numpy: ", np.linalg.solve(A,b))
 