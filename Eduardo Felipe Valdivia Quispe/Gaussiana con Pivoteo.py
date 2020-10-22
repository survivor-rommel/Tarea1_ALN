import numpy as np


n=int(input('Numero de Filas y Columnas:'))



A = np.zeros((n,n))
b= np.zeros((n))
x=np.zeros((n))
a=np.zeros((n,n+1))



print ('Introducir los coeficientes de la matriz:')



for f in range(0,n):
	for c in range(0,n):
		A[(f),(c)]=(input("Elemento A["+str(f+1)+","+str(c+1)+"]: "))


print ('Introducir el vector solucion:')
for v in range(0,n):
	b[(v)]=(input('b['+str(v+1)+']: '))



for k in range (0,n):
	for r in range(0,n+1):
		if (r==n):
			a[k,r]=b[k]
		else:
			a[k,r]=A[k,r]
print('Matriz aumentada:')
print(a)

for i in range (n-1):
    b[i]=b[i]/A[i][i]
    A[i]=A[i]/A[i][i]
    for k in range(i+1,n):
        b[k]=b[k]-A[k][i]*b[i]
        A[k]=A[k]-A[k][i]*A[i]

i=n-1
b[i]=b[i]/A[i][i]
A[i]=A[i]/A[i][i]


for i in reversed(range(n)):
    suma=np.sum(A[i][i+1:]*x[i+1:])
    x[i]=b[i]-suma

print(x)