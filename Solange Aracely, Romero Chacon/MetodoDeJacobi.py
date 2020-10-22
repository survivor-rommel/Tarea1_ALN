#Metodo de Jacobi

#Libreria para llenar de ceros mis matrices
import numpy as np
from numpy import array, zeros, diag, diagflat, dot

#Llenado de la matriz
n=int(input('Numero de Filas y Columnas:'))
#Matrices vacias
A = np.zeros((n,n))
b= np.zeros((n))
x= np.zeros((n))
a=np.zeros((n,n+1))
print ('Introducir los coeficientes de la matriz:')
#Llenado de la matriz
for f in range(0,n):
	for c in range(0,n):
		A[(f),(c)]=(input("Elemento A["+str(f+1)+","+str(c+1)+"]: "))
#Llenado del vector solucion
print ('Introducir el vector solucion:')
for v in range(0,n):
	b[(v)]=(input('b['+str(v+1)+']: '))
#Matriz aumentada
for k in range (0,n):
	for r in range(0,n+1):
		if (r==n):
			a[k,r]=b[k]
		else:
			a[k,r]=A[k,r]
print('Matriz aumentada:')
print(a)

#Implementacion del metodo
def jacobi(A,b,x,Nmax,Tol):                                                                                                                                              
    D = np.diag(np.diag(A))
    R = A - D 
    for i in range(Nmax):
        DInv = np.linalg.inv(D)
        temp = x
        x = np.dot(DInv, np.dot(-(R), x ) + b)
        if (np.linalg.norm(x - temp) < Tol):
            return x
    return x
#X0
print ('X0:')
for v in range(0,n):
	x[(v)]=(input('x['+str(v+1)+']: '))
#Nmax
Nmax=int(input('Nmax: '))
#Tolerancia
Tol=float(input('Tolerancia: '))
sol = jacobi(A,b,x,Nmax,Tol)
print ("Solucion:")
print(sol)